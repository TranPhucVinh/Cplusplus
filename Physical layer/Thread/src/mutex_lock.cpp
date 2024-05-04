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