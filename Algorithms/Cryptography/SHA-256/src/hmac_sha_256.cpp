#include "sha256.h"

#include <unistd.h>

using namespace std;

int main() {
    string msg = "";

    string key = "key";
    
    SHA256 obj;// Object for HMAC-SHA256
    uint32_t *hmac_sha256_hash = obj.hmac_sha_256(key, msg);
    
    for (int i = 0; i < 8; i++) {
        printf("%x", hmac_sha256_hash[i]);
        // cout << hex << hmac_sha256_hash[i]; // cout prints out the wrong number
    }
    cout << endl;

    return 0;
}
