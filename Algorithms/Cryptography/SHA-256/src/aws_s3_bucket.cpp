#include "sha256.h"
#include <time.h>
#include <sys/time.h>

using namespace std;

#define ISO_8061_SZ     64
#define HOST            "HOST"
#define STRING_TO_SIGN  "AWS4-HMAC-SHA256"
#define REGION         "ap-southeast-1"

char *amz_date();
string form_canon_req(const char *host, uint32_t* payload_hash, char *amz_date, const char *method,
                    const char *uri, const char *querystring);
string form_string_to_sign(const char *string_to_sign, char *amz_date, const char *region, string canon_req);

int main() {
    string msg = "";
    SHA256 sha256;
    uint32_t* payload_hash = sha256.hex_digest(msg);

    form_canon_req(HOST, payload_hash, amz_date(), "GET", "/", "");
    return 0;
}

char *amz_date() {
    struct timeval tv;
    struct tm *_tm;
    time_t _localtime;
    char *buffer = new char[ISO_8061_SZ];

    gettimeofday(&tv, NULL);
    _localtime = tv.tv_sec;

    _tm = localtime(&_localtime);    
    string time_str;
    strftime(buffer, ISO_8061_SZ, "%Y%m%dT%H%M%SZ", _tm);
    return buffer;
}

string form_canon_req(const char *host, uint32_t* payload_hash, char *amz_date, 
        const char *method, const char *uri, const char *querystring) {
    
    string cq = "", payload_hash_str = "";

    for (int i = 0; i < 8; i++) {
        stringstream _stream;
        _stream << hex << setw(8) << setfill('0') << payload_hash[i];
        payload_hash_str += _stream.str();
    }

    cq += string(method) + "\n" + string(uri);
    cq += "\n" + string(querystring) + "\n";

    // Canonical Headers
    cq += "host:" + string(host) + "\n";
    cq += "x-amz-content-sha256:" + payload_hash_str + "\n";
    cq += "x-amz-date:" + string(amz_date) + "\n";

    // Signed Headers
    cq += "\nhost;x-amz-content-sha256;x-amz-date\n";

    // Payload Hash
    cq += payload_hash_str;

    return cq;
}

string form_string_to_sign(const char *string_to_sign, char *amz_date,
                            const char *region, string canon_req) {
    string _string_to_sign = string(string_to_sign) + "\n";
    _string_to_sign += string(amz_date) + "\n";
}