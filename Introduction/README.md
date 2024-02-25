* Insertion operator: ``<<``
* Extraction operator: ``>>``
# Variables

## All ways to define a variable in CPP

Initialize with default value given by the environment:
```cpp
int var_1;
```
Implicit cast:
```cpp
int var_1 = 4;
```
[Initializer list](#initializer-list)
```cpp
int var_1{4};
```
Initialize with a value:
```cpp
int var_1(4);
```
Initialize var_1 by the value of var_2 as [copy constructor](https://github.com/TranPhucVinh/Cplusplus/blob/master/Object-oriented%20programming/Constructor%20and%20destructor/Constructor.md#copy-constructor):
```cpp
int var_1(var_2);
```
## Initializer list

Initializer list is a method to initialize a variable's value. Initializer list ``{}`` is only available from C++11 and above:

```cpp
#include <iostream>

int main()
{
    int value {};
    std::cout << value << std::endl;//0

	int number {123};
    std::cout << number << std::endl;//123
    return 0;
}
```
[Constructor initializer list](https://github.com/TranPhucVinh/Cplusplus/blob/master/Object-oriented%20programming/Constructor%20and%20destructor/Constructor.md#constructor-initializer-list)
# STL
STL is standard template library. It consists of three components:
* [Container](https://github.com/TranPhucVinh/Cplusplus/blob/master/Data%20structure/README.md#container)
* [Iterator](#interator)
* [Algorithms](https://github.com/TranPhucVinh/Cplusplus/tree/master/Algorithms)
## Iterator

An iterator is an object (like a pointer) that points to an element inside the container. We can use iterators to move through the contents of the container. 

Iterators are used to point at the memory addresses of STL containers.

Implementation: [Iterator in std::array](https://github.com/TranPhucVinh/Cplusplus/blob/master/Data%20structure/Array.md#iterator-in-stdarray)

# Header file

## hpp file

``.hpp`` file is header file like ``.h`` file. Its usage is identically to ``.h`` file.

Example: ``header.hpp``

```h
#include <iostream>
#ifndef header_hpp
#define header_hpp
//Other definitions go here
```

# Keywords

## constexpr

**constexpr** can be understood simply as a constant. **constexpr can't be used for [std::string](https://github.com/TranPhucVinh/Cplusplus/blob/master/Data%20structure/String/README.md#stdstring)**.

There are 2 difference between [const](https://github.com/TranPhucVinh/C/blob/master/Introduction/Keywords/README.md#const) and ``constexpr`` variables:

1. The initialization of a ``const`` variable can be deferred until run time, i.e the value of the ``const`` variable is sent to it at runtime. A ``constexpr`` variable must be initialized at compile time.

2. A ``constexpr`` variable can't be changed by pointer, not like [const (change value of a const by pointer)](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Memory/Pointer/Implementations.md#change-value-of-a-variable-with-pointer).

```c
#include <iostream>

volatile constexpr int x = 123;

int main()
{
	int *ptr;
	ptr = (int*)&x;
	printf("%d\n", x);//123
	*ptr = 456;
	printf("%d\n", x);//123, not changed to 456
	return 0;
}
```
## When must constexpr be used ?

* [When static member method requires a const char pointer as string](https://github.com/TranPhucVinh/Cplusplus/blob/master/Object-oriented%20programming/Method%20of%20class.md#static-member-methods)
## Naming convention for const and constexpr

As a naming convention suggestion, constants are written entirely in UPPER_CASE and use an underscore to separate words. This applies to variables that are constant at compile time and are allocated to static storage, and which would otherwise be pre-processor defines in C. The main areas of use are in [unnamed namespaces](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/Function/Namespace.md#unnamed-namespace) at the top of a file, as static constant class members, and as constant variables in functions.

For example:

```cpp
namespace
{
    constexpr int SOME_CONSTANT_VALUE = 5;
}

class Loader
{
    static const wchar_t* const DEFAULT_PATH;
};

void someFunction()
{
    constexpr int MAXIMUM_ITERATIONS = 15;
}
```
