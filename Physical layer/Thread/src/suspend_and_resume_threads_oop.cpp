#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int number = 0;
void suspend_thread_func();
void resume_thread_func();

class Thread{
	public:
		Thread(void func_handler()){
			_thread = std::thread(func_handler);
		}
		void run_thread(){
			_thread.join();
		}
        void resume_thread(Thread &thread_obj)
        { 
            std::unique_lock<std::mutex> resumeThreadLock(thread_obj.suspend_mutex);
            thread_obj.resume_condition.notify_one();
        }
        void suspend_thread(Thread &thread_obj)
        { 
            std::unique_lock<std::mutex> suspendThreadLock(thread_obj.suspend_mutex);
            thread_obj.resume_condition.wait(suspendThreadLock);
        }
	private:
		std::thread                 _thread;
        std::mutex                  suspend_mutex;
        std::condition_variable 	resume_condition;
};

Thread thread_1_suspend(suspend_thread_func), thread_2_resume(resume_thread_func);

int main()
{
	thread_1_suspend.run_thread();
    thread_2_resume.run_thread();
    return 0;
}

/*
    As the definition of suspend_thread_func involves a thread, i.e thread_1_suspend
    in this case with suspend_thread(), while suspend_thread_func is pass into Thread() constructor,
    suspend_thread() definition must take lvalue argument to inform its the thread existence,
    i.e thread_1_suspend in this case, to the compiler before thread is well define.
*/
void suspend_thread_func()
{
    while (1){
		number += 1;
        std::cout << "number " << number << "\n";
		if (number==3) {
            std::cout << "Task is suspended\n";
            thread_1_suspend.suspend_thread(thread_1_suspend);
            std::cout << "Task is resumed\n";
    	}
        std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

/*
    As the definition of resume_thread_func involves a thread, i.e thread_1_suspend
    in this case with resume_thread(), while resume_thread_func is pass into Thread() constructor,
    resume_thread() definition must take lvalue argument to inform its the thread existence,
    i.e thread_1_suspend in this case, to the compiler before thread is well define.
*/
void resume_thread_func(){
    while (1){
		if (number == 3){
            std::this_thread::sleep_for(std::chrono::seconds(3));
            thread_2_resume.resume_thread(thread_1_suspend);
            std::cout << "Has delay for 3 seconds in resume_thread\n";
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }	
}