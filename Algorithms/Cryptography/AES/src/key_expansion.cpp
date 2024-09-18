#include "key_expansion.h"

vector<uint8_t> setup_each_round_key(vector<uint8_t> encryption_key, int _round_index) {
    uint8_t each_round_constants[4] = {round_constants[_round_index], 0x0, 0x0, 0x0};
    vector<uint8_t> _each_round_key;

    vector<vector<uint8_t>> _key_rows = key_rows(encryption_key);

    vector<uint8_t> _tmp_key_rows_3 = _key_rows[3];
    right_rotate(_tmp_key_rows_3);

    // S-box and adding round constant for _key_rows[3]
    vector<uint8_t> _rc_key_row(STATE_ROWS);// key_row[3] after adding round constant
    for (int i = 0; i < STATE_ROWS; i++) {
        _rc_key_row[i] = sbox[(_tmp_key_rows_3[i] >> 4) & 0xf][_tmp_key_rows_3[i] & 0xf] ^ each_round_constants[i];
    }

    // Form new key row
    vector<vector<uint8_t>> _new_key_rows(STATE_ROWS, vector<uint8_t>(NB));

    for (int i = 0; i < NB; i++) {
        _new_key_rows[0][i] = _key_rows[0][i] ^ _rc_key_row[i];
        _each_round_key.push_back(_new_key_rows[0][i]);
    }

    for (int i = 0; i < NB; i++) {
        _new_key_rows[1][i] = _new_key_rows[0][i] ^ _key_rows[1][i];
        _each_round_key.push_back(_new_key_rows[1][i]);
    }

    for (int i = 0; i < NB; i++) {
        _new_key_rows[2][i] = _new_key_rows[1][i] ^ _key_rows[2][i];
        _each_round_key.push_back(_new_key_rows[2][i]);
    }

    for (int i = 0; i < NB; i++) {
        _new_key_rows[3][i] = _new_key_rows[2][i] ^ _key_rows[3][i];
        _each_round_key.push_back(_new_key_rows[3][i]);
    }

    return _each_round_key;
}

vector<vector<uint8_t>> setup_all_round_keys(vector<uint8_t> encryption_key) {
    vector<vector<uint8_t>> all_round_keys(AES_ROUNDS, vector<uint8_t>(16));

    vector<uint8_t> _each_round_key = encryption_key;

    for (uint8_t round_index = 0; round_index < AES_ROUNDS; round_index++) {
        _each_round_key = setup_each_round_key(_each_round_key, round_index);
        all_round_keys[round_index] = _each_round_key;// Remember not to use push_back() here
    }

    return all_round_keys;
}

vector<vector<uint8_t>> key_rows(vector<uint8_t> encryption_key) {
    vector<vector<uint8_t>> _key_rows(STATE_ROWS, vector<uint8_t>(NB));

    for (int _row = 0; _row < STATE_ROWS; _row++) {
        for (int _col = 0; _col < NB; _col++) {
            _key_rows[_row][_col] = encryption_key[_col + 4*_row];
        }
    }

    return _key_rows;
}

void right_rotate(vector<uint8_t> &vec, int rotate_time) {
    vector<uint8_t> _tmp_vec(vec.size());

    copy(vec.begin(), vec.end(), _tmp_vec.begin());

    for (int i = 0; i < vec.size(); i++){
        vec[(i + vec.size() - rotate_time) % vec.size()] = _tmp_vec[i];
    }
}
