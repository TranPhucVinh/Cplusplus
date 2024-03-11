# binary
CPP supports bitset library to implement binary conversion
```cpp
#include <bitset>
#define SZ 3 // Total bits in bit set
std::bitset<SZ> int_val = 4; // std::bitset<std::size_t N> with N is a constant
cout << int_val << endl;//100 (0b100)

constexpr int b = 3;// Use constexpr to set constant to std::size_t N of std::bitset
std::bitset<b> int_val = 2;
cout << int_val << endl;//010 (0b010)
```
Note: **std::size_t N** must alwasy be const, **std::bitset()** doesn't support variable size

**std::bitset()** will be useful when converting a negative number to binary when specifying the range of bit "1" for two's complement:
```cpp
std::bitset<32> int_val = -15;
cout << int_val << endl;// 11111111111111111111111111110001
```
**std::bitset()** has **to_string()** to convert its value to **std::string**:
```cpp
std::bitset<32> int_val = 1;
cout << int_val.to_string() << endl;
```
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
**Implementation**: Given two binary strings a and b, return their sum as a binary string.

If implementing this with **stoull()** to conver the string to binary them start adding 2 number, there will be a limited with a very long binary string like:
```
a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101"
b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"
```
The solution for this is to appending the returned string after performing the adding rule of binary value. Source code: [add_binary.cpp](add_binary.cpp)
# hex

## Print out a hex value

```c
#include <iostream>

using namespace std;

int a = 11;
int main() {
    cout << hex << 10 << endl;//a
    cout << hex << a << endl;//b
}
```
Or define:

```cpp
cout << std::hex << 10 << endl;
```

If define ``int hex = 100``, then there will be error: ``"hex" is ambiguous C/C++(266)``.

## Print out uint8_t value

```cpp
uint8_t value = 0x11;
cout << std::hex << value << endl; //Garbage character
```

This happens as ``std::hex`` requires printing out ``int`` value.

Problem solved:

```cpp
uint8_t value = 0x11;
cout << std::hex << static_cast<int>(value) << endl; //11
```
Please note that we use ``static_cast<int>`` only for printing out the value on ``std::hex``.
## Get first byte and last byte of a 2-byte int variable

```cpp
int value = 0x1234;
uint8_t lastByte = value;
uint8_t firstByte = value>>8;
cout << std::hex << lastByte << endl;//garbage_value
cout << std::hex << firstByte << endl;//garbage_value
cout << std::hex << static_cast<int>(lastByte) << endl;//34
cout << std::hex << static_cast<int>(firstByte) << endl;//12
cout << lastByte << endl;//garbage_value; Print out garbage_value as this is the parsing error of std::cout, use printf() instead
cout << firstByte << endl;//garbage_value; Print out garbage_value as this is the parsing error of std::cout, use printf() instead
printf("0x%x 0x%x\n", lastByte, firstByte);//0x34 0x12   
```

# dec

```c
int a = 0x11;

cout << dec << 9 << endl;//9
cout << dec << a << endl;//17
```

# oct

```c
int a = 0x11;

cout << oct << 9 << endl;//11
cout << oct << a << endl;//21
```
