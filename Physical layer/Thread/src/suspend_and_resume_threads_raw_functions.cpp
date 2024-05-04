#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int number = 0;
std::mutex                  suspend_mutex;
std::condition_variable 	resume_condition;
void suspend_thread_func();
void resume_thread_func();
void resumeThread();
void suspendThread();

int main()
{
    std::thread suspend_thread(suspend_thread_func);
    std::thread resume_thread(resume_thread_func);
    suspend_thread.join();
    resume_thread.join();
    return 0;
}

void suspend_thread_func()
{
    while (1){
		number += 1;
        std::cout << "number " << number << "\n";
		if (number==3) {
            std::cout << "Task is suspended\n";
            suspendThread();
            std::cout << "Task is resumed\n";
    	}
        std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void resume_thread_func(){
    while (1){
		if (number == 3){
            std::this_thread::sleep_for(std::chrono::seconds(3));
            resumeThread();
            std::cout << "Has delay for 3 seconds in resume_thread\n";
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }	
}

void resumeThread()
{ 
    std::unique_lock<std::mutex> resumeThreadLock(suspend_mutex);
    resume_condition.notify_one();
}

void suspendThread()
{ 
    std::unique_lock<std::mutex> suspendThreadLock(suspend_mutex);
    resume_condition.wait(suspendThreadLock);
}
