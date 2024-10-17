#include "sha.h"

SHA1::SHA1() {
    uint32_t init_hash[] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};

    _hash = make_unique<uint32_t[]>(5);
    copy(init_hash, init_hash + 5, _hash.get());

    for (int t = 0; t < 80; t++) {
        if (t >= 0 && t <=19) _K[t] = 0x5A827999;
        else if (t >= 20 && t <= 39) _K[t] = 0x6ED9EBA1;
        else if (t >= 40 && t <= 59) _K[t] = 0x8F1BBCDC;
        else _K[t] = 0xCA62C1D6;
    }
}

unique_ptr<uint32_t[]> SHA1::hex_digest(string msg) {
    vector<bool> msg_padding = message_padding(msg);

    vector<vector<bool>> msg_blocks = parse_msg_to_block(msg_padding);

    for (int i = 0; i < msg_blocks.size(); i++) {
        hash_block(msg_blocks[i]);
    }

    // for (int i = 0; i < 5; i++) {
    //     cout << hex << setw(8) << setfill('0') << _hash[i];
    // }
    // cout << endl;
    
    return move(_hash);
}

void SHA1::hash_block(vector<bool> msg) {
    vector<bitset<32>> words = parse_block_into_words(msg);
    uint32_t W[80];

    for (int w_idx = 0; w_idx < 80; w_idx++) {
        if (w_idx < 16) W[w_idx] = words[w_idx].to_ulong();
        else {
            W[w_idx] = ROTL(1, W[w_idx-3] ^ W[w_idx-8] ^ W[w_idx-14] ^ W[w_idx-16]);
        }
    }

    uint32_t a = _hash[0], b = _hash[1], c = _hash[2], d = _hash[3];
    uint32_t e = _hash[4];

    for (uint32_t t = 0; t < 80; t++) {
        uint32_t TEMP = (ROTL(5, a) + sha1_func(t, b, c, d) + e + W[t] + _K[t]) % (long) pow(2, 32);
        e = d; d = c; c = ROTL(30, b); b = a; a = TEMP;
    }
    _hash[0] = (_hash[0] + a) % (long) pow(2, 32);
    _hash[1] = (_hash[1] + b) % (long) pow(2, 32);
    _hash[2] = (_hash[2] + c) % (long) pow(2, 32);
    _hash[3] = (_hash[3] + d) % (long) pow(2, 32);
    _hash[4] = (_hash[4] + e) % (long) pow(2, 32);
}