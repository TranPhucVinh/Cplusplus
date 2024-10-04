#include "block_operations.h"

/*
    Form the blocks of BLOCK_SZ bytes from the original hex message
*/
vector<vector<uint8_t>> form_blocks(vector<uint8_t> _hex_msg) {
    int total_block = _hex_msg.size()/BLOCK_SZ;
    vector<vector<uint8_t>> _blocks(total_block, vector<uint8_t>(BLOCK_SZ));

    for (int _row = 0; _row < total_block; _row++) {
        for (int _col = 0; _col < BLOCK_SZ; _col++) {
            _blocks[_row][_col] = _hex_msg[_row*BLOCK_SZ + _col];
        }
    }

    return _blocks;
}

vector<vector<uint8_t>> column_major_order_transform(vector<uint8_t> _vec_1d) {
    vector<vector<uint8_t>> _vector_2d(STATE_ROWS, vector<uint8_t>(NB));

    for (int _row = 0; _row < STATE_ROWS; _row++) {
        for (int _col = 0; _col < NB; _col++) {
            _vector_2d[_row][_col] = _vec_1d[_row + 4*_col];
        }
    }

    return _vector_2d;
}

vector<uint8_t> string_to_hex_vec(string str) {
    vector<uint8_t> hex_vec;
    for (int i = 0; i < str.size(); i++) {
        hex_vec.push_back((uint8_t) str[i]);
    }
    return hex_vec;
}

void right_rotate(vector<uint8_t> &vec, int rotate_time) {
    vector<uint8_t> _tmp_vec(vec.size());

    copy(vec.begin(), vec.end(), _tmp_vec.begin());

    for (int i = 0; i < vec.size(); i++){
        vec[(i + vec.size() - rotate_time) % vec.size()] = _tmp_vec[i];
    }
}

void left_rotate(vector<uint8_t> &vec, int rotate_time) {
    vector<uint8_t> _tmp_vec(vec.size());
    copy(vec.begin(), vec.end(), _tmp_vec.begin());
    for (int i = 0; i < vec.size(); i++){
        vec[(i + rotate_time) % vec.size()] = _tmp_vec[i];
    }
}

uint8_t aes_gf_mult(uint8_t a, uint8_t b) {
    uint8_t result = 0;
    uint8_t carry;

    // Iterate over each bit of b
    for (int i = 0; i < 8; i++) {
        // If the lowest bit of b is set, XOR the current value of a with the result
        if (b & 1) {
            result ^= a;
        }

        // Check if the most significant bit of a is set
        carry = a & 0x80;

        // Left shift a by 1
        a <<= 1;

        // Right shift b by 1 to process the next bit
        b >>= 1;

        // If carry was set, XOR a with 0x1b (which represents the irreducible polynomial)
        if (carry) {
            a ^= 0x1b;
        }
    }

    return result;
}

vector<vector<uint8_t>> multiply_matrices(vector<vector<uint8_t>> a, vector<vector<uint8_t>> b) {
    vector<vector<uint8_t>> multiply(4, vector<uint8_t>(4));

    for (int col = 0; col < 4; col++) {
        for (int _row = 0; _row < 4; _row++) {
            multiply[_row][col] = 0;
            for (int _col = 0; _col < 4; _col++) {
                multiply[_row][col] ^= aes_gf_mult(a[_row][_col], b[_col][col]);
            }
        }
    }
    return multiply;
}
