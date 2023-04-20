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
