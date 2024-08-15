#include "sha256.h"

#define BLOCK_SZ_BYTES BLOCK_SZ/8

using namespace std;

int main() {
    string msg = "";

    // HMAC-SHA256
    string private_key = "key";
    if (private_key.size() < BLOCK_SZ_BYTES) {
        private_key.resize(BLOCK_SZ_BYTES, '\0'); // Pad key if shorter than 64 bytes
    }

    char ipad[BLOCK_SZ_BYTES], opad[BLOCK_SZ_BYTES];

    for (int i = 0; i < BLOCK_SZ_BYTES; i++) {
        ipad[i] = 0x36;
        opad[i] = 0x5C;
    }

    char ipad_xor[64];
    for (int i = 0; i < 64; i++) {
        ipad_xor[i] = ipad[i] ^ private_key[i];
    }

    // Must init ipad_xor with size BLOCK_SZ_BYTES to avoid NULL delimiter in
    // ipad_xor to make its size less than BLOCK_SZ_BYTES
    string inner_str_concat = string(ipad_xor, BLOCK_SZ_BYTES) + msg;

    SHA256 sha2561;
    uint32_t* inner_hash = sha2561.hex_digest(inner_str_concat);

    char inner_hash_char[32];// Split the 256-bit has into 32 chars
    int _idx = 0;
    for (int i = 0; i < 8; i++) {
        inner_hash_char[_idx] = (char) (inner_hash[i] >> 24) & 0xFF;
        inner_hash_char[_idx+1] = (char) (inner_hash[i] >> 16) & 0xFF;
        inner_hash_char[_idx+2] = (char) (inner_hash[i] >> 8)  & 0xFF;
        inner_hash_char[_idx+3] = (char) inner_hash[i] & 0xFF;
        _idx += 4;
    }

    char opad_xor[BLOCK_SZ_BYTES];
    for (int i = 0; i < BLOCK_SZ_BYTES; i++) {
        opad_xor[i] = opad[i] ^ private_key[i];
    }

    string opad_str_concat = string(opad_xor, BLOCK_SZ_BYTES) + string(inner_hash_char, 32);

    SHA256 sha2562;
    inner_hash = sha2562.hex_digest(opad_str_concat);
    for (int i = 0; i < 8; i++) {
        cout << hex << setw(8) << setfill('0') << inner_hash[i];
    }
    cout << endl;

    return 0;
}
