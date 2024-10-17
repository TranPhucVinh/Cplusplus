#ifndef SHA_H
#define SHA_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <vector>
#include <sstream>

#define BLOCK_SZ        512 // 512 bits is the block size of SHA-256
#define BLOCK_SZ_BYTES  BLOCK_SZ/8

// Bit set for Base64
#define SZ_8 8
#define SZ_6 6

using namespace std;

class SHA256 {
public:
    SHA256();
    unique_ptr<uint32_t[]> hex_digest(string msg);
    unique_ptr<uint32_t[]> hmac_sha_256(string key, string msg);
private:
    uint32_t _sha_256_const[64];
    unique_ptr<uint32_t[]> _hash;
    void hash_block(vector<bool> msg);
};

class SHA1 {
public:
    SHA1();
    unique_ptr<uint32_t[]> hex_digest(string msg);
private:
    uint32_t _K[80];
    unique_ptr<uint32_t[]> _hash;
    void hash_block(vector<bool> msg);
};

// Message padding and parsing functions
int                     get_padding_size(string msg);
int                     total_appened_0(int msg_sz);
vector<bool>            message_padding(string &msg);
vector<bitset<32>>      parse_block_into_words(vector<bool> msg_padding);
vector<vector<bool>>    parse_msg_to_block(vector<bool> msg);// Parse message the blocks of 512 bits


// SHA functions for bit manipulation
/*
    uint32_t must be used for unsigned int 32-bit integer.
    Must not use int32_t and int
*/
uint32_t SHR(uint32_t n, uint32_t x);
uint32_t ROTR(uint32_t n, uint32_t x);
uint32_t ROTL(uint32_t n, uint32_t x);
uint32_t CH(uint32_t x, uint32_t y, uint32_t z);
uint32_t MAJ(uint32_t x, uint32_t y, uint32_t z);

uint32_t BSIG0(uint32_t x);
uint32_t BSIG1(uint32_t x);
uint32_t SSIG0(uint32_t x);
uint32_t SSIG1(uint32_t x);

uint32_t sha1_func(uint32_t t, uint32_t b, uint32_t c, uint32_t d);
string   base64_encoding(string str);

#endif