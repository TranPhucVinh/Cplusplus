# Initial step
## Form state array from the original plain text
The plain text is divided into blocks of 16 bytes, those block are called state or state array. The State consists of four rows of bytes, each containing Nb bytes, where Nb is the block length (in bits) divided by 32. For AES-128, Nb = 128/32 = 4

All array (state array from plain text, encryption keys, expansion key) which has the size of 16 bytes in AES-128 are written in the form of 2d array with the size of 4x4 with the **row-major to column-major order transformation** rule:

```cpp
for (int _row = 0; _row < _state_rows; _row++) {
    for (int _col = 0; _col < _nb; _col++) {
        vector_2d[_row][_col] = vector_1d[_row + 4*_col];
    }
}
```

E.g:

```c
vector<uint8_t> vec = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x7, 0x34};
```
will be:
```c
0x32 0x88 0x31 0xe0
0x43 0x5a 0x31 0x37
0xf6 0x30 0x98 0x7
0xa8 0x8d 0xa2 0x34
```

In this tutorial, we will call this in short as **column-major order**.

Before performing AES encryption, the state array is formed from the plain text by performing **column-major order** transformation.
## Prepare round keys for all rounds
As AES use 9 different encryption keys for 9 rounds of encryption (refer to step 2: 9 main rounds), so we have to prepare those keys, called round keys in this initial step.

Take this key as an example: 54 68 61 74 73 20 6D 79 20 4B 75 6E 67 20 46 75

The steps for all 9 round keys will be:

* w[0] = (54, 68, 61, 74),w[1] = (73, 20, 6D, 79),w[2] = (20, 4B, 75, 6E),w[3] = (67, 20, 46, 75)
* g(w[3]):
    • circular byte left shift of w[3]: (20, 46, 75, 67)
    • Byte Substitution (S-Box): (B7, 5A, 9D, 85)
    • Adding round constant (01, 00, 00, 00) gives: g(w[3]) = (B6, 5A, 9D, 85)
* w[4] = w[0] ⊕ g(w[3]) = (E2, 32, FC, F1)
* w[5] = w[4] ⊕ w[1] = (91, 12, 91, 88), w[6] = w[5] ⊕ w[2] = (B1, 59, E4, E6), w[7] = w[6] ⊕ w[3] = (D6, 79, A2, 93)

The round key output of those steps will be: E2 32 FC F1 91 12 91 88 B1 59 E4 E6 D6 79 A2 93
# Step 1: The first add round key
The original encryption key is transformed by the **column-major order** into a 2d vector, called ``encryption_key_2d``

The first add round key step will be XORing the state array (outputed from the initial step) and the ``encryption_key_2d``. The output of this step is also called ``state array``.

# Step 2: 9 main rounds

The state array outputed from "step 1 add round key" is the main round, which includes 4 smaller steps:

* Bytes substitution (SubBytes)
* Row shifting (ShiftRows)
* Mix columns (MixColumns)
* Add round key (AddRoundKey)

## Bytes substitution
Bytes substitution step is to replace the current value by the value of the AES substitution box.

AES-128 has the 16x16 array as a constatnt, known as the substitution box - ``sbox[16][16]``. ``_state_array`` with value ``0x12`` will have the value of ``s[0x1][0x2]`` (looked up from ``sbox`` with row = 0x1 and column = 0x2). So if ``_state_array[_row][_col] = 0x12``, it will be: ``_state_array[_row][_col] = 0xc9``.

## Row shifting
Row shifting in AES encryption is defined as right rotating x times the x th row, where x = 0 to 3. It means:
* Keep the 0th row
* Right rotate by 1 the 1st row
* Right rotate by 2 the 2nd row
* Right rotate by 3 the 3rd row
## Mix column
The mix column step is multiplying the 4x4 constant mix column encryption vector (named ``mix_column_encrypt``) with the state array outputed from step **Row shifting** in Galois field GF(2^8). Refer to those theory:
* Finite field
* Multiplication in GF(2^8) and their coding implementation
* Matricies multiplication in GF(2^8)
### Finite field

A finite field (also called a Galois field) is a mathematical structure with a finite number of elements where you can perform addition, subtraction, multiplication, and division (except by zero) while satisfying the field axioms. These axioms are:

* Closure: For any two elements in the field, their sum or product is also in the field.
* Associativity: Addition and multiplication are associative.
* Commutativity: Addition and multiplication are commutative.
* Distributivity: Multiplication distributes over addition.
* Identity elements: There are additive and multiplicative identity elements (0 and 1, respectively) in the field.
* Inverses: Every element has an additive inverse and every non-zero element has a multiplicative inverse.

