#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netdb.h>

#include <math.h>

#define SERVER  "localhost"
#define PORT    8000

#define URL		"/rx_from_client"

char *form_http_request(const char *url, char *data);

int socket_connect(const char *host, in_port_t port){
	struct hostent *hp;
	struct sockaddr_in addr;
	int socket_fd;     

	if((hp = gethostbyname(host)) == NULL){
		herror("gethostbyname");
		exit(1);
	}
	bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	socket_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(socket_fd == -1){
		perror("socket_fd");
		exit(1);
	}
	
	if(connect(socket_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1){
		perror("connect");
		exit(1);
	}
	return socket_fd;
}

int main(){
	int fd;
	double sine_value; 
    char send_string[50];
    int x = 0; // radian value of sin(x)

	while(1){
		fd = socket_connect(SERVER, PORT); 
		sine_value = sin(x);
       
		sprintf(send_string, "%lf", sine_value);
        char *http_request = form_http_request(URL, send_string);

        if (write(fd, http_request, strlen(http_request)) < 0){
            close(fd);
            return 0;
        }
		
		shutdown(fd, SHUT_RDWR); 
		close(fd); 
		usleep(20000);

        x += 1;
	}
	
	return 0;
}

char *form_http_request(const char *url, char *data){
    char string_length[10];
	static char http_request[500];

    sprintf(string_length, "%ld", strlen(data));
    strcpy(http_request, "POST ");
	strcat(http_request, url);
    strcat(http_request, " HTTP/1.1\r\nHost:");
    strcat(http_request, SERVER);
    strcat(http_request, "\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: ");
    strcat(http_request, string_length);
    strcat(http_request, "\r\n\r\n");
    strcat(http_request, data);
    strcat(http_request, "\r\n");
    return http_request;
}