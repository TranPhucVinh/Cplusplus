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
#include <memory>
#include <fstream>

using namespace std;

#define INIT_BUFF_SZ 		    500 // Initial buffer size to read a HTTP request

class HTTP_Client {	
	public:
		char ip_str[30]; 
		int _http_client_fd;
};

class HTTP_Server {
	public:
		HTTP_Server(int port, bool reuse_address, int max_pending);
		bool 				is_new_http_client_connected();
		void 				http_client_thread_handling();
	private:
		int 				_http_server_fd;
		int 				_http_client_fd;//fd of the connected HTTP client
		vector<int>         _http_client_fd_list;
        
		struct 		        sockaddr_in http_client_addr;

		string 		        _httpd_hdr_str = "HTTP/1.1 %s\r\nContent-Type: %s\r\nContent-Length: %d\r\n";

		string 				read_http_request(int http_client_fd, int init_buf_sz);
		void				request_handler(unique_ptr<HTTP_Client> http_client, int req_buf_sz);
		void				close_http_client(unique_ptr<HTTP_Client> http_client);

        void                http_response(int http_client_fd, const char *content_type, const char *content);
        void 				get_request(string uri, int http_client_fd);

        string  			read_file(const char *file_name);
        vector<string>      split_string_by_delim(string s, string delim);
};
