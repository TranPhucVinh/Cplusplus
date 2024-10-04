#include "aes.h"
#include "aes_encrypt.h"

// aes_encrypt and block_operations call each other recursively

#ifndef block_operations_h
#define block_operations_h

vector<vector<uint8_t>> form_blocks(vector<uint8_t> _hex_msg);
vector<vector<uint8_t>> column_major_order_transform(vector<uint8_t> _vec_1d);
vector<uint8_t>         string_to_hex_vec(string str);
void                    right_rotate(vector<uint8_t> &vec, int rotate_time = 1);
void                    left_rotate(vector<uint8_t> &vec, int rotate_time = 1);
uint8_t                 aes_gf_mult(uint8_t a, uint8_t b);
vector<vector<uint8_t>> multiply_matrices(vector<vector<uint8_t>> a, vector<vector<uint8_t>> b);
#endif