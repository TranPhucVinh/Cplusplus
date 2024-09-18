#include "aes_128.h"

#include <sstream>
#include <iomanip>

int main() {
    string msg = "1234567890123456";
    string key = "1234567890123456";

    AES aes(key);
    vector<uint8_t> encrypted_hex = aes.encrypt(msg);
    
    for (int i = 0; i < 16; i++) {
        cout << hex << "0x" << static_cast<int>(encrypted_hex[i]) << " ";
    }
    cout << endl; 
    
    return 0;
}
