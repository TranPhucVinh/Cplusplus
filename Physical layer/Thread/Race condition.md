# 2 threads increase a shared variable

```cpp
#include <iostream>
#include <thread>

#define RANGE 1000000

int share_value;

void thread_func()
{
    for (int i = 0; i < RANGE; i++) share_value++;
}

int main()
{
    std::thread thread_1(thread_func), thread_2(thread_func);
    thread_1.join();
	thread_2.join();
	printf("share_value after executing 2 threads: %d\n", share_value);
    return 0;
}
```
**Result**: ``share_value after executing 2 threads: 1053188`` (expected ``2000000``)

# [std::mutex](Mutex.md)

Use std::mutex for [2 threads increase a shared variable issue]().

# std::atomic

An atomic operation is an indivisible operation. CPP atomic provides atomic types and operations that ensure safe access to variables, preventing data races and potential issues in multithreaded code, allowing threads to access and modify variables safely, without explicit locks or synchronization mechanisms.

Use std::atomic to solve the [2 threads increase a shared variable issue](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Thread/Race%20condition.md#2-threads-increase-a-shared-variable):

```cpp
#include <iostream>
#include <thread>
#include <atomic>

#define RANGE 1000000

std::atomic<int> shared_value;

void thread_func()
{
    for (int i = 0; i < RANGE; i++) shared_value++;
}

int main()
{
	shared_value = 0;// Must init value inside main(), not init globally
    std::thread thread_1(thread_func), thread_2(thread_func);
    thread_1.join();
	thread_2.join();
	std::cout << shared_value << std::endl;
    return 0;
}
```
**std::atomic_int** can also be used, as **std::atomic_int** is simply as typedef of **std::atomic<int>** 
```cpp
std::atomic_int shared_value; 
```
