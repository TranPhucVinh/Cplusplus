#include "sha.h"

using namespace std;

string sha_1_to_string_hex(unique_ptr<uint32_t[]> sha_1_hash) {
    string _sha1_str = "";
    for (int i = 0; i < 5; i++) {
        stringstream _stream;
        _stream << hex << setw(8) << setfill('0') << sha_1_hash[i];
        _sha1_str += _stream.str();
    }

    return _sha1_str;
}

string sha_1_to_string_char(unique_ptr<uint32_t[]> sha_1_hash) {
    string _sha_1_str = "";
    for (int i = 0; i < 5; i++) {
        _sha_1_str += (char) (sha_1_hash[i] >> 24) & 0xFF;
        _sha_1_str += (char) (sha_1_hash[i] >> 16) & 0xFF;
        _sha_1_str += (char) (sha_1_hash[i] >> 8) & 0xFF;
        _sha_1_str += (char) sha_1_hash[i] & 0xFF;
    }

    return _sha_1_str;
}

int main() {
    // string msg = "mhZ9lUo8LcJYNL9HJ1cQHw==258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
    string msg = "abcxyz";
    SHA1 sha1;
    unique_ptr<uint32_t[]> sha_1_hash = sha1.hex_digest(msg);
    cout << sha_1_to_string_hex(move(sha_1_hash)) << endl;
    cout << base64_encoding(sha_1_to_string_char(move(sha_1_hash))) << endl;
    
    return 0;
}