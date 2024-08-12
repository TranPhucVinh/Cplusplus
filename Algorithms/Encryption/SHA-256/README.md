The SHA-256 implementation follows "RFC 6234 - US Secure Hash Algorithms".

When a message of any length < 2^64 bits (for SHA-224 and SHA-256) or < 2^128 bits (for SHA-384 and SHA-512) is input to one of these algorithms, the result is an output called a message digest.

The message digests range in length from 224 to 512 bits, depending on the algorithm. Secure Hash Algorithms are typically used with other cryptographic algorithms, such as digital signature algorithms and keyed-hash authentication codes, the generation of random numbers [RFC4086], or in key derivation functions.

It is computationally infeasible to:
1. Find a message that corresponds to a given message digest
2. Find two different messages that produce the same message digest

The algorithm uses:
1. a message schedule of sixty-four 32-bit words
2. 8 working variables of 32 bits each
3. a hash value of 8 32-bit words which stores the final SHA256 value

Before calculating SHA, setup **functions**, **constants** and the **initial hash values**:
* Functions: [functions.h](functions.h)
* SHA-256 uses 64 32-bit constant stored in array ``sha_256_const`` (sha_256_const[0] to sha_256_const[63]):  ``uint32_t sha_256_const[]`` in [sha256.cpp](sha256.cpp)
* Initial SHA-256 hash values: ``uint32_t init_hash[]`` in [sha256.cpp](sha256.cpp)

Steps to calculate the SHA follow the following orders:
1. Message Padding and Parsing

# 1. Message Padding and Parsing

The purpose of message padding in SHA-256 is to make the total length of a padded message a multiple of 512. The **"big-endian" convention** is used when expressing 64-bit words, so that within each word the most significant bit is shown in the leftmost bit position.

The padding process of SHA-256 is perfomed as a "1" followed by m "0"s followed by a 64-bit integer appended to the end of the message to produce a padded message of length 512*n. The appended 64-bit integer is the length of the original message. The padded message is then processed by the hash function as n 512-bit.

Suppose a message has length L < 2^64. Before it is input to the hash function, the message is padded on the right as follows:
1. "1" is appended. Example: if the original message is "01010000", this is padded to "010100001".
2.  K "0"s are appended where K is the smallest, non-negative solution to the equation
```
( L + 1 + K ) mod 512 = 448
```
3. Then append the 64-bit block that is L in binary representation.

After taking the above 3 steps, the length of the message will be a multiple of 512 bits.

**Example**: Suppose the original message is the bit string
```
01100001 01100010 01100011 01100100 01100101
```
After step (1) this gives:
```
01100001 01100010 01100011 01100100 01100101 1
```
Since L = 40, the number of bits in the above is 41 and K = 407 "0"s are appended, making the total now 448. This gives the following in hex:
```
61626364 65800000 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000
```
The 64-bit representation of L = 40 is hex 00000000 00000028. Hence the final padded message is the following hex
```
61626364 65800000 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000028
```
