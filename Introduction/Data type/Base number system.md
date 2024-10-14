# [Binary](Binary.md)
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
// This will not print out the hex value of uint8_t value
uint8_t value = 0x11;
cout << std::hex << value << endl; //Garbage character
```

This happens as ``std::hex`` requires printing out ``int`` value.

**Problem solved**:

```cpp
uint8_t value = 0x11;
cout << std::hex << static_cast<int>(value) << endl; //11
cout << std::hex << "0x" << static_cast<int>(value) << endl; // 0x11
```
Please note that we use ``static_cast<int>`` only for printing out the value on ``std::hex``. It must not be ``static_cast<uint8_t>`` for ``uint8_t value``:
```cpp
// This will not print out the hex value of uint8_t value
uint8_t value = 0x11;
cout << std::hex << "0x" << static_cast<uint8_t>(value) << endl; // Garbage value
```
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
# uint8_t 
**uint8_t** is a special integer type in CPP as std::cout will treat it as a character symbol when printing out. In order to print out the number value, use **unsigned()**:
```cpp
uint8_t val = 48;
std::cout << val << "\n";// Character '0'
std::cout << unsigned(val) << "\n";// 48
```
# dec

```c
int a = 0x11;

cout << dec << 9 << endl;//9
cout << dec << a << endl;//17
```
Adding number which is bigger than long long size will be impossible with ``+`` operator. A workaround for it is to convert them to string then start adding: [add_numbers_bigger_than_long.cpp](add_numbers_bigger_than_long.cpp)
# oct

```c
int a = 0x11;

cout << oct << 9 << endl;//11
cout << oct << a << endl;//21
```
