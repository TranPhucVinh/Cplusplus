#include "aes_decrypt.h"

#include "key_expansion.h"
#include "block_operations.h"

AES_Decrypt::AES_Decrypt(uint8_t state_rows, uint8_t nb, string encryption_key) {
    _state_rows = state_rows;
    _nb = nb;
    _encryption_key = string_to_hex_vec(encryption_key);
    _round_keys = setup_all_round_keys(_encryption_key);
}

void AES_Decrypt::decrypt(vector<uint8_t> encrypted_msg, vector<uint8_t> iv) {
    vector<uint8_t> decrypted_txt;

    vector<vector<uint8_t>> _encrypted_block = form_blocks(encrypted_msg);
    vector<vector<uint8_t>> _decrypted_txt(_encrypted_block.size(), vector<uint8_t>(BLOCK_SZ));

    for (int i = 0; i < _encrypted_block.size(); i++) {
        _decrypted_txt[i] = block_decrypt(_encrypted_block[i]);

        for (int j = 0; j < BLOCK_SZ; j++) {
            if (i == 0) {        
                _decrypted_txt[i][j] = _decrypted_txt[i][j] ^ iv[j];
            } 
            else {
                _decrypted_txt[i][j] = _decrypted_txt[i][j] ^ _encrypted_block[i-1][j];
            }
        } 

        for (int j = 0; j < BLOCK_SZ; j++) {
            decrypted_txt.push_back(_decrypted_txt[i][j]);
        }
    }
}

vector<uint8_t> AES_Decrypt::block_decrypt(vector<uint8_t> _encrypted_block) {
    vector<uint8_t> decrypted_hex(_state_rows * _nb);
    vector<vector<uint8_t>> state(_state_rows, vector<uint8_t>(_nb));

    for (int _row = 0; _row < 4; _row++) {
        for (int _col = 0; _col < 4; _col++) {
            state[_row][_col] = _encrypted_block[_row + 4*_col];
        }
    }

    // Initial round key addition
    state = add_round_key(state, column_major_order_transform(_round_keys[AES_ROUNDS - 1]));

    // Main decryption rounds
    for (int i = AES_ROUNDS - 2; i >= 0; i--) {
        inverse_shift_row(state);
        inverse_substitution_box(state);
        state = add_round_key(state, column_major_order_transform(_round_keys[i]));
        state = multiply_matrices(inverse_mix_column, state);        
    }

    inverse_shift_row(state);
    inverse_substitution_box(state);

    vector<vector<uint8_t>> encryption_key_2d = column_major_order_transform(_encryption_key);
    state = add_round_key(state, encryption_key_2d);

    for (int _row = 0; _row < _state_rows; _row++) {
        for (int _col = 0; _col < _nb; _col++) {
            decrypted_hex[_row + 4 * _col] = state[_row][_col];
        }
    }

    for (int i = 0; i < decrypted_hex.size(); i++) {
        // cout << hex << "0x" << static_cast<int>(decrypted_hex[i]) << " ";
        cout << (char)(decrypted_hex[i]) << " ";
    }
    cout << endl;

    return decrypted_hex;
}

void AES_Decrypt::inverse_shift_row(vector<vector<uint8_t>> &_vec) {
    int rotate_time = 1;// Right rotate 1 byte for 1st row
    left_rotate(_vec[rotate_time], rotate_time); rotate_time += 1;
    left_rotate(_vec[rotate_time], rotate_time); rotate_time += 1;
    left_rotate(_vec[rotate_time], rotate_time);
}

void AES_Decrypt::inverse_substitution_box(vector<vector<uint8_t>> &_vec) {
    for (int _row = 0; _row < _state_rows; _row++) {
        for (int _col = 0; _col < _nb; _col++) {
            _vec[_row][_col] = inverse_sbox[_vec[_row][_col] >> 4][_vec[_row][_col] & 0x0F];
        }
    }
}