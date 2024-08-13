#include "msg_padding_parsing.h"
#include "functions.h"

class SHA256 {
    public:
        SHA256();
        uint32_t* hex_digest(string msg);
    private:
        uint32_t _sha_256_const[64], _hash[8];

        void hash_block(vector<bool> msg);
        void return_hash();
};
