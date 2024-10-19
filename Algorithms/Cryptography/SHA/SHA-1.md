SHA-1 is defined in RFC 3174

Steps to calculate SHA-1, which are quite similar to SHA-256, follow the following orders:
1. Message Padding and Parsing: Pad and parse the original message into a new message msg_padding.
2. Parse the padding message msg_padding into N blocks of 64 bytes (512 bits) M[i]: M[0] ... M[N-1]
3. For every message block M[i], parse them into 16 32-bit words M[i][0] ... M[i][15]
4. Start hash calculation

Step 1, 2 and 3 of SHA-1 are identical to SHA-256, just only step 4 is differnt with its unique functions
# 4. Start hash calculation

The SHA-1 hash calculation finally returns ``uint32_t _hash[5]``. Before starting hash calculation, init ``_hash``: ``_hash = init_hash``

Please note that all addition below include performing modulo 2^32, i.e ``% pow(2, 32)``. This step is to make sure all variables are limited to 32-bit.

For every message block ``M[i]``, the hash calculation steps are.

1. Prepare the message schedule ``W``:

```cpp
uint32_t W[80];

for (int w_idx = 0; w_idx < 80; w_idx++) {
    if (w_idx < 16) W[w_idx] = words[w_idx].to_ulong();
    else {
        W[w_idx] = ROTL(1, W[w_idx-3] ^ W[w_idx-8] ^ W[w_idx-14] ^ W[w_idx-16]);
    }
}
```

2. Initialize the working variables:

```cpp
uint32_t a = _hash[0], b = _hash[1], c = _hash[2], d = _hash[3]; uint32_t e = _hash[4];
```
3. Perform the main hash computation for all t = 0 to < 80:

```cpp
for (uint32_t t = 0; t < 80; t++) {
    uint32_t TEMP = (ROTL(5, a) + sha1_func(t, b, c, d) + e + W[t] + _K[t]) % (long) pow(2, 32);
    e = d; d = c; c = ROTL(30, b); b = a; a = TEMP;
}
```
Where ``sha1_func()`` is defined in ``functions.cpp``.

4. Calculate the hash value of the current message block ``M[i]``:
```cpp
_hash[0] = (_hash[0] + a) % (long) pow(2, 32);
_hash[1] = (_hash[1] + b) % (long) pow(2, 32);
_hash[2] = (_hash[2] + c) % (long) pow(2, 32);
_hash[3] = (_hash[3] + d) % (long) pow(2, 32);
_hash[4] = (_hash[4] + e) % (long) pow(2, 32);
```
Repeat those 4 steps for all message block ``M[i]``. The SHA-1 value of the original message will be the concatenation of all of ``_hash[0]`` through ``_hash[4]``.