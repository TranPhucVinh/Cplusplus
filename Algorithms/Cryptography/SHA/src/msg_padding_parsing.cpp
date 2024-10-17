#include "sha.h"

vector<bool> message_padding(string &msg) {
    vector<bool> msg_padding; 
    bitset<64> msg_sz;
    msg_sz = msg.length() * 8;

    for (int i = 0; i < msg.length(); i++) {
        bitset<8> msg_char = msg[i];
        for (int j = 0; j < 8; j++){
           msg_padding.push_back(msg_char[7-j]); 
        }        
    }

    msg_padding.push_back(0b1);

    int K = total_appened_0(msg_sz.to_ullong());

    for (int i = 0; i < K; i++) {
        msg_padding.push_back(0b0);
    }

    for (int i = 0; i < 64; i++) {
        msg_padding.push_back(msg_sz[63 - i]);
    }

    return msg_padding;
}

// Parse every 512-bit block into 16 32-bit words
vector<bitset<32>> parse_block_into_words(vector<bool> msg_padding) {
    vector<bitset<32>> words;

    int padding_index = 0;
    while (padding_index < 512) {
        bitset<32> word;
        for (int i = 0; i < 32; i++) {
            word[31-i] = msg_padding[padding_index];
            padding_index += 1;
        }
        words.push_back(word);
    }

    return words;
}

/*
    Parse the padding message into block of 64 bytes (512 bits)
*/
vector<vector<bool>> parse_msg_to_block(vector<bool> msg) {
    vector<vector<bool>> msg_blocks;

    int total_blocks =  msg.size() / 512;// Total blocks of 64 bytes (512 bits)
    int left_over_bits = msg.size() % 512;

    int msg_idx = 0;
    
    vector<bool>::iterator iter = msg.begin();

    if (total_blocks > 0) {
        while (msg_idx < msg.size()) {
            vector<bool> block(iter + msg_idx, iter + msg_idx + 512);
            msg_blocks.push_back(block);
            msg_idx += 512;
        }
    } else if (total_blocks == 0) {
        vector<bool> block(iter + msg_idx, iter + msg_idx + left_over_bits);
        msg_blocks.push_back(block);
    }

    return msg_blocks;
}

// L + 1 + K = 512*n + 448
// L = msg_sz (in bit)
int total_appened_0(int msg_sz) {
    int n;

    if ((float)(msg_sz - 447) / 512 < 0) {
        n = 0;
    } else {
        if (!((msg_sz - 447) % 512)) {
            n = (msg_sz - 447) / 512;
        } else {
            n = (int) ((msg_sz - 447) / 512) + 1;
        }
    }

    return 512*n + 447 - msg_sz;
}