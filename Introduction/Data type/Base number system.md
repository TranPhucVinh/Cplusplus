## hex

### Print out a hex value

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

### Print out uint8_t value

```cpp
uint8_t value = 0x11;
cout << std::hex << value << endl; //Garbage character
```

This happens as std::hex requires printing out ``int`` value.

Problem solved:

```cpp
uint8_t value = 0x11;
cout << std::hex << static_cast<int>(value) << endl; //11
```

Get first byte and last byte of a 2 byte int variable

```cpp
int value = 0x1234;
uint8_t lastByte = value;
uint8_t firstByte = value>>8;
cout << std::hex << static_cast<int>(lastByte) << endl;//34
cout << std::hex << static_cast<int>(firstByte) << endl;//12    
```

## dec

```c
int a = 0x11;

cout << dec << 9 << endl;//9
cout << dec << a << endl;//17
```

## oct

```c
int a = 0x11;

cout << oct << 9 << endl;//11
cout << oct << a << endl;//21
```