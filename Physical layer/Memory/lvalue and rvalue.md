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

## lvalue reference as pass by reference

```cpp
int number = 8;
void add_value(int& a)
{
	a += 1;
    return;
}

int main(){
    printf("number: %d\n", number);//8
    /*
        Calling add_value(number) will treat the paramter as
        int &a = number;
    */
    add_value(number);
    printf("number: %d\n", number);//9
}
```
## lvalue function

```cpp
int& func(){
    int a = 456;
    int &b = a;
    return b;
}

int main(){
    int &c = func();
    cout << c << endl;//456
}
```

lvalue function with pass by reference

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

lvalue function with pass by value

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

## rvalue as class object

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int publicNumber = 10;
		void hello(){
			cout << "Hello, World !\n";
		}
};

int main(){
    classTest &&rval_object = classTest();
    rval_object.hello();//Hello, World !
    cout << rval_object.publicNumber << endl; //10
}
```
	
## rvalue as function argument

For rvalue as function argument, the value passing to it must be rvalue

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
Use ``std::move()`` to be more efficient, instead of using ``func(a-0)``:

```cpp
printf("%d\n", func(std::move(a)));
```
