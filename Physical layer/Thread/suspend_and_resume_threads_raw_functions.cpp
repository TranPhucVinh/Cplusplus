#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int number = 0;
std::mutex                  suspend_mutex;
std::condition_variable 	resume_condition;
void *suspend_thread_func();
void *resume_thread_func();
void resumeAnySuspendedThread();
void suspendCurrentThread();

int main()
{
    std::thread suspend_thread(suspend_thread_func);
    std::thread resume_thread(resume_thread_func);
    suspend_thread.join();
    resume_thread.join();
    return 0;
}

void *suspend_thread_func()
{
    while (1){
		number += 1;
        std::cout << "number " << number << "\n";
		if (number==3) {
            std::cout << "Task is suspended\n";
            suspendCurrentThread();
            std::cout << "Task is resumed\n";
    	}
        std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void *resume_thread_func(){
    while (1){
		if (number == 3){
            std::this_thread::sleep_for(std::chrono::seconds(3));
            resumeAnySuspendedThread();
            std::cout << "Has delay for 3 seconds in resume_thread\n";
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }	
}

void resumeAnySuspendedThread()
{ 
    std::unique_lock<std::mutex> resumeAnySuspendedThreadLock(suspend_mutex);
    resume_condition.notify_one();
}

void suspendCurrentThread()
{ 
    std::unique_lock<std::mutex> suspendCurrentThreadLock(suspend_mutex);
    resume_condition.wait(suspendCurrentThreadLock);
}