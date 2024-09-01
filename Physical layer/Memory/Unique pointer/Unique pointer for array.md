# Initialize directly
```cpp
std::unique_ptr<int[]> uniquePtr(new int[2]);

uniquePtr[0] = 123;
uniquePtr[1] = 456;

std::cout << &uniquePtr << std::endl;//0x7fff13475d50
std::cout << uniquePtr[0] << std::endl;//123
std::cout << uniquePtr[1] << std::endl;//456
```
# Initialize by std::make_unique
```cpp
std::unique_ptr<int[]> uniquePtr;
uniquePtr = std::make_unique<int[]>(2);

uniquePtr[0] = 123;
uniquePtr[1] = 456;
```
# 2D array
```cpp
#include <iostream>
#include <memory>

#define ROWS        2
#define COLUMNS     2

/*
    For 2D array naming convention, to view its member
    x: horizontal axis
    yL vertical axis
*/
int main() {
    std::unique_ptr<std::unique_ptr<int[]>[]> array_2d(new std::unique_ptr<int[]>[ROWS]);

    for (int x = 0; x < ROWS; x++) {
        array_2d[x] = std::make_unique<int[]>(COLUMNS);
    }

    int value = 0;
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLUMNS; y++) {
            array_2d[x][y] = value++;
        }
    }

    // Display the 2D array
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLUMNS; y++) {
            std::cout << array_2d[x][y] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```
# Unique pointer for char array as string

```cpp
std::unique_ptr<char[]> strPtr{new char[40]};

strcpy(strPtr.get(), "Hello, World !");
std::cout << strPtr.get() << std::endl;//Hello, World !

std::cout << sizeof(strPtr.get()) << std::endl;//8; must not use sizeof() to get size of strPtr.get()
std::cout << strlen(strPtr.get()) << std::endl;//14; must use strlen() to get size of strPtr.get()
```
# [Unique pointer array as function argument](Unique%20pointer%20and%20function.md#unique-pointer-array-as-function-argument), using [template](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/Function/Template.md) so that array size is not hardcoded.