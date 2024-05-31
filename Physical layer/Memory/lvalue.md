# Define
**lvalue** or **lvalue reference**, which is defined with **&**, e.g **int &a**, stores the address of another variable.

By using ``&b`` reference declaration, ``&b`` will store the address of ``a`` (as ``&a``). As ``b`` is declared as lvalue reference, it becomes an alternative name for ``a``.

```cpp
int a = 9;
int &b = a;
std::cout << a << " " << b << std::endl; //9 9
std::cout << &a << " " << &b << std::endl;//0x72fe04 0x72fe04
```

From this example, we can see that the lvalue reference (``&b``) shares the same memory address of the variable it presents (``&a``).

Reference declaration for ``std::string`` must be [const reference](const%20reference.md):

```cpp
const std::string& str = "Hello, World !";//Must define as const reference
cout << str << endl;//Hello, World !
cout << &str << endl;//0x4d5060
```

## NULL initialization is not allowed in lvalue
As lvalue reference is an alternative name of a variable it present, ``NULL`` initialization is not allowed.
```cpp
int &b;//Must not do this, this gives compilation error
```
Or this:
```cpp
int &b = NULL;//Must not do this, this gives compilation error
```
This is different from pointer as pointer allow [NULL pointer](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Memory/Pointer/Types%20of%20pointer.md#null-pointer).
## Change lvalue
By using the lvalue, we can also change the value of the variable pointing to that lvalue. In this case variable ``a`` changes its value as it points to ``&b``
```cpp
int a = 9;
int &b = a;
std::cout << a << " " << b << std::endl; //9 9
std::cout << &a << " " << &b << std::endl;//0x72fe04 0x72fe04
int c = 10;
b = c;
std::cout << a << " " << b << std::endl; //10 10
std::cout << &a << " " << &b << " " << &c << std::endl;//0x72fe04 0x72fe04 0x7fffaa
```
## Can't assign const to lvalue
```cpp
const int a = 9;
int &b = a;//Compilation error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers 
```
# Pass by reference: lvalue as function argument
```cpp
#include <iostream>

using namespace std;

int number = 8;
int &lval = number;
void add_value(int& a)
{
	a += 1;
    return;
}

int main(){
    printf("number: %d\n", number);//8
    printf("lval: %d\n", lval);//8

    /*
        Calling add_value(number) will treat the paramter as
        int &a = number;
    */
    add_value(number);
    printf("number: %d\n", number);//9
    printf("lval: %d\n", lval);//9

    add_value(lval);//As &lval is number, so changing it will change number
    printf("number: %d\n", number);//10
    printf("lval: %d\n", lval);//10
}
```
Base on this example, we can see that by using lvalue reference, we pass the variable directly to function:
```cpp
int number = 8;
void add_value(int& a);
add_value(number);
```
This is different from passing by pointer as we have to [pass the address of the variable to the function](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Memory/Pointer/Implementations.md#change-value-of-variable-by-pointer-in-a-function)

# Return lvalue for a function
```cpp
int& func(){
    int a = 456;
    int &b = a;
    return b;
}

int main(){
	int a = func();
	std::cout << a << std::endl;//456
    int &b = func();
    std::cout << b << std::endl;//456
}
```
Assign value to a lvalue returned function to change a global variable:
```cpp
int a = 123;

int& func(){
    return a;
}

int main(){
    std::cout << a << std::endl;//123
	func() = 456;
	std::cout << a << std::endl;//456
}
```
# lvalue function with pass by reference

```cpp
int &func(int *a){
    int &b = *a;
    return b;
}

int main(){
    int a = 123;
    int &c = func(&a);
    cout << &a << " " << &c << std::endl; //0x7ffd31a69acc 0x7ffd31a69acc
    cout << c << endl;// 123
}
```

# lvalue function with pass by value

```cpp
int &func(int a){
    int &b = a;
    return b;
}

int main(){
    int a = 123;
    int &c = func(a);
    cout << &a << " " << &c << std::endl; //0x7fff0aa5179c 0x7ffcb4797cdc
    cout << c << endl;//Garbage value
}
```
That happen as ``a`` variable passed to ``func()`` is passed by value, so `` b`` in ``int &b = a`` inside ``func()`` is set with the garbage value.
# lvalue as class object

```cpp
#include <iostream>
class classTest{
	public:
		int publicNumber = 10;
		void hello(){
			std::cout << "Hello World \n";
		}
	private:
		int privateNumer = 20;
};

int main(){
	classTest object;
	classTest &obj_lval = object;

	obj_lval.hello(); //Hello World
	std::cout << obj_lval.publicNumber << std::endl; //10
}
```
# Choosing between passing by pointer and passing by lvalue reference in C++ 

As lvalue reference is supported in C++, we still need to use pointer for a variable when this variable needs:
* Address updated
* Set to NULL
# Applications
* [Suspend and resume threads by OOP](../Thread/README.md#suspend-and-resume-threads): [suspend_thread](../Thread/suspend_and_resume_threads_oop.cpp#L23) and [resume_thread](../Thread/suspend_and_resume_threads_oop.cpp#L18) methods must be defined by lvalue.
* [To change value of a vector as a function argument, lvalue must be used](https://github.com/TranPhucVinh/Cplusplus/blob/master/Data%20structure/Vector/Vector%20and%20function.md#vector-as-function-argument)
