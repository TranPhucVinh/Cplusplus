#include "msg_padding_parsing.h"

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

vector<vector<bitset<32>>> message_parsing(string &msg) {
    vector<vector<bitset<32>>> msg_blocks;
    uint64_t msg_sz_bit = msg.length() * 8;
    uint64_t msg_sz_byte = msg.length();
    int zero_append_num = total_appened_0(msg_sz_bit);

    int total_sz_bit = msg_sz_bit + 1 + zero_append_num + 64; // this value mod 512 must be 0

    int number_of_block = total_sz_bit / 512;

    bool pad_zero = false;

    for (int i = 0; i < number_of_block; i++) {
        vector<bitset<32>> block;
        for (int j = i*64; j < i*64 + 64; j+=4) {
            bitset<32> word = 0;
            if (!pad_zero) { // loading the message data part
                for (int k = j; k < j + 4; k++) {
                    if (k < msg_sz_byte) { // go until the pointer still in the msg data buffer
                        word |= msg[k] << (8 * (3 - (k-j))); // big endian
                    } else { // encounter the end of message buffer, add bit 1, and load some rented zero bit to complete 32 bit word, then minus that rented number to zero_append_num
                        word |= 0x80 << (8 * (3 - (k-j)));
                        pad_zero = true;
                        zero_append_num -= (7 + (3 - (k-j))*8); // This include the 7 zero bit from the byte above and the reminaing bit in left over byte of current 32 bit word
                        break;
                    }
                }
            } else { // loading the zero padding and finally the total message size
                if (zero_append_num == 0) { // this case must happen due to all the math logic, and the padding for message size is 64 bit
                    block.push_back((msg_sz_bit >> 32 & 0xFFFFFFFF));
                    block.push_back((msg_sz_bit & 0xFFFFFFFF));
                    break;
                } else {
                    zero_append_num -= 32; // pad 32 zero at the time, do nothing and add to the block
                }
            }
            block.push_back(word);
        }
        msg_blocks.push_back(block);
    }
    return msg_blocks;
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
