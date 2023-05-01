# Create a simple thread

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
Multiple arguments can be passed into thread function handler:
```cpp
void thread_func(int num1, int num2, int num3, int num4)
{
    std::cout << num1 + num2 + num3 + num4 << std::endl;
}

int main()
{
    std::thread thread_obj(thread_func, 1, 2, 3, 4);
    thread_obj.join();
    return 0;
}
```
# Thread function with argument

## Thread function with one argument

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

## Thread function with multiple arguments

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

# Delay inside thread

Delay inside thread with ``sleep_for()`` and ``chrono``:

```cpp
void thread_func()
{
    while (1){
        std::cout << "Hello, World !" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::thread thread_obj(thread_func);
    thread_obj.join();
    return 0;
}
```
