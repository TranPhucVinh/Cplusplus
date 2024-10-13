#include "sha256.h"

#include <unistd.h>

using namespace std;

/*
    Convert the hex value from SHA-256 into  
    their corresponding ASCII character
*/
string sha_256_to_string_char(unique_ptr<uint32_t[]> sha_256_hash) {
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

int main() {
    string msg1 = "", msg2 = "msg", msg3 = "key_64_chars";

    string key = "key";

    SHA256 obj;// Object for HMAC-SHA256
    unique_ptr<uint32_t[]> hmac_sha256_hash = obj.hmac_sha_256(key, msg1);

    cout << sha_256_to_string_hex(move(hmac_sha256_hash)) << endl;
    cout << sha_256_to_string_hex(obj.hmac_sha_256(key, msg2)) << endl;
    cout << sha_256_to_string_hex(obj.hmac_sha_256(sha_256_to_string_char(obj.hmac_sha_256(key, msg2)), msg3)) << endl;
    return 0;
}