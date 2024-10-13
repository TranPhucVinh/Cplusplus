#include "sha256.h"

using namespace std;

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
    string msg = "";
    SHA256 sha256;
    unique_ptr<uint32_t[]> sha_256_hash = sha256.hex_digest(msg);
    cout << sha_256_to_string_hex(move(sha_256_hash)) << endl;
    
    return 0;
}
