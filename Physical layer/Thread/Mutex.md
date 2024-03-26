# std::mutex

## lock()

```cpp
void std::mutex::lock()
```

**lock()** will wait until the mutex is successfully locked. This function is similar to [pthread_mutex_lock()](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Thread/API/Inter-task%20communication.md#pthread_mutex_lock) in GCC.

Use **std::mutex::lock()** for [one thread function handler to increase a shared value](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Thread/Race%20condition.md#one-thread-function-handler-to-increase-a-shared-value):

```cpp
#include <iostream>
#include <thread>
#include <mutex>

#define RANGE 1000000

int shared_value;
std::mutex _mutex;

void thread_func()
{
    for (int i = 0; i < RANGE; i++) {
		_mutex.lock();
		shared_value++;
		_mutex.unlock();
	}
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

## try_lock()

```cpp
bool std::mutex::try_lock()
```

**try_lock()** will check if the mutex is available for locking and return immediately without waiting. This function is similar to [pthread_mutex_trylock()](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Thread/Documents/Mutex.md#using-pthread_mutex_trylock) in GCC.

Return:
* ``true``: Success
* ``false``: Fail

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
# Timed mutex
## try_lock_for()
```cpp
std::timed_mutex::try_lock_for()
```

``try_lock_for()`` will try to lock the mutex for a chrono time period. ``try_lock_for()`` will block the program until specified chrono time period has elapsed or the lock is acquired, whichever comes first

Return:
* ``true``: Success
* ``false``: Fail

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
## try_lock_until()
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
# lock_guard
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

# std::unique_lock

Use ``unique_lock`` to solve the [One thread function handler to increase a share value](Race%20condition.md#one-thread-function-handler-to-increase-a-share-value) issue:
```cpp
#include <iostream>
#include <thread>
#include <mutex>

#define RANGE 3000000

std::mutex _mutex;

int share_value;

void thread_func()
{
	std::unique_lock<std::mutex> lock(_mutex);
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
**Result**: ``share_value after executing 2 threads: 6000000``

For ``unique_lock``, we don't need to call ``.unlock()`` as the mutex is automatically unlocked when the ``unique_lock`` object goes out of its scope.
