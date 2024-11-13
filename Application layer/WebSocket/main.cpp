#include "http_server.h"
#include "sha.h"

#define PORT            8000

void request_handler(string &request, string &response);
string read_file(const char *file_name);
vector<string> split_string_by_delim(string s, string delim);
string ws_data_parsing(string data);

int main() {
    string request, response;
    HTTP_Server http_server(PORT, request_handler, request, response);
    return 0;
}

void request_handler(string &request, string &response) {
    vector<string> _req_buf_vec = split_string_by_delim(request, " ");// Parse for URI
    if (_req_buf_vec.size() > 2) {
        string uri =  _req_buf_vec[1];
        string content;

        if (uri == "/"){
            response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: ";
            string file_data = read_file("index.html");
            if (file_data != "NULL") content = file_data;
            else content = "There is no index.html file";
            response += to_string(content.length()) + "\r\n\r\n" + content;
        } else if (uri == "/ws") {
            cout << "request /ws is triggered\n";
            
            size_t ws_key = request.find("Sec-WebSocket-Key:", 0);

            if ((request.find("Connection: Upgrade", 0) != string::npos)
                && (request.find("Upgrade: websocket", 0) != string::npos)
                && (request.find("Sec-WebSocket-Version: 13", 0) != string::npos)
                && (ws_key != string::npos)) {
                    // Size of Sec-WebSocket-Key: <24 bytes of ws key> is 43
                    string sub_str  = request.substr(ws_key, 43);
                    string ws_key = split_string_by_delim(sub_str, " ")[1];
                    string ws_magic_string = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
                    ws_key += ws_magic_string;

                    SHA1 sha1;
                    unique_ptr<uint32_t[]> sha_1_hash = sha1.hex_digest(ws_key);

                    string _ws_key_str;

                    // Convert SHA-1 to string
                    for (int i = 0; i < 5; i++) {
                        _ws_key_str += (char) (sha_1_hash[i] >> 24) & 0xFF;
                        _ws_key_str += (char) (sha_1_hash[i] >> 16) & 0xFF;
                        _ws_key_str += (char) (sha_1_hash[i] >> 8) & 0xFF;
                        _ws_key_str += (char) sha_1_hash[i] & 0xFF;
                    }

                    // WebSocket handshake process requires a Base64-encoded SHA-1
                    _ws_key_str = base64_encoding(_ws_key_str);
                    
                    response = "HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\n";
                    response += "Connection: Upgrade\r\nSec-WebSocket-Accept: ";
                    response += _ws_key_str + "\r\n\r\n";
                }
        }
        else {
            content = "Unhandle URL " + uri;
            response += to_string(content.length()) + "\r\n\r\n" + content;
        }
    } else { // Read WS response from WS client
        ws_data_parsing(request);
    }
    return;
}

string ws_data_parsing(string data) {
    string client_payload;
    uint8_t fin = data[0] >> 7;
    uint8_t rsv1 = (data[0] >> 6) & 0b01;
    uint8_t rsv2 = (data[0] >> 5) & 0b001;
    uint8_t rsv3 = (data[0] >> 4) & 0b0001;
    uint8_t opcode = data[0] & 0b1111;

    uint8_t mask = data[1] >> 7;
    uint8_t payload_length = data[1] & 0b01111111;
    if (mask == 1 && payload_length != 126 && payload_length != 127) {
        vector<uint8_t> masking_key, payload;
        masking_key.push_back(data[2]);
        masking_key.push_back(data[3]);
        masking_key.push_back(data[4]);
        masking_key.push_back(data[5]);

        uint8_t _index = 6;
        
        for (uint8_t i = 0; i < payload_length; i++) {
            payload.push_back(data[_index]);
            payload[i] ^= masking_key[i % 4];
            _index += 1;
            client_payload += string(1, payload[i]);
        }
        cout << client_payload << endl;
            
    }

    return client_payload;
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
    size_t index = s.find(delim, 0);
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
