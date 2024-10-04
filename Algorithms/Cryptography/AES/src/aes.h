#ifndef aes_h
#define aes_h

#include "aes_encrypt.h"
#include "key_expansion.h"

#define STATE_ROWS  4 // AES state array has 4 rows
#define NB          4

using namespace std;

class AES: public AES_Encrypt {
public:
    AES(string encryption_key) : AES_Encrypt(STATE_ROWS, NB, encryption_key) {}
};

#endif