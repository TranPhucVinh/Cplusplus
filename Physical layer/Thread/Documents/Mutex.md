# One thread function handler to increase a shared value

Solve the [one thread function handler to increase a shared value](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Thread/Race%20condition.md#one-thread-function-handler-to-increase-a-shared-value).

## Use std::mutex::lock()

**Program**: [mutex_lock.cpp]()

## Use std::mutex::try_lock()

In [one thread function handler to increase a shared value](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Thread/Race%20condition.md#one-thread-function-handler-to-increase-a-shared-value), if **mutex::try_lock()** fails to lock the mutex, the thread will handle other task, which results in failing to increase the shared value to **RANGE**:

```cpp
void thread_func()
{
    for (int i = 0; i < RANGE; i++) {
		if (_mutex.try_lock()){
            share_value++;
            _mutex.unlock();
        } else printf("Fail to lock mutex\n");
	}
}
// Other operations are like One thread function handler to increase a share value
```
**Result**:

```
...
Fail to lock mutex
Fail to lock mutex
shared_value after executing 2 threads: 1987206 // Expected: 2000000
```
## Use timed mutex [try_lock_for()]()

```cpp
std::timed_mutex tm;
void thread_func()
{
    for (int i = 0; i < RANGE; i++) {
		if (tm.try_lock_for(std::chrono::seconds(1))){
            share_value++;
            tm.unlock();
        } else printf("Fail to lock mutex\n");
	}
}
//Other operations are like One thread function handler to increase a share value
```
**Result**: ``share_value after executing 2 threads: 2000000``
## Use timed mutex try_lock_until()
Work like [try_lock_for()](#try_lock_for), but the wait time is set from current time.
```cpp
std::timed_mutex tm;
void thread_func()
{
	auto now=std::chrono::steady_clock::now();
	for (int i = 0; i < RANGE; i++) {
		if (tm.try_lock_until(now + std::chrono::seconds(10))){
            share_value++;
			tm.unlock();
        } else printf("Fail to lock mutex\n");
	}
}
//Other operations are like One thread function handler to increase a share value
```
## Use lock_guard
**Resource Acquisition Is Initialization**, abbreviated **RAII**, is a C++ programming technique which binds the life cycle of a resource that must be acquired before use, like locked mutex.

The class ``lock_guard`` is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex for the duration of a scoped block. The ``lock_guard`` lock of the mutex will be automatically remove when goes out of the scope.

```cpp
#include <mutex>

std::mutex _mutex;

int share_value;

void thread_func()
{
	std::lock_guard<std::mutex> lock(_mutex);
  for (int i = 0; i < RANGE; i++) share_value++;
}
//Other operations are like One thread function handler to increase a share value
```
**Result**: ``share_value after executing 2 threads: 2000000``

## Use std::unique_lock

Use ``unique_lock`` to solve the [One thread function handler to increase a share value](Race%20condition.md#one-thread-function-handler-to-increase-a-share-value) issue:

**Program**: [mutex_unique_lock.cpp](../src/mutex_unique_lock.cpp)

**Result**: ``share_value after executing 2 threads: 6000000``

For ``unique_lock``, we don't need to call ``.unlock()`` as the mutex is automatically unlocked when the ``unique_lock`` object goes out of its scope.
# Condition variable
## One thread unblocks another thread
In this example, after increasing the ``share_value`` to its ``RANGE``, thread 1 will set ``thread_2_run`` to allow thread 2 to run. Thread 2 will wait for ``thread_2_run`` then increases the ``share_value`` to ``RANGE``. This example is quite similar to [One thread function handler to increase a share value issue](Race%20condition.md#one-thread-function-handler-to-increase-a-share-value), except it has the flag ``thread_2_run`` to block thread 2 from running.

**Program**: [mutex_one_thread_fails_to_unblock_another_thread.cpp](../src/mutex_one_thread_fails_to_unblock_another_thread.cpp)

**Result**:

```
Thread 2 isn't ready to run
Thread 2 isn't ready to run
// Loop forever
```

**Problem solved**: We can use the following condition variable to solve that problem
* ``void std::condition_variable::wait(std::unique_lock<std::mutex>& lock)``
* ``void wait(std::unique_lock<std::mutex>& lock, Predicate stop_waiting)``
* ``std::condition_variable::wait_for()``

## ``void std::condition_variable::wait(std::unique_lock<std::mutex>& lock)``

```cpp
void std::condition_variable::wait(std::unique_lock<std::mutex>& lock);
```

``wait()`` causes the current thread to block until the condition variable is notified or a spurious wakeup occurs.

**Program**: [condition_variable_wait.cpp](../src/condition_variable_wait.cpp)

## ``void wait(std::unique_lock<std::mutex>& lock, Predicate stop_waiting)``
```cpp
template<class Predicate>
void wait(std::unique_lock<std::mutex>& lock, Predicate stop_waiting);
```
This type of ``wait()`` function can be used to return a variable
```cpp
//Other parts are like in void wait(std::unique_lock<std::mutex>& lock) example
void thread_func_1()
{
    for (int i = 0; i < RANGE; i++) {
		std::unique_lock<std::mutex> thread1_lock(_mutex);
		share_value++;
    }   
	cv.notify_one();
    thread_2_run = 1;
}

void thread_func_2(){
	printf("Thread 2 isn't ready to run\n");
	std::unique_lock<std::mutex> thread2_lock(_mutex);
	cv.wait(thread2_lock, []{ return thread_2_run;});
    for (int i = 0; i < RANGE; i++) {
        share_value++;
    }
}
```
## ``std::condition_variable::wait_for()``

```cpp
//Other parts are like in void wait(std::unique_lock<std::mutex>& lock) example
void thread_func_2(){
	printf("Thread 2 isn't ready to run\n");
	std::unique_lock<std::mutex> thread2_lock(_mutex);
	int ready = cv.wait_for(thread2_lock, std::chrono::seconds(1), []{ return thread_2_run;});
	if (ready){
		printf("Thread 2 is ready now\n");
		for (int i = 0; i < RANGE; i++) {
	        share_value++;
	    }
	} else printf("Thread 2 hasn't been ready in after 1 second waiting\n");
}
```
**Result**
```
Thread 2 isn't ready to run
Thread 2 is ready now
share_value after executing 2 threads: 2000000
```
# Recursive mutex
Recursive mutex is a mutex that may be locked multiple times by the same process/thread, without causing a deadlock.

In this example, where 2 threads count down from a number with thread_odd only prints odd numbers and thread_even only prints even numbers, and both of those threads are defined recursively, a recursive mutex is mandatorily used.

Program: [recursive_mutex_threads_print_odd_and_even_numbers.c](../src/recursive_mutex_threads_print_odd_and_even_numbers.cpp)
