#include "aes.h"

int main() {
    string msg = "1234567890123456abcxyz Hello, World !";
    // string msg = "1234567890123456";
    string key = "1234567890123456";
    vector<uint8_t> iv(38, 0x0);
    AES aes_encrypt(key);
    
    vector<uint8_t> encrypted_txt = aes_encrypt.cbc_encrypt(msg, iv);
    
    for (int i = 0; i < encrypted_txt.size(); i++) {
        cout << hex << "0x" << static_cast<int>(encrypted_txt[i]) << " ";
    }
    cout << endl; 
    
    AES aes_decrypt(key);
    aes_decrypt.decrypt(encrypted_txt, iv);
    return 0;
}