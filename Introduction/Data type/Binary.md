# bitset
CPP supports **bitset library** to implement binary conversion
## Create
```cpp
#include <bitset>
#define SZ 3 // Total bits in bit set
std::bitset<SZ> int_val = 4; // std::bitset<std::size_t N> with N is a constant
cout << int_val << endl;//100 (0b100), i.e int_val is displayed in the binary format of SZ = 3 characters 

constexpr int b = 3;// Use constexpr to set constant to std::size_t N of std::bitset
std::bitset<b> int_val = 2;
cout << int_val << endl; //010 (0b010)

const int c = 3;
std::bitset<c> val = 2;
cout << val << endl; //010 (0b010)
```
Note: **std::size_t N** must alwasy be const, std::bitset() **doesn't support variable size**.
## Read
``std::bitset`` is an array which allows access its member by index:
```cpp
#define SZ 3 // Total bits in bit set
std::bitset<SZ> int_val = 4;
cout << int_val[2] << " " << int_val[1] << " " << int_val[0] << endl;// 1 0 0
```
## Update
std::bitset() will be useful when **converting a negative number to binary** when specifying the range of bit "1" for two's complement:
```cpp
std::bitset<32> int_val = -15;
cout << int_val << endl;// 11111111111111111111111111110001
```
**Convert a binary bitset number to unsigned long**: Use ``to_ulong()``
```cpp
#define SZ 3 // Total bits in bit set

std::bitset<SZ> bin1 = 0b111, bin2("010");
cout << bin1.to_ulong() << " " << bin2.to_ulong() << endl;// 7 2
```
**std::bitset()** has **to_string()** to convert its value to **std::string**:
```cpp
std::bitset<32> int_val = 1;
cout << int_val.to_string() << endl;
```
To add 2 bitset numbers, they must be converted to int first:
```cpp
std::bitset<SZ> bin = 0b111;
std::bitset<SZ> shift_sz = 0b101;
cout << shift_sz.to_ullong() + bin.to_ullong() << endl;// 12
```
Bit shifting:
```cpp
#define SZ 3 // Total bits in bit set

std::bitset<SZ> bin = 0b111;
cout << (bin << 1) << endl;// 110 (0b110)
cout << (bin << 2) << endl;// 100 (0b100)
cout << (bin.to_ulong() << 1) << endl;// 14 = 0b1110
```
NOT bitwise
```cpp
#define SZ 3 // Total bits in bit set

std::bitset<SZ> int_val = 4;
cout << int_val << endl;// 100 (0b100)
cout << ~int_val << endl;// 100 (0b100)
cout << (~int_val).to_ullong() << endl;// 3
```
# Binary conversion
## Convert binary string to integer
Use [stoi()](https://github.com/TranPhucVinh/Cplusplus/blob/master/Data%20structure/String/string%20API.md#stoi)
## Convert decimal to binary/binary string
To **convert decimal to binary/binary string** in CPP, the only way to achieve that is to perform the conversion by looping calculation:
```cpp
string decToBinaryString(int dec_number) 
{ 
    string binary_string;
    while (dec_number > 0) { 
        binary_string += to_string(dec_number % 2);
        dec_number = dec_number/2; 
    } 

    // As we are forming the binary string by appending, so we need to reverse it
    reverse(binary_string.begin(), binary_string.end());
    return binary_string;
} 
```
# Implementation
Given two binary strings a and b, return their sum as a binary string.

If solving this problem by using **stoull()** to convert the string to binary then start adding them, this will not work with a very long binary string like this:
```
a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101"
b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"
```
The solution for this is to append the returned string after performing the adding rule of binary value. Source code: [add_binary.cpp](add_binary.cpp)
