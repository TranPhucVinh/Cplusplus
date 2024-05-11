# [Fundamental concepts](Fundamental%20concepts.md)

``class thread`` is available since C++11.

Compile: ``g++ main.cpp -std=c++11 -pthread``

```cpp
#include <thread>
std::thread thread_object(callback);
```

* [Create thread](Create%20thread.md): [Create a simple thread](Create%20thread.md#create-a-simple-thread), [create a thread inside a class]() and [create a thread with thread function handler as class method]()
* [Thread function with argument](Fundamental%20concepts.md#thread-function-with-argument): [Thread function with one argument](Fundamental%20concepts.md#thread-function-with-multiple-arguments) and [Thread function with multiple arguments](Fundamental%20concepts.md#thread-function-with-multiple-arguments)
* [Delay inside thread](Fundamental%20concepts.md#delay-inside-thread)
* [Thread is blocked by while(1)](Fundamental%20concepts.md##thread-is-blocked-by-while1), compare with the [corresponded issue in GCC PThread](https://github.com/TranPhucVinh/C/tree/master/Physical%20layer/Thread#thread-is-blocked-by-while1).

# Suspend and resume threads

Just like GCC, G++ pthread doesn't have functions to suspend and resume thread. Suspend and resume features must be implemented by [mutex](Race%20condition.md#stdmutex) and [conditional variable](Condition%20variable.md).

To suspend and resume between 2 threads without OOP, check [suspend_and_resume_threads_raw_functions.cpp](src/suspend_and_resume_threads_raw_functions.cpp). This program is intended for comprehensive and easy to understand the suspend and resume operation.

To suspend and resume between 2 threads with OOP, check [suspend_and_resume_threads_oop.cpp](suspend_and_resume_threads_oop.cpp). This program is intended for functions inheritance for other programs. [lvalue](../Memory/lvalue.md) is mandatorily used in this program to define [suspend_thread](suspend_and_resume_threads_oop.cpp#L23) and [resume_thread](suspend_and_resume_threads_oop.cpp#L18) methods. [Telemetry to ThingsBoard based on Internet status program](../../Application%20layer/thingsboard_telemetry_suspend_resume_by_internet_status.cpp) uses this mechanism.

# [Race condition](Documents/Race%20condition.md)
Race condition document includes: 
* [2 threads increase a shared variable](Race%20condition.md#2-threads-increase-a-shared-variable)
* [Mutex and condition variable](Documents/Mutex.md)
* **Semaphore**: ``semaphore`` library is only supported in C++20. Before that, GCC ``semaphore.h`` library is used in G++.
