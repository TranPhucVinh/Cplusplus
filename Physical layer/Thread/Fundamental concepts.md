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
# Thread is blocked by while(1)
Based on PThread program flow as [explained in GCC](https://github.com/TranPhucVinh/C/tree/master/Physical%20layer/Thread#thread-is-blocked-by-while1), ``str_thread`` in this program will block the program
```cpp
#include <iostream>
#include <thread>

void display_string(const char *str){
	while (1){
        std::cout << std::string(str) << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void display_int(int number){
	while (1){
        std::cout << number << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::thread str_thread(display_string, "Hello, World !");
	str_thread.join();
	std::thread int_thread(display_int, 123);
	int_thread.join();
    return 0;
}
```
**Result**
```
Hello, World !
Hello, World !
... (Only thread 1 runs, thread 2 doesn't run)
```
**Problem solved**: Call ``str_thread.join()`` and ``int_thread.join()`` at the same time:

```cpp
std::thread str_thread(display_string, "Hello, World !");
std::thread int_thread(display_int, 123);
str_thread.join();
int_thread.join();
```