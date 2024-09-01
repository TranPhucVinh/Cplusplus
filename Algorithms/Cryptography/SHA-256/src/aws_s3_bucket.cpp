#include "sha256.h"
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>     // write(), read() and close()
#include <sys/socket.h> // socket() and connect()
#include <netdb.h>
#include <errno.h>

using namespace std;

#define ISO_8061_SZ     64
#define YYYYMMDD        10 // Must be 10 char for YYYYMMDD
#define HOST            "s3.ap-southeast-2.amazonaws.com"
#define PORT            80
#define STRING_TO_SIGN  "AWS4-HMAC-SHA256"
#define REGION          "ap-southeast-2"

string access_key_id, secret_access_key, session_key;

void    get_aws_env_vars(string &access_key_id, string &secret_access_key, string &session_key);
string  sha_256_to_string_hex(unique_ptr<uint32_t[]> sha_256_hash);
string  sha_256_to_string_char(unique_ptr<uint32_t[]> sha_256_hash);
string  amz_date();
string  yyyymmdd();
string  form_canon_req(const char *host, string payload_hash, string amz_date, const char *method,
                    const char *uri, const char *querystring);
string  form_string_to_sign(const char *string_to_sign, string amz_date, const char *region, string canon_req);
string  calculate_signature(string secret_access_key, const char *region);

class HTTP_Client {
	public:
		HTTP_Client(const char *host, in_port_t port);	
		int write_http_request(std::string http_request);
		char *read_http_response();
	private:
		int _http_client_fd;
};

int main() {
    string msg = "";
    SHA256 sha256, hmac;

    string amz_date_str = amz_date();
    string sha_256_msg_str = sha_256_to_string_hex(sha256.hex_digest(msg));
    get_aws_env_vars(access_key_id, secret_access_key, session_key);

    string cq = form_canon_req(HOST, sha_256_msg_str, amz_date_str, "GET", "/", "");
    string SigningKey = calculate_signature(secret_access_key, REGION);

    string StringToSign = form_string_to_sign(STRING_TO_SIGN, amz_date_str, REGION, cq);
    cout << "C++ StringToSign " << StringToSign << endl;

    string AWS_Signature_V4 = sha_256_to_string_hex(hmac.hmac_sha_256(SigningKey, StringToSign));    
    string Credential = access_key_id + "/" + yyyymmdd() + "/" + REGION + "/s3/aws4_request,"; // "," is mandatory

    string http_request;

    http_request = "GET / HTTP/1.1\r\nHost: " + string(HOST) + "\r\n";
	http_request += "x-amz-content-sha256: " + sha_256_msg_str + "\r\n";
    http_request += "x-amz-date: " + amz_date_str + "\r\n";
    http_request += "x-amz-security-token: " + session_key + "\r\n";
    http_request += "Authorization: AWS4-HMAC-SHA256 Credential=" + Credential;
    http_request += " SignedHeaders=host;x-amz-content-sha256;x-amz-date;x-amz-security-token, Signature=";
    http_request += AWS_Signature_V4;
    http_request += "\r\nConnection: close\r\n\r\n";
    
    std::cout << http_request << std::endl;

    HTTP_Client http_client(HOST, PORT); 
    http_client.write_http_request(http_request);

    char* recv_buf = http_client.read_http_response(); 
    std::string recv_str(recv_buf);
    std::cout << recv_str << std::endl;
    delete recv_buf;

    return 0;
}

string amz_date() {
    struct timeval tv;
    struct tm *tm_utc;
    char buffer[ISO_8061_SZ];

    // Get current time
    gettimeofday(&tv, NULL);

    // Convert time to UTC
    tm_utc = gmtime(&tv.tv_sec);

    // Format time as ISO 8601
    if (strftime(buffer, sizeof(buffer), "%Y%m%dT%H%M%SZ", tm_utc) == 0) {
        throw std::runtime_error("strftime failed");
    }

    return std::string(buffer);
}

string yyyymmdd() {
    struct timeval tv;
    struct tm *_tm;
    time_t _localtime;
    char buffer[YYYYMMDD];
    
    gettimeofday(&tv, NULL);
    _localtime = tv.tv_sec;
    _tm = localtime(&_localtime); 

    strftime(buffer, YYYYMMDD, "%Y%m%d", _tm);

    return string(buffer);
}

string form_canon_req(const char *host, string payload_hash, string amz_date, 
        const char *method, const char *uri, const char *querystring) {

    string cq = string(method) + "\n" + string(uri);
    cq += "\n" + string(querystring) + "\n";

    // Canonical Headers
    cq += "host:" + string(host) + "\n";
    cq += "x-amz-content-sha256:" + payload_hash + "\n";
    cq += "x-amz-date:" + amz_date + "\n";
    cq += "x-amz-security-token:" + session_key + "\n";

    // Signed Headers
    cq += "\nhost;x-amz-content-sha256;x-amz-date;x-amz-security-token\n";

    // Payload Hash
    cq += payload_hash;

    return cq;
}

