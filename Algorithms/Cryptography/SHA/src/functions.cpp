#include "sha.h"

uint32_t SHR(uint32_t n, uint32_t x) {
    return (x >> n);
}

uint32_t ROTR(uint32_t n, uint32_t x) {
    return ((x >> n) | (x << (32-n))); // 32-bit word
}

uint32_t ROTL(uint32_t n, uint32_t x) {
    return ((x << n) | (x >> (32-n))); // 32-bit word
}

uint32_t CH(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ ( (~x) & z);
} 

uint32_t MAJ(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
} 

uint32_t BSIG0(uint32_t x) {
    return ROTR(2, x) ^ ROTR(13, x) ^ ROTR(22, x);
}

uint32_t BSIG1(uint32_t x) {
    return ROTR(6, x) ^ ROTR(11, x) ^ ROTR(25, x);
}

uint32_t SSIG0(uint32_t x) {
    return ROTR(7, x) ^ ROTR(18, x) ^ SHR(3, x);
}

uint32_t SSIG1(uint32_t x) {
    return ROTR(17, x) ^ ROTR(19, x) ^ SHR(10, x);
}

// f(t) with t = [0 to 79] are SHA1 logical functions
uint32_t sha1_func(uint32_t t, uint32_t b, uint32_t c, uint32_t d) {
    if (t <=19) {
        return (b & c) | (~b & d);
    } else if (t >= 20 && t <= 39) {
       return b ^ c ^ d;
    } else if (t >= 40 && t <= 59) {
        return (b & c) | (b & d) | (c & d);
    } else {
        return b ^ c ^ d;
    }
}

string base64_encoding(string str) {
    string ret_str;

    bitset<SZ_8> bitset_arr[str.size()];
    vector<bool> full_str;

    for (int i = 0; i < str.size(); i++) {
        bitset_arr[i] = str[i];
    }

    for (int i = 0; i < str.size(); i++) {
        for (int j = SZ_8-1; j >=0; j--) full_str.push_back(bitset_arr[i][j]);
    }

    // Calculate the number of padding bytes (not bits)
    int original_size = full_str.size() / SZ_8;  // Original number of bytes
    int padding_count = (3 - (original_size % 3)) % 3;  // Calculate required padding (0, 1, or 2 bytes)

    while (full_str.size() % SZ_6) {
        full_str.push_back(0);  // Add padding bits to complete 6-bit groups
    }
    
    int base64_arr_sz = full_str.size()/SZ_6;
    bitset<SZ_6> base64_arr[base64_arr_sz];

    int _idx = 0;
    for (int i = 0; i < base64_arr_sz; i++) {
        for (int j = SZ_6 - 1; j >= 0; j--) {
            base64_arr[i][j] = full_str[_idx];
            _idx += 1;
        }
    }

    for (int i = 0; i < base64_arr_sz; i++) {
        int base64_val = base64_arr[i].to_ulong();
        if (base64_val <= 25) {
            ret_str += (base64_val + 65);
        } else if (base64_val <= 51) {
            ret_str += (base64_val + 71);
        } else if (base64_val <= 61) {
            ret_str += (base64_val-4);
        } else if (base64_val == 62) {
            ret_str += "+";
        } else {
            ret_str += "/";
        }
    }

    // Add padding characters ('=') based on the number of padding bytes
    for (int i = 0; i < padding_count; i++) {
        ret_str += '=';
    }

    return ret_str;
}