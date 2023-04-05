# Define

lvalue reference is defined with ``int &``

By using ``&b`` reference declaration, ``&b`` will store the address of ``a`` (as ``&a``). As ``b`` is declared as lvalue reference, it becomes an alternative name for ``a``.

```cpp
int a = 9;
int &b = a;
std::cout << a << " " << b << std::endl; //9 9
std::cout << &a << " " << &b << std::endl;//0x72fe04 0x72fe04
```

From this example, we can see that the lvalue reference (``&b``) shares the same memory address of the variable it presents (``&a``).

Reference declarion for ``std::string``:

```c
const std::string& str = "Hello, World !";//Must define with const
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
## lvalue reinitialization is not allowed
```c
int a = 9;
int &b = a;
std::cout << a << " " << b << std::endl; //9 9
std::cout << &a << " " << &b << std::endl;//0x72fe04 0x72fe04
int c = 10;
&b = c;//Compilation error; reinitialization for lvalue is not allow
```
# std::string as lvalue reference

```c
//For passing const string, use const std::string
void const_str(const std::string& const_str)
{
    cout << const_str;
    return;
}

void lval_ref_str(std::string &str){
    cout << str;
    return;
}

int main(){
    string str = "lvalue reference string\n";
    const_str("Hello, World !\n");//Passing const string Hello, World !
    lval_ref_str(str);
}
```

# lvalue reference as pass by reference

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
```c
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
    int &c = func();
    cout << c << endl;//456
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
