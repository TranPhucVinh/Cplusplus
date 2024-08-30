#include "sha256.h"

#include <unistd.h>

using namespace std;

string sha_256_to_string(unique_ptr<uint32_t[]> sha_256_hash) {
    string _sha256_str = "";
    for (int i = 0; i < 8; i++) {
        stringstream _stream;
        _stream << hex << setw(8) << setfill('0') << sha_256_hash[i];
        _sha256_str += _stream.str();
    }
    return _sha256_str;
}

int main() {
    string msg1 = "", msg2 = "msg";

    string key = "key";
    
    SHA256 obj;// Object for HMAC-SHA256
    unique_ptr<uint32_t[]> hmac_sha256_hash = obj.hmac_sha_256(key, msg1);

    cout << sha_256_to_string(move(hmac_sha256_hash)) << endl;
    cout << sha_256_to_string(obj.hmac_sha_256(key, msg2)) << endl;

    return 0;
}