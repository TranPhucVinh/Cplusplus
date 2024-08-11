#include "msg_padding_parsing.h"
#include "functions.h"

class SHA256 {
    public:
        SHA256();
        void hex_digest(string msg);
        void hex_digest_tmp(string &msg);
    private:
        uint32_t _sha_256_const[64], _hash[8];

        void hash_block(vector<bool> msg);
        void hash_block_temp(vector<bitset<32>> &block_word);
        void return_hash();
};
