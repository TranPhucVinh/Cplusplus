#include "http_server.h"

#define PORT            8000

void request_handler(string &request, string &response);
string read_file(const char *file_name);
vector<string> split_string_by_delim(string s, string delim);

int main() {
    string request, response;
    HTTP_Server http_server(PORT, request_handler, request, response);
    return 0;
}

void request_handler(string &request, string &response) {
    size_t get_request_index = request.find("GET");
    size_t post_request_index = request.find("POST");

    if (get_request_index != string::npos) {
        vector<string> _req_buf_vec = split_string_by_delim(request, " ");
        string uri =  _req_buf_vec[1];
        string content;
        response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: ";

        if (uri == "/"){
            string file_data = read_file("index.html");
            if (file_data != "NULL") content = file_data;
            else content = "There is no index.html file";
        } else {
            content = "Unhandle URL " + uri;
        }
        response += to_string(content.length()) + "\r\n\r\n" + content;
    }

    if (post_request_index != string::npos) {
        response = "HTTP POST";
    }
    
    return;
}

string read_file(const char *file_name) {
    string data;
    ifstream ifs(file_name);

	if(!ifs.good()) {
		cout << "File " << file_name << "doesn't exist\n";
		return "NULL";
    }

    while (!ifs.eof()){
        string _data;
        getline(ifs, _data);
        data += _data + "\n";
    }
    return data;
}

vector<string> split_string_by_delim(string s, string delim) {
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
