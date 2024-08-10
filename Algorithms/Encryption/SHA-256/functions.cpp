#include "functions.h"

uint32_t SHR(uint32_t n, uint32_t x) {
    return (x >> n);
}

uint32_t ROTR(uint32_t n, uint32_t x) {
    return ((x >> n) | (x << (32-n))); // 32-bit word
}

uint32_t ROTL(uint32_t n, uint32_t x) {
    return ((x << n) | (x >> (32-n))); // 32-bit word
}

uint32_t CH(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ ( (~x) & z);
} 

uint32_t MAJ(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
} 

uint32_t BSIG0(uint32_t x) {
    return ROTR(2, x) ^ ROTR(13, x) ^ ROTR(22, x);
}

uint32_t BSIG1(uint32_t x) {
    return ROTR(6, x) ^ ROTR(11, x) ^ ROTR(25, x);
}

uint32_t SSIG0(uint32_t x) {
    return ROTR(7, x) ^ ROTR(18, x) ^ SHR(3, x);
}

uint32_t SSIG1(uint32_t x) {
    return ROTR(17, x) ^ ROTR(19, x) ^ SHR(10, x);
}
