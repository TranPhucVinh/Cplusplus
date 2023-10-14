#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>//bcopy()
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define DEBUG   
#define HOST          "ec2-18-142-177-27.ap-southeast-1.compute.amazonaws.com"
#define PORT          9090
#define TOKEN         "47DF5DqQgOvw2J9jSlKK"
#define BUFFSIZE      500

int         send_number = 0;
int 		telemetry_is_suspended = 0;

std::string form_http_request(std::string data);
int         socket_connect(char *host, in_port_t port);
void        monitor_internet_status();
void        telemetry();

class Thread{
	public:
		Thread(void func_handler()){
			_thread = std::thread(func_handler);
		}
		void run_thread(){
			_thread.join();
		}
        void resume_thread(Thread &thread_obj)
        { 
            std::unique_lock<std::mutex> resumeThreadLock(thread_obj.suspend_mutex);
            thread_obj.resume_condition.notify_one();
        }
        void suspend_thread(Thread &thread_obj)
        { 
            std::unique_lock<std::mutex> suspendThreadLock(thread_obj.suspend_mutex);
            thread_obj.resume_condition.wait(suspendThreadLock);
        }
	private:
		std::thread                 _thread;
        std::mutex                  suspend_mutex;
        std::condition_variable 	resume_condition;
};

Thread monitor_thread(monitor_internet_status), telemetry_thread(telemetry);

int main()
{
	monitor_thread.run_thread();
    telemetry_thread.run_thread();
    return 0;
}

int socket_connect(const char *host, in_port_t port){
	struct hostent *hp;
	struct sockaddr_in addr;
	int sock;     

	if((hp = gethostbyname(host)) == NULL){
		herror("gethostbyname");
		return -1;
	}
	bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(sock == -1){
		perror("Socket connect: ");
		return -1;
	}
	
	if(connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1){
		perror("Socket connect:");
		return -1;
	}
	return sock;
}

std::string form_http_request(std::string data){
	static std::string http_request;

    http_request = std::string("POST /api/v1/") + TOKEN + std::string("/telemetry HTTP/1.1\r\nHost: ") + HOST + std::string("\r\nContent-Type: application/json");
    http_request += std::string("\r\nContent-Length: ") + std::to_string(data.size()) + std::string("\r\n\r\n") + data + std::string("\r\n");

	return http_request;
}

void monitor_internet_status(){
	while (1){
        struct hostent *hostinfo;
        hostinfo = gethostbyname(HOST);

        if (hostinfo == NULL) {
			std::cout << "No Internet connection, telemetry_thread is suspended\n";
			std::cout << "send_number is " << send_number << std::endl;
			telemetry_is_suspended = 1;

			monitor_thread.suspend_thread(telemetry_thread);
		}
        else {
			if (telemetry_is_suspended == 1){
				std::cout << "Internet has recovered\n";
				monitor_thread.resume_thread(telemetry_thread);
				std::cout << "telemetry_thread is resumed\n";
				telemetry_is_suspended == 0;
			}
		}
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void telemetry(){
	int 		client_fd;
    std::string send_json;
    char 		response_buffer[BUFFSIZE];

    while (1){
		client_fd = socket_connect(HOST, PORT);
		if (client_fd > -1){
			send_json = "{'unix_tcp_client':" + std::to_string(send_number) + "}";
			
			std::string http_request = form_http_request(send_json);

			#ifdef DEBUG  
				std::cout << http_request << std::endl;
			#endif

			int wsz = write(client_fd, http_request.c_str(), http_request.size());//wsz: write size
			
			#ifdef DEBUG    
				if (wsz == http_request.size()) {
					std::cout << "Send HTTP request for ThingsBoard telemetry successfully with size " << wsz << std::endl;
					send_number += 1;
				}
				else std::cout << "Fail to send HTTP request\n";

				while(read(client_fd, response_buffer, BUFFSIZE - 1) != 0){
					std::cout << response_buffer << std::endl;
					bzero(response_buffer, BUFFSIZE);
					break;
				}
			#endif
		} else {
			std::cout << "Can't connect to " << HOST << std::endl;
		}	
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    shutdown(client_fd, SHUT_RDWR); 
    close(client_fd);
}