#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

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
