AES a symmetric block cipher that can process data blocks of 128 bits (16 bytes), using cipher keys with lengths of 128, 192, and 256 bits, which comes into the term of AES-128, AES-192 and AES-256 to indicate the length of the key.

With the message to be encrypted by AES smaller than 16 bytes, padding technique is required.

# Raw AES encryption
Flowchart

```mermaid
flowchart TB
    A["Plain text"] --> B1["State array"] --> B2["Add round key"] --> C["SubBytes"] --> D["ShiftRows"] --> E["MixColumns"] --> F["Add round key"] -- "9 main rounds" --> C
    F --> G["SubBytes"] --> H["ShiftRows"] --> I["Add round key"] --> J["Encrypted text"]
	EN["Encryption key"] -- "⊕" --> B1
    R1["Round key i {i = 0 to 8}"] -- "⊕" --> F
    R2["Round key 9 "]  -- "⊕" --> I
```
⊕: XOR operation

**Step by step**: [Raw encryption steps](Raw%20encryption%20steps.md)
# AES encryption mode
AES encryption in real life application isn't raw ecryption but goes with encryption modes instead. They are **CBC** (Cipher Block Chaining) and **ECB** (Electronic Codebook).
