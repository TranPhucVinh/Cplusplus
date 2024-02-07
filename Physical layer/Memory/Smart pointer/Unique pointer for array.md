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
# [Unique pointer array as function argument](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/Smart%20pointer/Unique%20pointer%20and%20function.md#unique-pointer-array-as-function-argument), using [template](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/Function/Template.md) so that array size is not hardcoded.
# Unique pointer for char array as string

```cpp
std::unique_ptr<char[]> strPtr{new char[40]};

strcpy(strPtr.get(), "Hello, World !");
std::cout << strPtr.get() << std::endl;//Hello, World !
```
