**PKCS** (**Public Key Cryptography Standards**) **Cryptographic Message Syntax** (**CMS**) is a standard used for securely transmitting data through encryption, signing, authentication, and key management in cryptographic messages. CMS (Cryptographic Message Syntax) as defined in RFC 5652 is the successor to **PKCS#7**. PKCS#7 padding is more general, when compared to PKCS#5, and can be used with any block size between 1 and 255 bytes. This makes PKCS#7 suitable for modern block ciphers like AES, which uses a block size of 16 bytes (128 bits).

PKCS#5 specifically defines methods for secure password-based encryption and doesn't relate to CMS. PKCS#5 Padding is specifically designed for block ciphers with a block size of 8 bytes (64 bits) and isn't used in AES CBC.

**Cipher Block Chaining** (CBC) mode can be part of CMS (Cryptographic Message Syntax), specifically for encrypting content. In the CMS standard (RFC 5652), several symmetric encryption algorithms are supported, and CBC mode is one of the commonly used modes for block ciphers like AES and 3DES.

# Encryption
For AES-128 encryption with CBC mode, it's called AES-CBC-128. AES-CBC-128 include the AES raw encryption, padding and **Initialization Vector** (**IV**). Encryption steps will be:
* PKCS 7 padding
* Form message blocks with 16 bytes for each block
* AES-128 raw encryption for each block which includes IV
## PKCS 7 padding 
AES CBC assumes the plain text message input length is a multiple of k bytes, where k bytes is the block size. With AES-128, the block size is 16 bytes. So k is 16. With the input length is ``lth`` bytes, then, this message is padded at the trailing end with ``k-(lth mod k)`` bytes all having value ``k-(lth mod k)``.
## Form message blocks
After PKCS 7 padding steps, the plain text now is a multiple of 16 bytes. We have to form the message blocks with 16 bytes for each block. Message blocks will be marked as m0, m1, m2,...
## AES-128 raw encryption for each block which includes IV
![AES-CBC-128-IV](https://private-user-images.githubusercontent.com/30307543/372443084-55dbee1a-7f7e-4f9e-a46e-016f115fac47.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3Mjc3ODE5MTgsIm5iZiI6MTcyNzc4MTYxOCwicGF0aCI6Ii8zMDMwNzU0My8zNzI0NDMwODQtNTVkYmVlMWEtN2Y3ZS00ZjllLWE0NmUtMDE2ZjExNWZhYzQ3LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDEwMDElMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQxMDAxVDExMjAxOFomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTc4YmZkMWQyZDBiNjIxMjhhZDQ4NDcyMWJlNjZlNDdiMTc2ZDJmMDZlZjdhYzZlYTdlYjdhNmVkYjIzMzkzNTcmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.HXSqeX0bYGrDFNl8B6cENWwHCNE8ZopqzQDCvkVjkDA)

# Decryption

## Decrypt all blocks
AES-CBC-128 will form the blocks of 16 bytes from the encrypted text then start decrypting each block. AES-CBC-128 requires the intial vector (``iv``) for the decryption process, with the full steps are:

```cpp
for (int i = 0; i < _encrypted_block.size(); i++) {
    _decrypted_txt[i] = block_decrypt(_encrypted_block[i]);

    for (int j = 0; j < BLOCK_SZ; j++) {
        if (i == 0) {        
            _decrypted_txt[i][j] = _decrypted_txt[i][j] ^ iv[j];
        } 
        else {
            // As using CBC-128, just only after XORing with _encrypted_block[i-1],
            // _decrypted_txt can turn back to its plain text
            _decrypted_txt[i][j] = _decrypted_txt[i][j] ^ _encrypted_block[i-1][j];
        }
    } 
}
```
After decrypting each block, the decrypted text is XORed with:
* iv for the 0-index block
* The previous encrypted block
This XORing operation of _decrypted_txt will result in the original plain text.

The above decryption process results in the PKCS#7 padding value which are need to be removed. It's important to note that **there is no way to decrypt the encrypted message to get the original PKCS#7 padding** (i.e PKCS#7 plain text padding).

PKCS#7 padding stores the total padding value in the last bytes of the decrypted text. So to remove this padding, simple get the last byte value from the decrypted text to known how many bytes to be removed from the last byte index.

## Decrypt each block

To decrypt each block, (function ``block_decrypt()``), total 11 keys are required: 10 rounds key (index 9 to 0) + original encryption key. The steps will be:

1. **Initial round key with key 10th** (index 9): Add round key between the encrypted hex with the 10th round key
2. 9 decryption rounds with key from 9th to 1 (index 8 to 0):
* **Inverse shift row**: The inverse step for the shift row operation in encryption. This step will left rotate the rows.
* **Inverse substitution box**: The inverse step for the substitution box in encryption. To avoid reversing the S-box which results in high time complexity (by seaching inside the 16x16 array), we use a constant 16x16 array
* Add round key between the state array and the ith round key
* Inverse mix column by Galoise multiplying matrix between the inverse_mix_column and the state array. This step calls ``multiply_matrices()`` (to multiply matrix) and ``aes_gf_mult()()`` (for GF(2^8) multiplication) functions which is the same with the encryption process. ``multiply_matrices()`` will multiply the ``inverse_mix_column`` and the state array, where ``inverse_mix_column`` is the matrix defined specifically for the decryption process (just like ``mix_column`` matrix is defined specifically for the encryption process).

3. Call **Inverse shift row** and **Inverse substitution box** for the outputed state arrays
4. Add round key between the outputed state array from step 3. with the original encryption key.