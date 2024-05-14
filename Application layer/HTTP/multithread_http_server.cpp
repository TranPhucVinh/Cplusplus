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

#define REUSEADDR		    	true
#define MAXPENDING 		    	5
#define INIT_BUFF_SZ 		    500 // Initial buffer size to read a HTTP request
#define PORT 			    	8000

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

    int flags = fcntl(_http_client_fd, F_GETFL);// Get current flag status of the _http_client_fd
    if (flags == -1) {
        perror("fcntl F_GETFL");
        exit(EXIT_FAILURE);
    }

    // Set new flag status for the _http_client_fd, include: the current ones + O_NONBLOCK
    // O_NONBLOCK must be used. Without it, read() of read_http_request() will block permanently
    // after reading add the HTTP request
    if (fcntl(_http_client_fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl F_SETFL");
        exit(EXIT_FAILURE);
    }

	if (_http_client_fd > 0) return true;
	else return false;
}

void HTTP_Server::close_http_client(unique_ptr<HTTP_Client> http_client) {
	int http_client_fd;
	http_client_fd = http_client->_http_client_fd;

	vector<int>::iterator pos = find(_http_client_fd_list.begin(), _http_client_fd_list.end(), http_client_fd);
	if(pos != _http_client_fd_list.end()){
		_http_client_fd_list.erase(pos);
	}
	printf("HTTP client with fd %d and IP %s is disconnected\n", http_client_fd, http_client->ip_str);
	printf("Totally %ld HTTP clients are connected now\n", _http_client_fd_list.size());
	close(http_client_fd);
}

void HTTP_Server::http_client_thread_handling() {
	char ip_str[30];
	inet_ntop(AF_INET, &(http_client_addr.sin_addr.s_addr), ip_str, INET_ADDRSTRLEN);
	_http_client_fd_list.push_back(_http_client_fd);
	cout << "New HTTP client with fd " << _http_client_fd;
	cout << " connected with IP " << ip_str;
	cout << "; " << _http_client_fd_list.size() << " HTTP clients have connected now\n";

	unique_ptr<HTTP_Client> http_client = make_unique<HTTP_Client>();

	http_client->_http_client_fd = _http_client_fd;
	strcpy(http_client->ip_str, ip_str);

	thread http_client_thread(&HTTP_Server::request_handler, this, move(http_client), INIT_BUFF_SZ);
	http_client_thread.detach();
}

string HTTP_Server::read_http_request(int http_client_fd, int init_buf_sz){
	size_t totalReadBytes = 0;
	vector<char> _req_buf(init_buf_sz);

	while (true) {
        // Read into the buffer starting from the current end position
        int bytesRead = read(http_client_fd, _req_buf.data() + totalReadBytes, _req_buf.size() - totalReadBytes);
        
        if (bytesRead == -1) {
            perror("Error reading file");
            cout << "\n";
            break;
        } else if (bytesRead == 0) {
			break;// end of data
        }

        totalReadBytes += bytesRead;

        if (totalReadBytes == _req_buf.size()) {
            _req_buf.resize(_req_buf.size() * 2);// Double the buffer size
        }
    }

	_req_buf.resize(totalReadBytes);

	string req_buf_str = string(_req_buf.begin(), _req_buf.end());

	return req_buf_str;
}

/*
	req_buf_sz: Request buffer size	
*/
void HTTP_Server::request_handler(unique_ptr<HTTP_Client> http_client, int init_buf_sz){
	int http_client_fd;
    string req_buf_str;

	http_client_fd = http_client->_http_client_fd;
	req_buf_str = read_http_request(http_client_fd, init_buf_sz);

	if (req_buf_str.size() > 0) {
		cout << "New HTTP client with socket fd: " << http_client_fd << "\n";

		size_t get_request_index = req_buf_str.find("GET");
		size_t post_request_index = req_buf_str.find("POST");

		if (get_request_index != string::npos) {
			vector<string> _req_buf_vec = split_string_by_delim(req_buf_str, " ");
			string uri =  _req_buf_vec[1];
			get_request(uri, http_client_fd);
		}

		if (post_request_index != string::npos) {
            cout << "HTTP POST request:\n";
			cout << endl;
			cout << req_buf_str << endl << endl;

			close_http_client(move(http_client));
		}
	} else if (req_buf_str.size() == 0) {
		close_http_client(move(http_client)); 
	}
}

void HTTP_Server::get_request(string uri, int http_client_fd){
    if (uri == "/"){
        int fd = open("index.html", O_RDONLY);
        if (fd > 0){
            close(fd);//Only open this file to check for its existence
            string html_file = read_file("index.html");
			http_response(http_client_fd, "text/html", html_file.c_str());
        } else {
            // When having no index.html file, Content-Type must be text/html
			const char *no_file = "There is no index.html file";
			http_response(http_client_fd, "text/html", no_file);
        }
    } else {
        char no_uri[50];// URL not found handler
		sprintf(no_uri, "Not found %s", uri.c_str());
		http_response(http_client_fd, "text/html", (const char*)no_uri);
    }
}

/*
    HTTP response include: content_type, response content
*/
void HTTP_Server::http_response(int http_client_fd, const char *content_type, const char *content){
    int rsp_buf_sz = _httpd_hdr_str.length() + strlen("200 OK") + strlen(content_type) + strlen("\r\n") + strlen(content);
    char *res_buf = new char[rsp_buf_sz + 1];
    bzero(res_buf, rsp_buf_sz);//Delete buffer

    snprintf(res_buf, rsp_buf_sz, _httpd_hdr_str.c_str(), "200 OK", content_type, strlen(content));
    strcat(res_buf, "\r\n");
    strcat(res_buf, content);
    write(http_client_fd, res_buf, rsp_buf_sz);
    delete res_buf;
}

string HTTP_Server::read_file(const char *file_name){
    string data;
    ifstream ifs(file_name);

	if(!ifs.good()) {
		cout << "File" << file_name << "doesn't exist\n";
		return "NULL";
    }

    while (!ifs.eof()){
        string _data;
        getline(ifs, _data);
        data += _data + "\n";
    }
    return data;
}

/*
	Split string by delimiter
*/
vector<string> HTTP_Server::split_string_by_delim(string s, string delim) {
    vector<string> all_substr;
    std::size_t index = s.find(delim, 0);
    string sub_str  = s.substr(0, index);
    string new_string = s.substr(index+1);

    while (index != string::npos) { 
        if (sub_str != delim && sub_str.size() >= 1) {
            all_substr.push_back(sub_str);
        }

        index = new_string.find(delim, 0);
        sub_str  = new_string.substr(0, index);
        new_string = new_string.substr(index+1);
    }

    if (sub_str != delim && sub_str.size() >= 1) {
        all_substr.push_back(sub_str);
    }

    return all_substr;
}
