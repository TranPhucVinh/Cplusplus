#include "aes_encrypt.h"
#include "key_expansion.h"
#include "block_operations.h"

AES_Encrypt::AES_Encrypt(uint8_t state_rows, uint8_t nb, string encryption_key) {
    _state_rows = state_rows;
    _nb = nb;
    _encryption_key = string_to_hex_vec(encryption_key);
    _round_keys = setup_all_round_keys(_encryption_key);
}

vector<uint8_t> AES_Encrypt::cbc_encrypt(string plain_txt, vector<uint8_t> iv) {
    vector<uint8_t> encrypted_txt;
    vector<uint8_t> hex_msg = string_to_hex_vec(plain_txt);
    int lth = hex_msg.size();
    uint8_t padding = BLOCK_SZ - (lth % BLOCK_SZ);

    for (int i = 0; i < padding; i++) hex_msg.push_back(padding);

    vector<vector<uint8_t>> _block_msg = form_blocks(hex_msg);
    vector<vector<uint8_t>> _encrypted_txt(_block_msg.size(), vector<uint8_t>(BLOCK_SZ));
    for (int i = 0; i < _block_msg.size(); i++) {
        for (int j = 0; j < BLOCK_SZ; j++) {
            if (i == 0) {        
                _block_msg[i][j] = _block_msg[i][j] ^ iv[j];
            } 
            else {
                _block_msg[i][j] = _block_msg[i][j] ^ _encrypted_txt[i-1][j];
            }
        } 

        _encrypted_txt[i] = block_encrypt(_block_msg[i]);

        for (int j = 0; j < BLOCK_SZ; j++) {
            encrypted_txt.push_back(_encrypted_txt[i][j]);
        }
    }

    return encrypted_txt;
}

vector<uint8_t> AES_Encrypt::block_encrypt(vector<uint8_t> block) {
    // Initial state
    vector<vector<uint8_t>> state = column_major_order_transform(block);
    vector<vector<uint8_t>> encryption_key_2d = column_major_order_transform(_encryption_key);
    state = add_round_key(state, encryption_key_2d);

    // AES_ROUNDS - 1 = 9 main rounds
    for (int i = 0; i < AES_ROUNDS - 1; i++) {
        substitution_box(state);
        shift_row(state);
        state = multiply_matrices(mix_column_encrypt, state);

        state = add_round_key(state, column_major_order_transform(_round_keys[i]));
    }

    // The last round
    substitution_box(state);
    shift_row(state);
    state = add_round_key(state, column_major_order_transform(_round_keys[AES_ROUNDS - 1]));

    vector<uint8_t> encrypted_hex(_state_rows * _nb);
    for (int _row = 0; _row < 4; _row++) {
        for (int _col = 0; _col < 4; _col++) {
            encrypted_hex[_row + 4*_col] = state[_row][_col];
        }
    }

    return encrypted_hex;
}

vector<uint8_t> AES_Encrypt::string_to_hex_vec(string str) {
    vector<uint8_t> hex_vec;
    for (int i = 0; i < str.size(); i++) {
        hex_vec.push_back((uint8_t) str[i]);
    }
    return hex_vec;
}

void AES_Encrypt::substitution_box(vector<vector<uint8_t>> &encrypted_msg) {
    for (int _row = 0; _row < _state_rows; _row++) {
        for (int _col = 0; _col < _nb; _col++) {
            encrypted_msg[_row][_col] = sbox[(encrypted_msg[_row][_col] >> 4) & 0xf][encrypted_msg[_row][_col] & 0xf];
        }
    }
}

void AES_Encrypt::shift_row(vector<vector<uint8_t>> &_vec) {
    int rotate_time = 1;// Right rotate 1 byte for 1st row
    right_rotate(_vec[rotate_time], rotate_time); rotate_time += 1;
    right_rotate(_vec[rotate_time], rotate_time); rotate_time += 1;
    right_rotate(_vec[rotate_time], rotate_time);
}

uint8_t AES_Encrypt::aes_gf_mult(uint8_t a, uint8_t b) {
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

vector<vector<uint8_t>> AES_Encrypt::multiply_matrices(vector<vector<uint8_t>> a, vector<vector<uint8_t>> b) {
    vector<vector<uint8_t>> multiply(_nb, vector<uint8_t>(_nb));

    for (int col = 0; col < _nb; col++) {
        for (int _row = 0; _row < _nb; _row++) {
            multiply[_row][col] = 0;
            for (int _col = 0; _col < _nb; _col++) {
                multiply[_row][col] ^= aes_gf_mult(a[_row][_col], b[_col][col]);
            }
        }
    }
    return multiply;
}
