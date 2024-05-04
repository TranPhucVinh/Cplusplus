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