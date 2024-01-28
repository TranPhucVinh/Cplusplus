#include <stdio.h>      
#include <sys/socket.h> /* for socket(), connect()*/
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <errno.h>

#define RECEIVER_IP "127.0.0.1"
#define PORT        8000
#define BUFFSIZE    256

class TCP_Sender {	
	public:
        int  _sender_fd;
        char _buffer[BUFFSIZE];

        TCP_Sender(const char *rx_ip, int port);
        ~TCP_Sender();
		void write_to_tcp_receiver();
    private:
        void error(const char *msg);
};

int main(){
    TCP_Sender tcp_sender(RECEIVER_IP, PORT);

    while(1){
        tcp_sender.write_to_tcp_receiver();
    }
    
    return 0;
}

TCP_Sender::TCP_Sender(const char *rx_ip, int port){
    struct sockaddr_in _receiver_addr;
    _receiver_addr.sin_family      = PF_INET;
    _receiver_addr.sin_addr.s_addr = inet_addr(rx_ip);          
    _receiver_addr.sin_port        = htons(port);

    // Create TCP socket
    if ((_sender_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        printf("Fail to create socket\n");
        exit(0);
    } else printf("Create TCP socket successfully\n");

    // Connect to server
    if (connect(_sender_fd, (struct sockaddr *)&_receiver_addr, sizeof(_receiver_addr)) < 0){
        if (errno == ECONNREFUSED) {
            printf("TCP server hasn't been started or server doesn't support connection\n");
        } else printf("Can't connect to TCP server with error %d", errno);
        exit(0);
    } else {
        // Check if TCP receiver has reached maximum connections
        int bytes_received = read(_sender_fd, _buffer, BUFFSIZE);
        if (bytes_received > 0) {
            if (!strcmp(_buffer, "Y")) {
                printf("Reject connection as TCP receiver has reached maximum connection\n");
                exit(0);
            } else {
                printf("connect to TCP server successfully\n");
                bzero(_buffer, BUFFSIZE);         //Delete buffer
            }
        } 
    }
}

TCP_Sender::~TCP_Sender(){
    close(_sender_fd); //Close socket
}

void TCP_Sender::write_to_tcp_receiver(){
    printf("message: ");
    bzero(_buffer, BUFFSIZE);
    fgets(_buffer, BUFFSIZE, stdin);

    write(_sender_fd, _buffer, BUFFSIZE);
}

void TCP_Sender::error(const char *msg){
    perror(msg);
    exit(0);
}
