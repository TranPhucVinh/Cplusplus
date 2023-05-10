#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>// bcopy()
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

char        response_buffer[BUFFSIZE];
int         send_number = 0;

std::string form_http_request(std::string data);

int         socket_connect(char *host, in_port_t port);
void        telemetry();

int main()
{
    telemetry();
    return 0;
}

int socket_connect(const char *host, in_port_t port){
	struct hostent *hp;
	struct sockaddr_in addr;
	int sock_fd;     

	if((hp = gethostbyname(host)) == NULL){
		herror("gethostbyname");
		exit(1);
	}
	bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	sock_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(sock_fd == -1){
		perror("setsockopt");
		exit(1);
	}
	
	if(connect(sock_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1){
        std::cout << "Fail to connect to " << host << std::endl;
		exit(1);
	}
	return sock_fd;
}

std::string form_http_request(std::string data){
	static std::string http_request;

    http_request = std::string("POST /api/v1/") + TOKEN + std::string("/telemetry HTTP/1.1\r\nHost: ") + HOST + std::string("\r\nContent-Type: application/json");
    http_request += "\r\nContent-Length: " + std::to_string(data.size()) + "\r\n\r\n" + data + "\r\n";
	return http_request;
}

void telemetry(){
	int client_fd;
    std::string send_json;
    
    client_fd = socket_connect(HOST, PORT);

    while (1){
        send_json = "{'unix_tcp_client':" + std::to_string(send_number) + "}";
        
        std::string http_request = form_http_request(send_json);

        #ifdef DEBUG    
            std::cout << http_request << std::endl;
        #endif
        int wsz = write(client_fd, http_request.c_str(), http_request.size());//wsz: write size
        
        #ifdef DEBUG    
            while(read(client_fd, response_buffer, BUFFSIZE - 1) != 0){
                std::cout << response_buffer << std::endl;
                bzero(response_buffer, BUFFSIZE);
                break;
            }
        #endif

        if (wsz == http_request.size()) send_number += 1;
        else std::cout << "Fail to send HTTP request\n" << std::endl;
        sleep(1);
    }
    shutdown(client_fd, SHUT_RDWR); 
    close(client_fd);
}