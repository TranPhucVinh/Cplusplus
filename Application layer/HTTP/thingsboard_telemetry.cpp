#include <iostream>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define DEBUG
#define HOST          "demo.thingsboard.io"
#define PORT          80
#define TOKEN         "nX6blKRMdInsacwbg583"
#define BUFFSIZE      500

char        response_buffer[BUFFSIZE];
int         send_number = 0;

using namespace std;

string form_http_request(string data);

int         socket_connect(const char *host, int port);
void        telemetry();

int main() {
    telemetry();
    return 0;
}

int socket_connect(const char *host, int port) {
	int socket_fd;

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *response;
    int err = getaddrinfo(host, NULL, &hints, &response);
    if(err != 0 || response == NULL) {
		printf("DNS lookup failed err=%d res=%p\n", err, response);
		exit(1);
	}

    struct sockaddr *addr;
    addr = response->ai_addr;
    ((struct sockaddr_in *)addr)->sin_port = htons(port);

	socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
	if(socket_fd == -1){
		perror("socket_fd");
		exit(1);
	}
	
	if(connect(socket_fd, addr, sizeof(struct sockaddr_in)) == -1){
		perror("connect");
		exit(1);
	}

	return socket_fd;
}

string form_http_request(string data){
	string http_request;

    http_request = string("POST /api/v1/") + TOKEN + string("/telemetry HTTP/1.1\r\nHost: "); 
    http_request += HOST + string("\r\nContent-Type: application/json");
    http_request += "\r\nContent-Length: " + std::to_string(data.size()) + "\r\n\r\n" + data + "\r\n";
	return http_request;
}

void telemetry() {
	int client_fd;
    string send_json;

    while (1){
        // As socket_connect(HOST, PORT) is inside while(1) loop, when Internet gets disconnected
        // program stops immediatetly
        client_fd = socket_connect(HOST, PORT);
        
        send_json = "{'unix_tcp_client':" + to_string(send_number) + "}";
        
        string http_request = form_http_request(send_json);

        #ifdef DEBUG    
            cout << http_request << endl;
        #endif
        int wsz = write(client_fd, http_request.c_str(), http_request.size());//wsz: write size
        
        #ifdef DEBUG    
            while(read(client_fd, response_buffer, BUFFSIZE - 1) != 0){
                cout << response_buffer << endl;
                // bzero(response_buffer, BUFFSIZE);
                break;
            }
        #endif

        if (wsz == http_request.size()) send_number += 1;
        else cout << "Fail to send HTTP request\n" << endl;
        sleep(1);
    }
    shutdown(client_fd, SHUT_RDWR); 
    close(client_fd);
}