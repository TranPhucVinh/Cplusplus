# nullptr

``nullptr`` is NULL pointer and is available since C++11.

```cpp
int *ptr = nullptr;
int a = 123;

ptr = &a;
std::cout << *ptr;//123
```

# Pointer object of a class

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int public_number = 10;
		void hello(){
			cout << "Hello World \n";
		}
};

int main(){
	classTest *pointer_object, object;
	pointer_object = &object;
	pointer_object->hello(); //Hello World
	cout << pointer_object->public_number << endl; //10
}
```

**Note**: Pointer object of a class must be mapped to an object of that class. If not mapping, this pointer object will be a wild pointer and can't access the variable value of that object (cause **Segmentation fault** error)

```cpp
//This cause Segmentation fault error and must not be done
classTest *pointer_object;
cout << pointer_object->public_number << endl;//Segmentation fault
```

# lvalue reference

lvalue reference is defined with ``int &``

By using ``&b`` reference declaration, ``&b`` will store the address of ``a`` (as ``&a``).

```cpp
int a = 9;
int &b = a;
std::cout << a << " " << b << std::endl; //9 9
std::cout << &a << " " << &b << std::endl;//0x72fe04 0x72fe04
```

Reference declarion for ``std::string``:

```c
const std::string& str = "Hello, World !";//Must define with const
cout << str << endl;//Hello, World !
cout << &str << endl;//0x4d5060
```

**Note**: ``int &b`` can't be defined without referencing to any lvalue like this

```cpp
int &b;//Define without referencing to any lvalue
```

This will cause error:

```
main.cpp:29:6: error: 'b' declared as reference but not initialized
```

## Change value of variable by lvalue reference

```cpp
int number = 8;
int add_value(int& a)
{
	return a+1;
}

int main(){
   printf("number: %d\n", number);//8

    /*
        Calling add_value(number) will treat the paramter as
        int &a = number;
    */
   printf("number: %d\n", add_value(number));//9
}
```
# rvalue reference

rvalue reference is unofficially called as double address operator. rvalue reference can be defined with ``int &&`` and ``int &&a``.

``&&`` is new in C++11. ``int&& a`` means "a" is an r-value reference.

Compile: ``g++ main.c -std=c++11``

```c
#include <stdio.h>

int main()
{
    int&& a = 1;//Define with int&&   
    int &&b = 2;//Define with int &&
    printf("a: %d, &a: %d\n", a, &a);//a: 1, &a: 6487560
    printf("b: %d, &b: %d\n", b, &b);//b: 2, &b: 6487564
}
```

Calling ``&&a`` will result in error:

```cpp
printf("&&a: %d", &&a);//This will result in error
printf("&&b: %d", &&b);//This will result in error
```
**Error**

```
main.c:13:25: error: label 'a' used but not defined
main.c:14:25: error: label 'b' used but not defined
```

Double address operator as function argument: As double address is intended for rvalue, so the value passing to it must be rvalue

```c
#include <stdio.h>

int func(int&& a)
{
    return a+1;
}

int main()
{   
    int a = 4;
    printf("%d\n", func(3));//4
    printf("%d\n", func(a-0));//5
    printf("%d\n", func(a+1));//6
}
```

# uintptr_t

``uintptr_t`` is used to convert a pointer to integer. ``uintptr_t`` is ``unsigned __int64``.

```cpp
int a = 9;
uintptr_t *b = (uintptr_t*) &a;
std::cout << &a << " " << b << std::endl; //0x72fe14 0x72fe14
```

``uintptr_t`` can't be used to get the value of the pointer.

```c
//With define like above
std::cout << *b << " " << std::endl; //3236750919781, not 9 as value of variable a
```

**Note**: If defining pointer like this, there will be error

```cpp
uintptr_t *c = &a;
```

## Change value of variable by uintptr_t

Using ``uintptr_t*``:

```cpp
#include <stdio.h>
#include <stdint.h>

int a = 8;

int add_value(uintptr_t *a)
{
	return *a+1;
}

int main(){
   printf("a: %d\n", a);//8
   printf("a: %d\n", add_value((uintptr_t*)&a));//9
}
```

Using ``uintptr_t&``:

```cpp
int a = 8;
int add_value(uintptr_t &a)
{
	return a+1;
}

int main(){
   printf("a: %d\n", a);//8
   printf("a: %d\n", add_value((uintptr_t&)a));//9
}
```
