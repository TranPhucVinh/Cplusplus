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
std::cout << b << std::endl;
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
}
```

# Pointer

* [nullptr]()
* [Pointer object of a class]()
* [uintptr_t]()

# lvalue

* [lvalue reference as pass by reference](lvalue.md#lvalue-reference-as-pass-by-reference)
* [lvalue function with pass by reference](lvalue.md#lvalue-function-with-pass-by-reference)
* [lvalue function with pass by value](lvalue.md#lvalue-function-with-pass-by-value)

# rvalue
