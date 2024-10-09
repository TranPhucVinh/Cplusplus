#include "http_server.h"

HTTP_Server::HTTP_Server(int port, function<void (string&, string&)> request_handler, string &request, string &response, bool reuse_address, int max_pending){
    _port = port;
    _reuse_address = reuse_address;
    _request = request;
    _response = response;

    _max_pending = max_pending;
    _request_handler = request_handler;

    _http_client_length = sizeof(http_client_addr);//Get address size of sender
    _http_server_fd = socket_parameters_init();

    _epfd = epoll_create1(EPOLL_CLOEXEC);
    if (_epfd < 0) {
        printf("Unable to create an epoll fd\n");
        return;
    }

    // _http_server_fd must be added to monitor to detect the EPOLLIN event when a new TCP client connect to it
    http_client_conn_evt.events  = EPOLLIN;
    http_client_conn_evt.data.fd = _http_server_fd;
    if(epoll_ctl(_epfd, EPOLL_CTL_ADD, _http_server_fd, &http_client_conn_evt)){
        printf("Failed to add http_server_fd to be monitored by epoll");
        close(_http_server_fd);
        return;
    }
    printf("Waiting for a HTTP client to connect ...\n");
    while (1) {
        http_client_handler();
    }
}

void HTTP_Server::http_client_handler() {
    /*
        ready_socket_fds: Total ready TCP socket file descriptors
        Those TCP sockets can be both HTTP server and senders
    */
    int ready_socket_fds = epoll_wait(_epfd, happened_events, MAXEVENTS, TIMEOUT);

    if (ready_socket_fds == 0) printf("Timeout after %d miliseconds\n", TIMEOUT);
    else {
        // By using while(1) and this for() loop, happened_events() is updated in everytime the EPOLLIN happens to HTTP server and HTTP clients
        for(int i = 0; i < ready_socket_fds; i++) {
            int socket_fd = happened_events[i].data.fd;
            int http_client_fd;

            // A new HTTP client connects to HTTP server will trigger the EPOLLIN event in that HTTP server
            if(socket_fd == _http_server_fd) {
                if ((http_client_fd = accept(_http_server_fd, (struct sockaddr *) &http_client_addr, &_http_client_length)) > 0) {
                    inet_ntop(AF_INET, &(http_client_addr.sin_addr.s_addr), ip_str, INET_ADDRSTRLEN);
                    printf("New HTTP client with fd %d connected with IP %s\n", http_client_fd, ip_str);

                    struct epoll_event http_client_event;// epoll_event to monitor the newly connected HTTP client
                    http_client_event.events = EPOLLIN;
                    http_client_event.data.fd = http_client_fd;//Add file descriptor http_client_fd to monitor

                    // Add that http_client_event to be monitored by epoll
                    if (epoll_ctl(_epfd, EPOLL_CTL_ADD, http_client_fd, &http_client_event) < 0) {
                        printf("Unable to add fd of the connected HTTP client to be monitored by epoll\n");
                    } else {
                        _http_client_fd_list.push_back(http_client_fd);
                        printf("Succesfully add HTTP client fd %d to monitored list\n", http_client_fd);
                        printf("Totally %ld HTTP clients are connected now\n", _http_client_fd_list.size());
                    }
                }
            }

            // Any connected HTTP client writes data to HTTP server will trigger the EPOLLIN event in that HTTP server
            else {
                char req_buf[BUFFSIZE];// Buffer for HTTP request from HTTP client
                bzero(req_buf, BUFFSIZE);//Delete buffer
                http_client_fd = socket_fd;

                int bytes_received = read(http_client_fd, req_buf, BUFFSIZE);
                if (bytes_received > 0) {
                    _request = req_buf;
                    _request_handler(_request, _response);

                    const char *content = _response.c_str();
                    const char *content_type = "text/html";
                    
                    int rsp_buf_sz = _httpd_hdr_str.length() + strlen("200 OK") + strlen(content_type) + strlen("\r\n") + strlen(content);
                    char *res_buf = new char[rsp_buf_sz + 1];
                    bzero(res_buf, rsp_buf_sz);//Delete buffer

                    snprintf(res_buf, rsp_buf_sz, _httpd_hdr_str.c_str(), "200 OK", content_type, strlen(content));
                    strcat(res_buf, "\r\n");
                    strcat(res_buf, content);
                    write(http_client_fd, res_buf, rsp_buf_sz);
                } else {
                    vector<int>::iterator iter;
                    iter = find(_http_client_fd_list.begin(), _http_client_fd_list.end(), http_client_fd);
                    if(iter != _http_client_fd_list.end()){
                        _http_client_fd_list.erase(iter);
                    }
                    epoll_ctl(_epfd, EPOLL_CTL_DEL, http_client_fd, NULL);
                    cout << "HTTP client with fd " << http_client_fd << " and IP " << ip_str << " is disconnected\n";
                    cout << "Totally " << _http_client_fd_list.size() << " HTTP clients are connected now\n";
                    close(http_client_fd);
                }
            }
        }
    }
}

int HTTP_Server::socket_parameters_init() {
    struct 	sockaddr_in http_server_addr;
    
    // Create TCP socket receiver
	_http_server_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (_http_server_fd < 0){
        perror("_http_server_fd\n");
    } else cout << "Create HTTP server socket successfully\n";
 
    http_server_addr.sin_family = AF_INET;                
    http_server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    http_server_addr.sin_port = htons(_port);      

    // setsockopt() must be called before bind() so that SO_REUSEADDR can take effect
   	if (_reuse_address){
		int enable_val = 1;
        if (!setsockopt(_http_server_fd, SOL_SOCKET, SO_REUSEADDR, &enable_val, sizeof(enable_val))){
            cout << "Set socket to reuse address successfully\n";
        } else cout << "Unable to set socket to reuse address\n";
	}

    //Bind to the local address
    if (bind(_http_server_fd, (struct sockaddr *) &http_server_addr, sizeof(http_server_addr)) < 0) {
        cout << "Fail to bind socket to local address with errno \n" << errno << endl;
        exit(0);
    }
    else cout << "Start TCP socket receiver successfully through binding\n";

    //Set up connection mode for socket sender
    if (listen(_http_server_fd, _max_pending) < 0) exit(0);
    return _http_server_fd;
}
