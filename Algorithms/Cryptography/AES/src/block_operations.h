#include "aes.h"
#include "aes_encrypt.h"

// aes_encrypt and block_operations call each other recursively

#ifndef block_operations_h
#define block_operations_h

vector<vector<uint8_t>> form_blocks(vector<uint8_t> _hex_msg);
vector<vector<uint8_t>> column_major_order_transform(vector<uint8_t> _vec_1d);

#endif