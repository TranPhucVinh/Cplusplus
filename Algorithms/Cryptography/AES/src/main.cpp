#include "aes.h"

int main() {
    string msg = "1234567890123456";
    string key = "1234567890123456";
    vector<uint8_t> iv(16, 0x0);
    AES aes(key);
    
    vector<uint8_t> encrypted_txt = aes.cbc_encrypt(msg, iv);
    
    for (int i = 0; i < encrypted_txt.size(); i++) {
        cout << hex << "0x" << static_cast<int>(encrypted_txt[i]) << " ";
    }
    cout << endl; 
    
    return 0;
}