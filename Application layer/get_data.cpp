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

class HTTP_Client {
	public:
		char ip_str[30]; 
		HTTP_Client(const char *host, in_port_t port);	
		std::string form_http_request(std::string str);
		int write_http_request(std::string http_request);
		char *read_http_response();
	private:
		int _http_client_fd;
};

int main(int argc, char *argv[]){
    while (1){
        HTTP_Client http_client(HOST, PORT); 
        
        std::string http_request = http_client.form_http_request(PATH);
        std::cout << http_request << std::endl;

		http_client.write_http_request(http_request);

		char* recv_buf = http_client.read_http_response(); 
        std::string recv_str(recv_buf);
		std::cout << recv_str << std::endl;
		delete recv_buf;

        sleep(1);
    }
	return 0;
}

HTTP_Client::HTTP_Client(const char *host, in_port_t port){
	struct hostent *hp;
	struct sockaddr_in addr;   

	if((hp = gethostbyname(host)) == NULL){
        std::cout << "Fail to get host " << host << std::endl;
		return;
	}
	bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	_http_client_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(_http_client_fd == -1){
		perror("setsockopt");
		exit(1);
	}
	
	if(connect(_http_client_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1){
		perror("connect");
		exit(1);
	}
}

std::string HTTP_Client::form_http_request(std::string str){
	std::string path = str;
	static std::string http_request;

    http_request = std::string("GET ") + path + std::string(" HTTP/1.0\r\nHost: ");
	http_request += HOST + std::string("\r\nConnection: close\r\n\r\n");

	return http_request;
}

int HTTP_Client::write_http_request(std::string http_request){
	if (write(_http_client_fd, http_request.c_str(), http_request.size()) < 0){
	    close(_http_client_fd);
	    return 0;
	}
	return 1;
}

/* Read HTTP response */
char *HTTP_Client::read_http_response(){
	char* recv_buf = NULL;
	int index = 0;
	int read_size_chunk = 0;
	recv_buf = new char[1024];
	while(1)
	{
		read_size_chunk = read(_http_client_fd, &recv_buf[index += read_size_chunk], 1024);
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

	shutdown(_http_client_fd, SHUT_RDWR); 
	close(_http_client_fd);
	return recv_buf;
}
