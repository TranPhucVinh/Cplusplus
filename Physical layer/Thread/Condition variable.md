# 2 threads with mutex where thread 1 allows thread 2 to run
After increasing the ``share_value`` to its ``RANGE``, thread 1 will set ``thread_2_run`` to allow thread 2 to run. Thread 2 will wait for ``thread_2_run`` then increases the ``share_value`` to ``RANGE``. This example is quite similar to [One thread function handler to increase a share value issue](Race%20condition.md#one-thread-function-handler-to-increase-a-share-value), except it has the flag ``thread_2_run`` to block thread 2 from running.

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

#define RANGE 1000000

void thread_func_1();
void thread_func_2();

int share_value;
int thread_2_run = 0;

std::mutex _mutex;

int main()
{
    std::thread thread_1(thread_func_1), thread_2(thread_func_2);
    thread_1.join();
	thread_2.join();
	printf("share_value after executing 2 threads: %d\n", share_value);
    return 0;
}

void thread_func_1()
{
    for (int i = 0; i < RANGE; i++) {
		std::unique_lock<std::mutex> thread1_lock(_mutex);
		share_value++;
    }
    thread_2_run = 1;
}

void thread_func_2(){
	std::unique_lock<std::mutex> thread2_lock(_mutex);
    for (int i = 0; i < RANGE; i++) {
        while(!thread_2_run){
            printf("Thread 2 isn't ready to run\n");
            sleep(1);
        }
        share_value++;
    }
}
```
# void wait(std::unique_lock<std::mutex>& lock)
```cpp
void std::condition_variable::wait( std::unique_lock<std::mutex>& lock);
```
``wait()`` causes the current thread to block until the condition variable is notified or a spurious wakeup occurs.

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#define RANGE 1000000

void thread_func_1();
void thread_func_2();

int share_value;
int thread_2_run = 0;

std::mutex 					_mutex;
std::condition_variable 	cv;

int main()
{
    std::thread thread_1(thread_func_1), thread_2(thread_func_2);
    thread_1.join();
	thread_2.join();
	printf("share_value after executing 2 threads: %d\n", share_value);
    return 0;
}

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
	std::unique_lock<std::mutex> thread2_lock(_mutex);
    for (int i = 0; i < RANGE; i++) {
        while(!thread_2_run){
            printf("Thread 2 isn't ready to run\n");
            cv.wait(thread2_lock);
        }
        share_value++;
    }
}
```
# void wait(std::unique_lock<std::mutex>& lock, Predicate stop_waiting)
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
# std::condition_variable::wait_for()

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
