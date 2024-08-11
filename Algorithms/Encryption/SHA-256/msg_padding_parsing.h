#include <iostream>
#include <bitset>
#include <vector>
#include <sstream>
#include <iomanip>

#define BLOCK_SZ 512 // 512 bits is the block size of SHA-256

using namespace std;

int get_padding_size(string msg);
int total_appened_0(int msg_sz);
vector<bool> message_padding(string &msg);

vector<bitset<32>>      parse_block_into_words(vector<bool> msg_padding);
vector<vector<bool>>    parse_msg_to_block(vector<bool> msg);// Parse message the blocks of 512 bits
vector<vector<bitset<32>>> message_parsing(string &msg);