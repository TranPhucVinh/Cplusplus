#include <iostream>          
#include <sys/socket.h>     /* for socket(), connect()*/
#include <stdlib.h>         /* for atoi() and exit() */
#include <string.h>         /* for memset() */
#include <unistd.h>         /* for close() */
#include <fcntl.h>          /* for open() */
#include <sys/types.h> 
#include <netinet/in.h>
#include <arpa/inet.h>      /* for inet_ntop() */
#include <thread>

#include <vector>
#include <algorithm> // find()

using namespace std;

#define REUSEADDR		true
#define MAXPENDING 		5
#define BUFFSIZE 		256
#define PORT 			8000

#define MAX_CONNECTIONS 3   // Max number of TCP senders accepted to connect to this TCP receiver

class TCP_Sender {	
	public:
		char ip_str[30]; 
		int _sender_fd;
};

class TCP_Receiver {
	public:
		TCP_Receiver(int port, bool reuse_address, int max_pending, int max_connections);
		bool 				is_new_tcp_sender_connected();
        bool                reached_max_connections(); // Check wheter MAX_CONNECTIONS number of TCP sender have connected 
        void                register_connection_to_handler();
	private:
        int                 _total_connected_sndr_fd;// Total connected TCP sender fd
        int                 _max_connections;
		int 				_receiver_fd;
		int 				_sender_fd;//fd of the connected TCP sender
		vector<int>         _sender_fd_list;
		struct 		        sockaddr_in _sender_addr;
        void				read_tcp_sender_msg(unique_ptr<TCP_Sender> tcp_sender, int req_buf_sz);
};

int main(){ 
	TCP_Receiver http_server(PORT, REUSEADDR, MAXPENDING, MAX_CONNECTIONS);
   	cout << "Waiting for a TCP sender to connect ...\n";
    while (1){
		if (http_server.is_new_tcp_sender_connected()){
            if (http_server.reached_max_connections()){
               cout << "Maximum number of " << MAX_CONNECTIONS << " connected TCP senders " << " have been reached. Reject new connection\n";
            } else {
			    http_server.register_connection_to_handler();
            }


		}
	}
}

TCP_Receiver::TCP_Receiver(int port, bool reuse_address, int max_pending, int max_connections){
	struct 	sockaddr_in _receiver_addr;

    _total_connected_sndr_fd = 0;    
    _max_connections = max_connections;

    // Create TCP socket receiver
	_receiver_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (_receiver_fd  < 0){
        perror("_receiver_fd \n");
    } else cout << "Create TCP receiver socket successfully\n";
 
    _receiver_addr.sin_family = AF_INET;                
    _receiver_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    _receiver_addr.sin_port = htons(port);      

    // setsockopt() must be called before bind() so that SO_REUSEADDR can take effect
   	if (reuse_address){
		int enable_val = 1;
        if (!setsockopt(_receiver_fd , SOL_SOCKET, SO_REUSEADDR, &enable_val, sizeof(enable_val))){
            cout << "Set socket to reuse address successfully\n";
        } else cout << "Unable to set socket to reuse address\n";
	}

    //Bind to the local address
    if (bind(_receiver_fd , (struct sockaddr *) &_receiver_addr, sizeof(_receiver_addr)) < 0) {
        cout << "Fail to bind socket to local address with errno \n" << errno << endl;
        exit(0);
    }
    else cout << "Start TCP socket receiver successfully through binding\n";

    //Set up connection mode for socket sender
    if (listen(_receiver_fd , max_pending) < 0) exit(0);
}

/*
	Check if a new TCP sender has connected
	Return true if there is a new connection, false if there isn't
*/
bool TCP_Receiver::is_new_tcp_sender_connected(){
	socklen_t _sender_length;
	_sender_length = sizeof(_sender_addr);//Get address size of sender
	_sender_fd = accept(_receiver_fd , (struct sockaddr *) &_sender_addr, &_sender_length);
	if (_sender_fd > 0) {
        _total_connected_sndr_fd += 1;
        return true;
    }
	else return false;
}

/*
    Check wheter MAX_CONNECTIONS number of TCP sender have connected 
*/
bool TCP_Receiver::reached_max_connections(){
    if (_total_connected_sndr_fd <= _max_connections) {
        write(_sender_fd, "N", sizeof("N"));
        return false;
    }
    else {
        write(_sender_fd, "Y", sizeof("Y"));
        close(_sender_fd);
        _total_connected_sndr_fd -= 1;// Reset _total_connected_sndr_fd to its previous value
        return true;
    }
}

void TCP_Receiver::register_connection_to_handler() {
    char ip_str[30];
	inet_ntop(AF_INET, &(_sender_addr.sin_addr.s_addr), ip_str, INET_ADDRSTRLEN);
	_sender_fd_list.push_back(_sender_fd);
	cout << "New TCP sender with fd " << _sender_fd;
	cout << " connected with IP " << ip_str;
	cout << "; " << _sender_fd_list.size() << " TCP senders have connected now\n";

	unique_ptr<TCP_Sender> tcp_sender = make_unique<TCP_Sender>();

	tcp_sender->_sender_fd = _sender_fd;
	strcpy(tcp_sender->ip_str, ip_str);

	thread tcp_sender_thread(&TCP_Receiver::read_tcp_sender_msg, this, move(tcp_sender), BUFFSIZE);
	tcp_sender_thread.detach();
}

/*
	req_buf_sz: Request buffer size	
*/
void TCP_Receiver::read_tcp_sender_msg(unique_ptr<TCP_Sender> tcp_sender, int req_buf_sz){
	int _sender_fd;
	char req_buf[req_buf_sz];// Buffer for HTTP request from HTTP client
	bzero(req_buf, req_buf_sz);//Delete buffer

	_sender_fd = tcp_sender->_sender_fd;
	while(1){
		int bytes_received = read(_sender_fd, req_buf, req_buf_sz);
        if (bytes_received > 0) {
            cout << "Message of TCP sender with fd " << _sender_fd << ": " << req_buf;
        } else if (bytes_received == 0) {
            vector<int>::iterator pos = find(_sender_fd_list.begin(), _sender_fd_list.end(), _sender_fd);
			if(pos != _sender_fd_list.end()) {
				_sender_fd_list.erase(pos);
			}
			printf("TCP sender with fd %d and IP %s is disconnected\n", _sender_fd, tcp_sender->ip_str);
			printf("Totally %ld TCP senders are connected now\n", _sender_fd_list.size());
            _total_connected_sndr_fd -= 1;
            printf("_total_connected_sndr_fd %d\n", _total_connected_sndr_fd);
			close(_sender_fd);
            break;
        } else cout << "Connection error\n";
    }
}
