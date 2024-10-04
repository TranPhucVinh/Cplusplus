**PKCS** (**Public Key Cryptography Standards**) **Cryptographic Message Syntax** (**CMS**) is a standard used for securely transmitting data through encryption, signing, authentication, and key management in cryptographic messages. CMS (Cryptographic Message Syntax) as defined in RFC 5652 is the successor to **PKCS#7**. PKCS#7 padding is more general, when compared to PKCS#5, and can be used with any block size between 1 and 255 bytes. This makes PKCS#7 suitable for modern block ciphers like AES, which uses a block size of 16 bytes (128 bits).

PKCS#5 specifically defines methods for secure password-based encryption and doesn't relate to CMS. PKCS#5 Padding is specifically designed for block ciphers with a block size of 8 bytes (64 bits) and isn't used in AES CBC.

**Cipher Block Chaining** (CBC) mode can be part of CMS (Cryptographic Message Syntax), specifically for encrypting content. In the CMS standard (RFC 5652), several symmetric encryption algorithms are supported, and CBC mode is one of the commonly used modes for block ciphers like AES and 3DES.

For AES-128 encryption with CBC mode, it's called AES-CBC-128. AES-CBC-128 include the AES raw encryption, padding and **Initialization Vector** (**IV**). Encryption steps will be:
* PKCS 7 padding
* Form message blocks with 16 bytes for each block
* AES-128 raw encryption for each block which includes IV
# PKCS 7 padding 
AES CBC assumes the plain text message input length is a multiple of k bytes, where k bytes is the block size. With AES-128, the block size is 16 bytes. So k is 16. With the input length is ``lth`` bytes, then, this message is padded at the trailing end with ``k-(lth mod k)`` bytes all having value ``k-(lth mod k)``.
# Form message blocks
After PKCS 7 padding steps, the plain text now is a multiple of 16 bytes. We have to form the message blocks with 16 bytes for each block. Message blocks will be marked as m0, m1, m2,...
# AES-128 raw encryption for each block which includes IV
![AES-CBC-128-IV](https://private-user-images.githubusercontent.com/30307543/372443084-55dbee1a-7f7e-4f9e-a46e-016f115fac47.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3Mjc3ODE5MTgsIm5iZiI6MTcyNzc4MTYxOCwicGF0aCI6Ii8zMDMwNzU0My8zNzI0NDMwODQtNTVkYmVlMWEtN2Y3ZS00ZjllLWE0NmUtMDE2ZjExNWZhYzQ3LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDEwMDElMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQxMDAxVDExMjAxOFomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTc4YmZkMWQyZDBiNjIxMjhhZDQ4NDcyMWJlNjZlNDdiMTc2ZDJmMDZlZjdhYzZlYTdlYjdhNmVkYjIzMzkzNTcmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.HXSqeX0bYGrDFNl8B6cENWwHCNE8ZopqzQDCvkVjkDA)
