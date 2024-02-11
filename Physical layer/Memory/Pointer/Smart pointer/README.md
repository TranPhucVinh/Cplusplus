Smart pointer is a wrapper of a raw pointer. Using smart pointer will automate the process of dynamic allocation then deallocation/free-up for pointer in the heap memory. The deallocation process when using smart pointer will help preventing memory leak.

Smart pointer includes: 
* [Unique pointer](#unique-pointer)
* [Shared pointer]()
* Weak pointer

# [Unique pointer]()

* [Fundamental concepts](Unique%20pointer.md#fundamental-concepts)
* [Unique pointer allows setting value to its deferencing](Unique%20pointer.md#unique-pointer-allows-setting-value-to-its-deferencing)
* [Unique pointer doesn't allow sharing](Unique%20pointer.md#unique-pointer-doesnt-allow-sharing)
* [Using std::move to completely move value from 2 unique pointers](Unique%20pointer.md#using-stdmove-to-completely-move-value-from-2-unique-pointers)
* [Unique pointer as class object](Unique%20pointer.md#unique-pointer-as-class-object)
* [Function returns a unique pointer](Unique%20pointer%20and%20function.md#function-returns-a-unique-pointer)
* [Unique pointer as function argument](Unique%20pointer%20and%20function.md#unique-pointer-as-function-argument)
# [Shared pointer](Shared%20pointer.md)

# Custom deleter

As smart pointer automated the deallocation process, if we want to have our own function to handle the deallocation process, we need **custom deleter**.

For example in unique pointer, if we don't specify its custom deleter by declaring like this:
```cpp
std::unique_ptr<int> uniquePtr(new int(123));
```
The unique pointer default deleter function, **std::default_delete()** will be used.

To declare custome deleter:

```cpp
#include <iostream>
#include <memory>

using namespace std;

void custom_deleter(int *unique_ptr){
	delete unique_ptr;
	cout << "Custom deleter is called\n";
}

int main(){
	std::unique_ptr<int, void(*)(int*)> uniquePtr(new int(123), custom_deleter);

    std::cout << &uniquePtr << std::endl;
    std::cout << *uniquePtr << std::endl;//123
}
```
For ``auto``:
```cpp
auto uniquePtr = std::unique_ptr<int, void(*)(int*)>(new int(123), custom_deleter);
```
**Result**
```
0x7fff620953f0 
123
Custom deleter is called
```
