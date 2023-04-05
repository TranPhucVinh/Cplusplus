# Memory functions

## memset()

Calling ``memset()`` of ``cstring``

```cpp 
#include <cstring>

char str[] = "C programming with GNU-GCC";
memset(str,'$',7); //$$$$$$$amming with GNU-GCC
```

Or

```cpp
char str[] = "C programming with GNU-GCC";
::memset(str,'$',7); //$$$$$$$amming with GNU-GCC
```

## std::move

Available since C+11: ``g++ main.cpp -std=c++11``

Allow the efficient transfer of resources. ``std::move()`` is used for [the function argument as a rvalue](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/lvalue%20and%20rvalue.md#rvalue-as-function-argument).

### A simple variable

```c
int a = 10;
int b = std::move(a);
std::cout << b << std::endl;//10
std::cout << a << std::endl;//10; after calling std::move(), variable a still keeps its value
```

### A class object

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int publicNumber;
		void hello(int val){
			cout << "Value: " << privateNumer + val << endl;
		}
	private:
		int privateNumer = 2;
};

int main(){
	classTest object_1, object_2;
	object_1.publicNumber = 1;
	cout << object_1.publicNumber << endl; //1
	object_1.hello(1);//Value: 3

	object_2 = std::move(object_1);

	cout << object_2.publicNumber << endl; //1
	object_2.hello(1);//Value: 3
	
	// After calling std::move(), object object_1 still keeps its value
	cout << object_1.publicNumber << endl; //1
	object_1.hello(1);//Value: 3
}
```

# [Pointer](Pointer.md)

* [nullptr](Pointer.md#nullptr)
* [Pointer as an object of a class, new keyword](../../Object-oriented%20programming/Fundamental%20concepts.md#define-variable-and-function-for-a-class-use-class-object-as-a-pointer)
* [uintptr_t](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/Pointer.md#uintptr_t): [Change value of variable by uintptr_t* and uintptr_t&](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/Pointer.md#change-value-of-variable-by-uintptr_t)
* [Smart pointer](Smart%20pointer): [Unique pointer](Smart%20pointer#Unique%20pointer.md), share pointer and weak pointer

# lvalue

* [lvalue define](): [NULL initialization]() and [reinitialization]() aren't allowed
* [lvalue reference as pass by reference](lvalue.md#lvalue-reference-as-pass-by-reference)
* [Return lvalue for a function]()
* [lvalue function with pass by reference](lvalue.md#lvalue-function-with-pass-by-reference)
* [lvalue function with pass by value](lvalue.md#lvalue-function-with-pass-by-value)
* [Choosing between passing by pointer and passing by lvalue reference in C++]()

# rvalue

* [rvalue concept, define rvalue](rvalue.md#define-rvalue)
* [rvalue as class object](rvalue.md#rvalue-as-class-object)
