#include "aes_128.h"

// aes_128 and key_expansion call each other recursively

#ifndef key_expansion_h
#define key_expansion_h

const uint8_t round_constants[AES_ROUNDS] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36
};

vector<vector<uint8_t>> key_rows(vector<uint8_t> encryption_key);
void right_rotate(vector<uint8_t> &vec, int rotate_time = 1);
vector<uint8_t> setup_each_round_key(vector<uint8_t> encryption_key, int _round_index);
vector<vector<uint8_t>> setup_all_round_keys(vector<uint8_t> encryption_key);

#endif