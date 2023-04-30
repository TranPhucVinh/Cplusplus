# [Fundamental concepts](Fundamental%20concepts.md)

``class thread`` is available since C++11.

Compile: ``g++ main.cpp -std=c++11 -pthread``

```cpp
#include <thread>
std::thread thread_object(callback);
```

* [Create a simple thread](Fundamental%20concepts.md#create-a-simple-thread)
* [Thread function with argument](Fundamental%20concepts.md#thread-function-with-argument): [Thread function with one argument](Fundamental%20concepts.md#thread-function-with-multiple-arguments) and [Thread function with multiple arguments](Fundamental%20concepts.md#thread-function-with-multiple-arguments)
* [Delay inside thread](Fundamental%20concepts.md#delay-inside-thread)

## Suspend and resume threads

Just like GCC, G++ pthread doesn't have functions to suspend and resume thread. Suspend and resume features must be implemented by [mutex](Race%20condition.md#stdmutex) and [conditional variable](Condition%20variable.md).

To suspend and resume between 2 threads in functions with no specific class object, check [suspend_and_resume_threads_raw_functions.cpp](suspend_and_resume_threads_raw_functions.cpp).

# [Race condition](Race%20condition.md)
**Race condition issue**: [One thread function handler to increase a share value](Race%20condition.md#one-thread-function-handler-to-increase-a-share-value)

[std::mutex](Race%20condition.md#stdmutex) for **One thread function handler to increase a share value** issue: 
* [std::mutex::lock()](Race%20condition.md#lock)
* [std::mutex::try_lock()](Race%20condition.md#try_lock)

[Timed mutex](Race%20condition.md#timed-mutex) for **One thread function handler to increase a share value** issue: 
* [std::timed_mutex::try_lock_for()]()

[lock_guard](Race%20condition.md#lock_guard) for **One thread function handler to increase a share value** issue.

[Condition variable](Condition%20variable.md): [2 threads with mutex where thread 1 allows thread 2 to run](Condition%20variable.md#2-threads-with-mutex-where-thread-1-allows-thread-2-to-run) and APIs
