# Define

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
# lvalue function

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

## lvalue function with pass by reference

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

## lvalue function with pass by value

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
