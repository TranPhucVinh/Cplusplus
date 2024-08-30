#include "sha256.h"

SHA256::SHA256() {
    uint32_t sha_256_const[] = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
                            0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
                            0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
                            0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
                            0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
                            0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
                            0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
                            0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
                            0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
                            0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
                            0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
                            0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
                            0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
                            0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
                            0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
                            0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

    uint32_t init_hash[] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
                0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
        
    copy(begin(sha_256_const), end(sha_256_const), begin(_sha_256_const));

    _hash = make_unique<uint32_t[]>(8);
    copy(init_hash, init_hash + 8, _hash.get());
}

unique_ptr<uint32_t[]> SHA256::hex_digest(string msg) {
    vector<bool> msg_padding = message_padding(msg);

    vector<vector<bool>> msg_blocks = parse_msg_to_block(msg_padding);

    for (int i = 0; i < msg_blocks.size(); i++) {
        hash_block(msg_blocks[i]);
    }

    // for (int i = 0; i < 8; i++) {
    //     cout << hex << setw(8) << setfill('0') << _hash[i];
    // }
    // cout << endl;
    
    return move(_hash);
}

unique_ptr<uint32_t[]> SHA256::hmac_sha_256(string key, string msg) {
    if (key.size() < BLOCK_SZ_BYTES) {
        key.resize(BLOCK_SZ_BYTES, '\0'); // Pad key if shorter than 64 bytes
    }

    char ipad[BLOCK_SZ_BYTES], opad[BLOCK_SZ_BYTES];

    for (int i = 0; i < BLOCK_SZ_BYTES; i++) {
        ipad[i] = 0x36;
        opad[i] = 0x5C;
    }

    char ipad_xor[64];
    for (int i = 0; i < 64; i++) {
        ipad_xor[i] = ipad[i] ^ key[i];
    }

    // Must init ipad_xor with size BLOCK_SZ_BYTES to avoid NULL delimiter in
    // ipad_xor to make its size less than BLOCK_SZ_BYTES
    string inner_str_concat = string(ipad_xor, BLOCK_SZ_BYTES) + msg;

    SHA256 sha256_1;

    unique_ptr<uint32_t[]> _inner_hash = sha256_1.hex_digest(inner_str_concat);// HMAC SHA-256

    char inner_hash_char[32];// Split the 256-bit has into 32 chars
    int _idx = 0;
    for (int i = 0; i < 8; i++) {
        inner_hash_char[_idx] = (char) (_inner_hash[i] >> 24) & 0xFF;
        inner_hash_char[_idx+1] = (char) (_inner_hash[i] >> 16) & 0xFF;
        inner_hash_char[_idx+2] = (char) (_inner_hash[i] >> 8)  & 0xFF;
        inner_hash_char[_idx+3] = (char) _inner_hash[i] & 0xFF;
        _idx += 4;
    }

    char opad_xor[BLOCK_SZ_BYTES];
    for (int i = 0; i < BLOCK_SZ_BYTES; i++) {
        opad_xor[i] = opad[i] ^ key[i];
    }

    string opad_str_concat = string(opad_xor, BLOCK_SZ_BYTES) + string(inner_hash_char, 32);

    SHA256 sha256_2;
    _inner_hash = sha256_2.hex_digest(opad_str_concat);

    // for (int i = 0; i < 8; i++) {
    //     cout << hex << setw(8) << setfill('0') << _inner_hash[i];
    // }
    // cout << endl;

    return _inner_hash;
}

void SHA256::hash_block(vector<bool> msg) {
    vector<bitset<32>> words = parse_block_into_words(msg);

    uint32_t W[64];

    for (int w_idx = 0; w_idx < 64; w_idx++) {
        if (w_idx < 16) W[w_idx] = words[w_idx].to_ulong();
        else {
            W[w_idx] = (SSIG1(W[w_idx - 2]) + W[w_idx - 7] + SSIG0(W[w_idx-15]) + W[w_idx - 16] ) % 
                        (long) pow(2, 32);// Must cast to (long) to avoid "Floating point exception"
        }
    }

    uint32_t a = _hash[0], b = _hash[1], c = _hash[2], d = _hash[3];
    uint32_t e = _hash[4], f = _hash[5], g = _hash[6], h = _hash[7];

    for (int w_idx = 0; w_idx < 64; w_idx++) {
        uint32_t T1 = h + BSIG1(e) + CH(e, f, g) + _sha_256_const[w_idx]+ W[w_idx];
        T1 = T1 % (long)pow(2, 32);
            
        uint32_t T2 = (BSIG0(a) + MAJ(a, b, c)) % (long)pow(2, 32);
        h = g;
        g = f;
        f = e;
        e = (d + T1) % (long)pow(2, 32);
        d = c;
        c = b;
        b = a;
        a = (T1+ T2) % (long)pow(2, 32);
    }

    _hash[0] = (_hash[0]+ a) % (long)pow(2, 32);
    _hash[1] = (_hash[1]+ b) % (long)pow(2, 32);
    _hash[2] = (_hash[2]+ c) % (long)pow(2, 32);
    _hash[3] = (_hash[3]+ d) % (long)pow(2, 32);
    _hash[4] = (_hash[4]+ e) % (long)pow(2, 32);
    _hash[5] = (_hash[5]+ f) % (long)pow(2, 32);
    _hash[6] = (_hash[6]+ g) % (long)pow(2, 32);
    _hash[7] = (_hash[7]+ h) % (long)pow(2, 32);
}
