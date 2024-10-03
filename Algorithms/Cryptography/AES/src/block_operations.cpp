#include "block_operations.h"

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
