# Raw pointer
## [Dynamic memory allocation](Raw%20pointer/Dynamic%20memory%20allocation.md)
* [new](Raw%20pointer/Dynamic%20memory%20allocation.md#new) and [delete](Raw%20pointer/Dynamic%20memory%20allocation.md#delete)
* [memset()](Dynamic%20memory%20allocation.md#memset)
* [std::move](Dynamic%20memory%20allocation.md#stdmove): A simple variable, a class object

## [Pointer object](Raw%20pointer/Pointer%20object.md)

* [nullptr](Pointer.md#nullptr)
* [Pointer as an object of a class, new keyword](../../Object-oriented%20programming/Fundamental%20concepts.md#define-variable-and-function-for-a-class-use-class-object-as-a-pointer)
* [uintptr_t](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/Pointer.md#uintptr_t): [Change value of variable by uintptr_t* and uintptr_t&](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/Pointer.md#change-value-of-variable-by-uintptr_t)

# Smart pointer

Smart pointer is a wrapper of a raw pointer. Using smart pointer will automate the process of dynamic allocation then deallocation/free-up for pointer in the heap memory. The deallocation process when using smart pointer will help preventing memory leak.

There are 3 types of smart pointer in CPP:

* [Unique pointer](Unique%20pointer) (support since C++14)
* Shared pointer
* Weak pointer
# Reference
C only supports pointer while C++ supports pointers and reference ([lvalue reference](#lvalue) and [rvalue reference](#rvalue))
## [lvalue](lvalue.md)

* [lvalue define](): [NULL initialization]() and [reinitialization]() aren't allowed
* [lvalue reference as pass by reference](lvalue.md#lvalue-reference-as-pass-by-reference)
* [Return lvalue for a function]()
* [lvalue function with pass by reference](lvalue.md#lvalue-function-with-pass-by-reference)
* [lvalue function with pass by value](lvalue.md#lvalue-function-with-pass-by-value)
* [Choosing between passing by pointer and passing by lvalue reference in C++]()

## [rvalue](rvalue.md)

* [rvalue concept, define rvalue](rvalue.md#define-rvalue)
* [rvalue as class object](rvalue.md#rvalue-as-class-object)
## const reference