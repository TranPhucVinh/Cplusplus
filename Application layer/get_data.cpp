#include <iostream>
#include <stdio.h>      // perror()
#include <string.h>
#include <stdlib.h>
#include <unistd.h>     // write(), read() and close()
#include <sys/socket.h> // socket() and connect()
#include <netdb.h>
#include <errno.h>

#define HOST "example.com"
#define PORT 80
#define PATH "/"

std::string form_http_request();

int socket_connect(const char *host, in_port_t port){
	struct hostent *hp;
	struct sockaddr_in addr;
	int sock;     

	if((hp = gethostbyname(host)) == NULL){
        std::cout << "Fail to get host " << HOST << std::endl;
		return -1;
	}
	bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(sock == -1){
		perror("setsockopt");
		exit(1);
	}
	
	if(connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1){
		perror("connect");
		exit(1);
	}

	return sock;
}

int main(int argc, char *argv[]){
	int fd;

    while (1){
        fd = socket_connect(HOST, PORT); 
        std::string http_request = form_http_request();
        std::cout << http_request << std::endl;

        if (write(fd, http_request.c_str(), http_request.size()) < 0){
            close(fd);
            return 0;
        }

        /* Read HTTP response */
        char* recv_buf = NULL;
        int index = 0;
        int read_size_chunk = 0;
        recv_buf = (char*)malloc(1024);
        while(1)
        {
            read_size_chunk = read(fd, &recv_buf[index += read_size_chunk], 1024);
            if(read_size_chunk > 0)
            {
                recv_buf = (char*) realloc(recv_buf, index + read_size_chunk + 1024);
            }
            else
            {
                recv_buf = (char*) realloc(recv_buf, index + 1);
                recv_buf[index] = 0;
                break;
            }
        }
        std::string recv_str(recv_buf);
        std::cout << recv_str << std::endl;

        shutdown(fd, SHUT_RDWR); 
        close(fd); 
        
        sleep(1);
    }
	return 0;
}

std::string form_http_request(){
	static std::string http_request;

    http_request += "GET ";
    http_request += PATH;
    http_request += " HTTP/1.0\r\nHost: ";
	http_request += HOST;
	http_request += "\r\nConnection: close\r\n\r\n";

	return http_request;
}