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
# Use timed mutex [try_lock_for()]()

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

**Program**: [mutex_unique_lock.cpp]()

**Result**: ``share_value after executing 2 threads: 6000000``

For ``unique_lock``, we don't need to call ``.unlock()`` as the mutex is automatically unlocked when the ``unique_lock`` object goes out of its scope.
