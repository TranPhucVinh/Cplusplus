# API

```cpp
#include <thread>
std::thread thread_object(callback);
```

# Implementations

## Create a simple thread

```cpp
#include <iostream>
#include <thread>

void thread_func()
{
    std::cout << "Hello, World !";
}

int main()
{
    std::thread thread_obj(thread_func);
    thread_obj.join();
    return 0;
}
```

## Thread function with argument

Thread function with one argument

```cpp
void thread_func(int int_arg)
{
    std::cout << "Int arg: " << int_arg;
}

int main()
{
    std::thread thread_obj(thread_func, 123);
    thread_obj.join();
    return 0;
}
```
**Result**

```
Int arg: 123
```

Thread function with multiple arguments

```cpp
void thread_func(int int_arg, std::string string_arg)
{
    std::cout << "Int arg: " << int_arg << std::endl;
    std::cout << "String arg: " << string_arg << std::endl;
}

int main()
{
    std::thread thread_obj(thread_func, 123, "Hello, World !");
    thread_obj.join();
    return 0;
}
```

```
Int arg: 123
String arg: Hello, World !
```