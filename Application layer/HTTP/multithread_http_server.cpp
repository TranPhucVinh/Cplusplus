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

#define REUSEADDR		    true
#define ELEMENT_NUMBERS     1
#define MAXPENDING 		    5
#define BUFFSIZE 		    256
#define PORT 			    8000

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
		std::vector<int>    http_client_fd_list;
		std::string 		httpd_hdr_str = "HTTP/1.1 %s\r\nContent-Type: %s\r\nContent-Length: %d\r\n";
		struct 		        sockaddr_in http_client_addr;
		void  				response_file(const char *file_name);
		void				request_handler(std::unique_ptr<HTTP_Client> http_client, int req_buf_sz);
};

int main(){ 
	HTTP_Server http_server(PORT, REUSEADDR, MAXPENDING);
   	cout << "Waiting for a HTTP client to connect ...\n";
    while (1){
		if (http_server.is_new_http_client_connected() > 0){
			http_server.http_client_thread_handling();
		}
	}
}

HTTP_Server::HTTP_Server(int port, bool reuse_address, int max_pending){
	struct 	sockaddr_in http_server_addr;
    
    // Create TCP socket receiver
	_http_server_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (_http_server_fd < 0){
        perror("_http_server_fd\n");
    } else cout << "Create HTTP server socket successfully\n";
 
    http_server_addr.sin_family = AF_INET;                
    http_server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    http_server_addr.sin_port = htons(port);      

    // setsockopt() must be called before bind() so that SO_REUSEADDR can take effect
   	if (reuse_address){
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
    if (listen(_http_server_fd, max_pending) < 0) exit(0);
}

/*
	Check if a new HTTP client has connected
	Return true if there is a new connection, false if there isn't
*/
bool HTTP_Server::is_new_http_client_connected(){
	socklen_t http_client_length;
	http_client_length = sizeof(http_client_addr);//Get address size of sender
	_http_client_fd = accept(_http_server_fd, (struct sockaddr *) &http_client_addr, &http_client_length);
	if (_http_client_fd > 0) return true;
	else return false;
}

void HTTP_Server::http_client_thread_handling(){
	char ip_str[30];
	inet_ntop(AF_INET, &(http_client_addr.sin_addr.s_addr), ip_str, INET_ADDRSTRLEN);
	http_client_fd_list.push_back(_http_client_fd);
	cout << "New HTTP client with fd " << _http_client_fd;
	cout << " connected with IP " << ip_str;
	cout << "; " << http_client_fd_list.size() << " HTTP clients have connected now\n";

	std::unique_ptr<HTTP_Client> http_client = std::make_unique<HTTP_Client>();

	http_client->_http_client_fd = _http_client_fd;
	strcpy(http_client->ip_str, ip_str);

	std::thread http_client_thread(&HTTP_Server::request_handler, this, std::move(http_client), BUFFSIZE);
	http_client_thread.detach();
}

/*
	req_buf_sz: Request buffer size	
*/
void HTTP_Server::request_handler(std::unique_ptr<HTTP_Client> http_client, int req_buf_sz){
	int http_client_fd;
    string req_buf;

	std::unique_ptr<char[]> _req_buf{new char[req_buf_sz]};// Buffer for HTTP request from HTTP client
	bzero(_req_buf.get(), req_buf_sz);//Delete buffer

	http_client_fd = http_client->_http_client_fd;
	while(1){
		int bytes_received = read(http_client_fd, _req_buf.get(), req_buf_sz);
		if (bytes_received > 0) {
			cout << "New HTTP client with socket fd: " << http_client_fd << "; HTTP request:\n";
            req_buf = string(_req_buf.get());

			size_t rn_index = req_buf.find("\r\n"); // Find \r\n inside req_buf
            string first_line_request = req_buf.substr(0, rn_index);//

			string get_method = first_line_request.substr(0, 3);// Cut 3 char for "GET"
			string post_method = first_line_request.substr(0, 4);// Cut 4 char for "POST"

			if (!get_method.compare("GET")){
				string uri = first_line_request.substr(3, 3);
				if (!uri.compare(" / ")){
					int fd = open("index.html", O_RDONLY);
					if (fd > 0){
						close(fd);//Only open this file to check for its existence
						response_file("index.html");
					} else {
						char res_buf[100];
						char no_file[] = "There is no index.html file";
						snprintf(res_buf, sizeof(res_buf), httpd_hdr_str.c_str(), "200 OK", "text/html", sizeof(no_file));
						strcat(res_buf, "\r\n");
						strcat(res_buf, no_file);
						
						write(http_client_fd, res_buf, sizeof(res_buf));
					}
				} else {
                    strtok(_req_buf.get(), " ");
        			char* not_found_uri    = strtok(NULL, " ");

					char no_uri[50];
					char res_buf[100] = {0};
					int sz = sprintf(no_uri, "Not found %s", not_found_uri);
					snprintf(res_buf, sizeof(res_buf), httpd_hdr_str.c_str(), "200 OK", "text/html", sz);
					strcat(res_buf, "\r\n");
					strcat(res_buf, no_uri);
					write(http_client_fd, res_buf, sizeof(res_buf));
					cout << no_uri << endl;
				}
			} else {
				cout << "Unhandle METHOD from this type of request: " << first_line_request << endl;
			}

		} else {
			auto pos = find(http_client_fd_list.begin(), http_client_fd_list.end(), http_client_fd);
			if(pos != http_client_fd_list.end()){
				http_client_fd_list.erase(pos);
			}
			printf("HTTP client with fd %d and IP %s is disconnected\n", http_client_fd, http_client->ip_str);
			printf("Totally %ld HTTP clients are connected now\n", http_client_fd_list.size());
			close(http_client_fd); 
			break;
		}
	}
}

void HTTP_Server::response_file(const char *file_name){
    ifstream ifs(file_name, std::ios::ate);
    if(!ifs.good()) {
      cout << "Cannot open file!" << endl;
    } else cout << "Open file successfully\n";

    size_t file_sz = ifs.tellg(); 
    ifs.seekg(0);// Revert ifs back to index 0

    std::unique_ptr<char[]> file_buffer(new char[file_sz]);

    ifs.read(file_buffer.get(), file_sz);

	//HTTP response buffer size
	int rsp_buf_sz = strlen(file_buffer.get()) + httpd_hdr_str.length() + strlen("200 OK") + strlen("text/html") + strlen("\r\n");

    std::unique_ptr<char[]> res_buf(new char[rsp_buf_sz + 1]);
	bzero(res_buf.get(), rsp_buf_sz);//Delete buffer

	snprintf(res_buf.get(), rsp_buf_sz, httpd_hdr_str.c_str(), "200 OK", "text/html", file_sz);
	strcat(res_buf.get(), "\r\n");
	strcat(res_buf.get(), file_buffer.get());
	write(_http_client_fd, res_buf.get(), strlen(res_buf.get()));
}
