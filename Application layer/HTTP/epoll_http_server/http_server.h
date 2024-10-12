#ifndef http_server_h
#define http_server_h

#include <iostream>          
#include <sys/socket.h>     /* for socket(), connect()*/
#include <stdlib.h>         /* for atoi() and exit() */
#include <string.h>         /* for memset() */
#include <unistd.h>         /* for close() */
#include <fcntl.h>          /* for open() */
#include <sys/types.h> 
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>      /* for inet_ntop() */

#include <vector>
#include <algorithm> // find()
#include <memory>
#include <fstream>
#include <functional>

#define MAXPENDING 	    5
#define BUFFSIZE 	    500
#define MAXEVENTS       1       // Maximum numbers of connected HTTP clients to handle/monitor
#define ELEMENT_NUMBERS 1
#define TIMEOUT         5000    // miliseconds

using namespace std;

class HTTP_Server {
public:
    HTTP_Server(int port, function<void (string&, string&)> request_handler, string &request, string &response, bool reuse_address = true, int max_pending = MAXPENDING);
private:
    int 				_http_server_fd;
    int 				_http_client_fd;// fd of the connected HTTP client
    vector<int>         _http_client_fd_list;
    int                 _epfd;
    int                 _port;
    int                 _max_pending;
    char                ip_str[30];
    bool                _reuse_address;
    struct 		        sockaddr_in http_client_addr;
    struct              epoll_event http_client_conn_evt;// New HTTP client connected event
    struct              epoll_event happened_events[MAXEVENTS];
    socklen_t 	        _http_client_length;
    string              _request, _response;

    int                 socket_parameters_init();
    void                http_client_handler();
    function<void (string&, string&)> _request_handler;
};

#endif