The finite field with p^n elements is often denoted GF(p^n), where 𝑝 is a prime number. For instance, GF(2) consists of the elements {0, 1} with arithmetic done modulo 2.

Finite field is applied in CRC and crytography, e.g with symetric encrytion like AES. AES uses the GF(2^8) field.

### Multiplication in GF(2^8)

In Galois field, numbers are represented as polynomial. E.g $0x57 = x^6 + x^4 + x^2 + x + 1$

Generally, a number in Galois field will be represented as polynomial $A(x) = \Sigma_{i=0}^{n-1} a_i * x_i^i $

where $a_i$ is 0 or 1

In the polynomial representation, multiplication in GF(2^8) (denoted by •) corresponds with the multiplication of polynomials modulo an irreducible polynomial of degree 8. For the AES algorithm, this irreducible polynomial is $ 0x011b = x^8 + x^4 + x^3 + x + 1$.

Multiplying 0x57 and 0x83 in GF(2^8) will be: $ (x^6 + x^4 + x^2 + x + 1) • (x^7 + x + 1) = x^{13} + x^{11} + x^9 + x^8 + x^7 + x^7 + x^5 + x^3 + x^2 + x + x^6 + x^4 + x^2 + x + 1 = x^{13} + x^{11} + x^9 + x^8 + x^6 + x^5 + x^4 + x^3 + 1 $

All the adding in this multiplying are XORing, not arithmetic or binary adding or ORing. It means that XORing 2 same numbers result in 0, e.g $x^2 + x^2 = 0$

Then, reduce the result with modulo ``0x011b``:

$ (x^{13} + x^{11} + x^9 + x^8 + x^6 + x^5 + x^4 + x^3 + 1) modulo (x^8 + x^4 + x^3 + x + 1) = x^7 + x^6 + 1 $

So 0x57 • 0x83 = 0xc1

Algebra theory states that the modulo operation in Galoise Field is equal to the XORing one.

### Coding implementation for GF(2^8) multiplication

With $B(x) = \Sigma_{i=0}^{n-1} b_i * x_i^i $, then A(x) • B(x) = $ \Sigma_{i=0}^{n-1} A(x) * b_i * x_i^i $. The $\Sigma$ operation here is XORing, not arithmetic or binary adding or ORing.

If b_i = 1, this element will be $ A(x) * x_i^i $. This corresponds to a left shift of ``i`` bits.

With the lowest bit of b is 1, then ``multiplication result ^= A(x)``, i.e XOR A(x) with the result.

As there are only 8 bit in each multiplying number, we automate the process above by the for loop with the iteration of 8:
* (1) At first, if the lowest bit of b is 1, then ``multiplication result ^= A(x)``, i.e XOR A(x) with the result.
* (2) Check if the most significant bit of A(x) is set in order to perform reducing with modulo, marked this as carry
* (3) Left shift A(x) by i bit for each iteration
* (4): In order to perform step (1) as this step only cares the lowest bit, right shift b by 1 to process the next bit
* (5): If carry was set, XOR a with 0x1b (which represents the irreducible polynomial)

Refer to ``aes_gf_mult()`` function in aes_128.cpp

### Matricies multiplication in GF(2^8)
For matricies multiplication in GF(2^8), keep the multiplication rule as [matrices multiplication in algebra](multiply_matrices.cpp), except using the GF(2^8) multiplication function (``aes_gf_mult`` in aes_128.cpp) then XORing all multiplication results (not adding like in algebra) (``multiply_matrices`` in aes_128.cpp).
## Add round key
Similar to **Step 1: The first add round key**, the AddRoundKey step in each of the 9 rounds will be XORing the state array outputed from the Mix column step and the round key of this round.

## Output of each round

The output of each round is sent to the next round as its input to make up totally 9 rounds. The output of round 9 (index 8), called state_array, is sent to ``step 4: Bytes substitution`` as its input

# Step 4: Bytes substitution
``Step 4: Bytes substitution`` is similar to the steps of the same name inside ``Step 3: 9 main rounds``. Its output is sent to ``step 5: Row shifting`` as the input
# Step 5: Row shifting
``Step 5: Row shifting`` is similar to the steps of the same name inside ``Step 3: 9 main rounds``. Its output is sent to ``step 6: Add round key`` as the input.
# Step 6: Add round key
Similar the previous Add round key steps, this step will XOR the state array outputed from Step 5: Row shifting and the 10th round key (index 9th). The output of this final step results in the AES encrypted message

Please note that Step 4, 5 and 6 are similar to the "9 main rounds" steps, except it doesn't include the Mix column step.
