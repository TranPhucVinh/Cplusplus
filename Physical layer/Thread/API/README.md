# std::mutex::lock()

```cpp
void std::mutex::lock()
```

**lock()** will wait until the mutex is successfully locked. This function is similar to [pthread_mutex_lock()](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Thread/API/Inter-task%20communication.md#pthread_mutex_lock) in GCC.

# std::mutex::try_lock()
```cpp
bool std::mutex::try_lock()
```

**try_lock()** will check if the mutex is available for locking and return immediately without waiting. This function is similar to [pthread_mutex_trylock()](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Thread/Documents/Mutex.md#using-pthread_mutex_trylock) in GCC.

Return:
* ``true``: Success
* ``false``: Fail

# std::timed_mutex::try_lock_for()
```cpp
std::timed_mutex::try_lock_for()
```

``try_lock_for()`` is a timed mutex which will try to lock the mutex for a chrono time period. ``try_lock_for()`` will block the program until specified chrono time period has elapsed or the lock is acquired, whichever comes first

Return:
* ``true``: Success
* ``false``: Fail
