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

namespace
{
    constexpr bool REUSEADDR        = true;
    constexpr int ELEMENT_NUMBERS   = 1;
    constexpr int MAXPENDING 	    = 5;
    constexpr int BUFFSIZE 		    = 256;
    constexpr int PORT              = 8000;
}

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
		std::vector<int>    _http_client_fd_list;
		std::string 		_httpd_hdr_str = "HTTP/1.1 %s\r\nContent-Type: %s\r\nContent-Length: %d\r\n";
		struct 		        sockaddr_in _http_client_addr;
		char  				*read_file(const char *file_name);
        void                http_response(int http_client_fd, const char *content_type, const char *content);
		void				request_handler(std::unique_ptr<HTTP_Client> http_client, int req_buf_sz);
};
