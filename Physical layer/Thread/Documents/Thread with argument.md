# Thread function with one argument

```cpp
void thread_func(int int_arg) {
    std::cout << "Int arg: " << int_arg;
}

int main() {
    std::thread thread_obj(thread_func, 123);
    thread_obj.join();
    return 0;
}
```
**Result**

```
Int arg: 123
```

# Thread function with multiple arguments
Multiple arguments can be passed into thread function handler:
```cpp
void thread_func(int int_arg, std::string string_arg) {
    std::cout << "Int arg: " << int_arg << std::endl;
    std::cout << "String arg: " << string_arg << std::endl;
}

int main() {
    std::thread thread_obj(thread_func, 123, "Hello, World !");
    thread_obj.join();
    return 0;
}
```

```
Int arg: 123
String arg: Hello, World !
```
```cpp
void thread_func(int num1, int num2, int num3, int num4) {
    std::cout << num1 + num2 + num3 + num4 << std::endl;
}

int main() {
    std::thread thread_obj(thread_func, 1, 2, 3, 4);
    thread_obj.join();
    return 0;
}
```
# std::ref() for lvalue thread function argument
**std::ref()** is a function used to pass lvalue variable as an argument to CPP thread:
```cpp
void thread_func(int &a) {
    a += 1;
}

int main() {
    int a = 1;
    std::thread thread_obj(thread_func, std::ref(a));
    thread_obj.join();
    std::cout << a << std::endl;// 2
    return 0;
}
```
