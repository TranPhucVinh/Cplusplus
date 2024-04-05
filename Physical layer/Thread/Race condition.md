# One thread function handler to increase a shared value

```cpp
#include <iostream>
#include <thread>

#define RANGE 1000000

int shared_value;

void thread_func()
{
    for (int i = 0; i < RANGE; i++) shared_value++;
}

int main()
{
    std::thread thread_1(thread_func), thread_2(thread_func);
    thread_1.join();
	thread_2.join();
	printf("shared_value after executing 2 threads: %d\n", shared_value);
    return 0;
}
```
**Result**: ``share_value after executing 2 threads: 1053188`` (expected ``2000000``)

# [std::mutex](Mutex.md)

Use [std::mutex::lock](Mutex.md#lock) for [one thread function handler to increase a shared value](#one-thread-function-handler-to-increase-a-shared-value).

# std::atomic

An atomic operation is an indivisible operation. CPP atomic provides atomic types and operations that ensure safe access to variables, preventing data races and potential issues in multithreaded code, allowing threads to access and modify variables safely, without explicit locks or synchronization mechanisms.

Use std::atomic for [one thread function handler to increase a shared value](#one-thread-function-handler-to-increase-a-shared-value):

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
# std::promise and std::future

* **std::promise** is a template class that allows you to store a value or an exception that will be made available in the future.
* **std::future** is a template class that represents a value that may not be available yet but will be available at some point in the future.

In this example, t2 will wait for 5 seconds to get the "future" value ``futureObj`` from ``t1``:
```cpp
#include <iostream>
#include <thread>
#include <future>

int main() {
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();

    std::thread t1([&promiseObj]() {
        // Simulating some computation
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        promiseObj.set_value(42);
    });

    std::thread t2([&futureObj]() {
        // This line could potentially block forever
        int result = futureObj.get();
        std::cout << "Result from future: " << result << std::endl;
    });

    t1.join();
    t2.join();

    return 0;
}
```
