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