string form_string_to_sign(const char *string_to_sign, string amz_date,
                            const char *region, string canon_req) {
    string _string_to_sign = string(string_to_sign) + "\n";
    _string_to_sign += amz_date + "\n";

    string Scope = yyyymmdd() + "/" + region + "/s3/aws4_request";

    SHA256 canon_req_sha;
    _string_to_sign += Scope + "\n" + sha_256_to_string_hex(canon_req_sha.hex_digest(canon_req));
    return _string_to_sign;
}

string calculate_signature(string secret_access_key, const char *region) {
    SHA256 _obj;
    string date_key = sha_256_to_string_char(_obj.hmac_sha_256(string("AWS4") + secret_access_key, yyyymmdd()));
    string date_region_key = sha_256_to_string_char(_obj.hmac_sha_256(date_key, region));
    string date_region_service_key = sha_256_to_string_char(_obj.hmac_sha_256(date_region_key, "s3"));
    string signing_key = sha_256_to_string_char(_obj.hmac_sha_256(date_region_service_key, "aws4_request"));

    return signing_key;
}

void get_aws_env_vars(string &access_key_id, string &secret_access_key, string &session_key) {
    const char* access_key_id_cstr = getenv("AWS_ACCESS_KEY_ID");
    const char* secret_access_key_cstr = getenv("AWS_SECRET_ACCESS_KEY");
    const char* session_key_cstr = getenv("AWS_SESSION_TOKEN");

    if (access_key_id_cstr == nullptr) {
        cout << "There is no AWS_ACCESS_KEY_ID\n";
        exit(0);
    } else {
        access_key_id = string(access_key_id_cstr);
        secret_access_key = string(secret_access_key_cstr);
        session_key = string(session_key_cstr);
    }
}

/*
    Convert the hex value from SHA-256 into  
    their corresponding ASCII character
*/
string sha_256_to_string_char(unique_ptr<uint32_t[]> sha_256_hash) {
    // for (int i = 0; i < 8; i++) {
    //     cout << hex << setw(8) << setfill('0') << sha_256_hash[i];
    // }
    // cout << endl;

    string _sha256_str = "";
    for (int i = 0; i < 8; i++) {
        _sha256_str += (char) (sha_256_hash[i] >> 24) & 0xFF;
        _sha256_str += (char) (sha_256_hash[i] >> 16) & 0xFF;
        _sha256_str += (char) (sha_256_hash[i] >> 8) & 0xFF;
        _sha256_str += (char) sha_256_hash[i] & 0xFF;
    }

    return _sha256_str;
}

/*
    Convert the hex value from SHA-256 into  
    string hex. e.g 0x12ab to "12ab"
*/
string sha_256_to_string_hex(unique_ptr<uint32_t[]> sha_256_hash) {
    string _sha256_str = "";
    for (int i = 0; i < 8; i++) {
        stringstream _stream;
        _stream << hex << setw(8) << setfill('0') << sha_256_hash[i];
        _sha256_str += _stream.str();
    }
    return _sha256_str;
}

HTTP_Client::HTTP_Client(const char *host, in_port_t port){
	struct hostent *hp;
	struct sockaddr_in addr;   

	if((hp = gethostbyname(host)) == NULL){
        std::cout << "Fail to get host " << host << std::endl;
		return;
	}
	bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	_http_client_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(_http_client_fd == -1){
		perror("setsockopt");
		exit(1);
	}
	
	if(connect(_http_client_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1){
		perror("connect");
		exit(1);
	}
}

int HTTP_Client::write_http_request(std::string http_request){
	if (write(_http_client_fd, http_request.c_str(), http_request.size()) < 0){
	    close(_http_client_fd);
	    return 0;
	}
	return 1;
}

/* Read HTTP response */
char *HTTP_Client::read_http_response(){
	char* recv_buf = NULL;
	int index = 0;
	int read_size_chunk = 0;
	recv_buf = new char[1024];
	while(1)
	{
		read_size_chunk = read(_http_client_fd, &recv_buf[index += read_size_chunk], 1024);
		if(read_size_chunk > 0)
		{
			recv_buf = (char*) realloc(recv_buf, index + read_size_chunk + 1024);
		}
		else
		{
			recv_buf = (char*) realloc(recv_buf, index + 1);
			recv_buf[index] = 0;
			break;
		}
	}

	shutdown(_http_client_fd, SHUT_RDWR); 
	close(_http_client_fd);
	return recv_buf;
}
