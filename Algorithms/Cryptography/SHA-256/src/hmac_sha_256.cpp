#include "sha256.h"

#include <unistd.h>

using namespace std;

string sha_256_to_string(uint32_t* sha_256_hash) {
    string _sha256_str = "";
    for (int i = 0; i < 8; i++) {
        stringstream _stream;
        _stream << hex << setw(32) << setfill('0') << static_cast<int>(sha_256_hash[i]);
        _sha256_str += _stream.str();
    }
    return _sha256_str;

    // for (int i = 0; i < 8; i++) {
    //     // printf("%x", sha_256_hash[i]);
    //     cout << hex << setw(8) << setfill('0') << sha_256_hash[i]; // cout prints out the wrong number
    // }
    // cout << endl;
    // return "inner ";
}

int main() {
    string msg = "";

    string key = "key";
    
    SHA256 obj;// Object for HMAC-SHA256
    uint32_t *hmac_sha256_hash = obj.hmac_sha_256(key, msg);

    for (int i = 0; i < 8; i++) {
        printf("%x", hmac_sha256_hash[i]);
        // cout << hex << hmac_sha256_hash[i]; // cout prints out the wrong number
        // cout << hex << setw(8) << setfill('0') << hmac_sha256_hash[i]; // cout prints out the wrong number
    }
    cout << endl;

    cout << sha_256_to_string(hmac_sha256_hash) << endl;
    
    return 0;
}