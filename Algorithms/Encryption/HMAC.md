HMAC (Hash-based Message Authentication Code) is a specific type of message authentication code (MAC) involving a cryptographic hash function and a secret cryptographic key. Steps to calculate HMAC includes:
* Preparation
* Key Adjustment
* Inner Padding (ipad) and Outer Padding (opad)
* Inner Hashing
* Outer Hashing, i.e the HMAC
# Preparation
* Message (M): The data or message that you want to authenticate.
* Key (K): A secret key known only to the sender and receiver.
* Hash Function (H): A cryptographic hash function like SHA-256, MD5.
This example will implement HMAC with SHA-256.
# Key Adjustment
**Block Size (B)**: The block size of the hash function (e.g., 64 bytes for SHA-256).

Key Length:
* If the key (K) is longer than the block size (B), hash it to reduce its length: ``K' = H(K)``
* If the key is shorter than B, pad it with zeros to make it B bytes long.
Let's denote this adjusted key as **K'**, which is either the hashed or zero-padded key.

In HMAC SHA-256, with the key is longer than the block size of 64 byte, after hasing to ``K'``, ``K'`` now has the size of 32 bytes. When then need to pad ``K'`` with zeros so that it's 64 bytes long.

# Inner Padding (ipad) and Outer Padding (opad)
* **ipad**: A string char (``uint8_t``) of the block size B, consisting of totally B 0x36 bytes. E.g for HMAC SHA-256, ipad is the ``uint8_t`` array of B=64 bytes of ``0x36``.
* **opad**: A string char (``uint8_t``) of the block size B, consisting of totally B 0x5C bytes. E.g for HMAC SHA-256, opad is the ``uint8_t`` array of B=64 bytes of ``0x5C``.

# Inner Hashing

Compute the inner hash by 3 steps:
* Step 1: XOR B bytes of 2 array: **K'** (the adjusted key) and ``ipad``
* Step 2: Concatenate the result of step 1 with the original message ``M``
* Step 3: Put the result in step 2 to the hash function, i.e SHA-256

```c
Inner_Hash=H((K' XOR ipad) concatenate M)
```
# Outer Hashing, i.e calculate the HMAC
Compute the outer hash, i.e the final result as HAMC, by 3 steps:
* Step 1: XOR B bytes of 2 array: **K'** (the adjusted key) and ``ipad``
* Step 2: Concatenate the result of step 1 with the **Inner_Hash** (from the previous step Inner Hashing).

Specifically for HMAC-SHA256, **Inner_Hash** is an array of 8 member of 32-bit, while step 1 has returned an array of 64 members of 8-bit. So we have to parse the **Inner_Hash** array into the array of 32 members of 8-bit, before concatenating.

* Step 3: Put the result in step 2 to the hash function, i.e SHA-256. The result will be the HMAC value.

The result is the HMAC, a fixed-length string that serves as the MAC for the message. This value can be sent along with the message to allow the receiver to verify the integrity and authenticity of the message using the shared secret key.
