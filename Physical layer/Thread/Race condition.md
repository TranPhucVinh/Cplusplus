# One thread function handler to increase a share value

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

# std::mutex

## lock()

```cpp
void std::mutex::lock()
```

``lock()`` will wait until the mutex is successfully locked.

Use ``std::mutex::lock()`` for [One thread function handler to increase a share value]():

```cpp
#include <iostream>
#include <thread>
#include <mutex>

#define RANGE 1000000

int share_value;
std::mutex _mutex;

void thread_func()
{
    for (int i = 0; i < RANGE; i++) {
		_mutex.lock();
		share_value++;
		_mutex.unlock();
	}
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

## try_lock()

```cpp
bool std::mutex::try_lock()
```

``try_lock()`` will check if the mutex is available for locking and return immediately without waiting.

Return:
* ``true``: Success
* ``false``: Fail

Use ``std::mutex::try_lock()`` for [One thread function handler to increase a share value]():

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
//Other operations are like One thread function handler to increase a share value
```
**Resul**:

```
...
Fail to lock mutex
Fail to lock mutex
share_value after executing 2 threads: 1987206
```
# Timed mutex

```cpp
std::timed_mutex::try_lock_for()
```

``try_lock_for()`` will try to lock the mutex for a chrono time period. Blocks until specified chrono time period has elapsed or the lock is acquired, whichever comes first

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