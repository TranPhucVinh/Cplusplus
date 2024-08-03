# ``std::thread::join()``
Just like [pthread_join()](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Thread/API.md#pthread_join), ``std::thread::join()`` will block the current process until this thread finishes its execution.

However, creating std::thread without ``std::thread::join()`` results in error:
```c
//This program gives error when running
int main()
{
    std::thread thread_obj(thread_func);
    return 0;
}
```
When running this program, there will be error: **terminate called without an active exception**
## ``std::thread::join()`` will block the process if this thread has while(1)
```cpp
#include <iostream>
#include <thread>
#include <unistd.h>

void display_string(const char *str){
	while (1){
        std::cout << std::string(str) << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void display_int(int number){
	while (1){
        std::cout << number << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::thread str_thread(display_string, "Hello, World !");
	str_thread.join();
	std::thread int_thread(display_int, 123);
	int_thread.join();
	std::cout << "display_string thread has joined" << std::endl;
	std::cout << "display_int thread has joined" << std::endl;
	while(1){
		std::cout << "2 thread are running now\n";
		sleep(1);
	}
    return 0;
}
```
**Result**
```
Hello, World !
Hello, World !
... (Only thread 1 runs, thread 2 doesn't run. The lines of code after str_thread.join() won't be run as they're blocked)
```
**Problem solved**: Use **[std::thread::detach](#stdthreadjoin)** to separate the thread of execution from the thread object, allowing execution to continue independently.

```cpp
std::thread str_thread(display_string, "Hello, World !");
str_thread.detach();
std::thread int_thread(display_int, 123);
int_thread.detach();
std::cout << "display_string thread has joined" << std::endl;
std::cout << "display_int thread has joined" << std::endl;
while(1){
	std::cout << "2 thread are running now\n";
	sleep(1);
}
return 0;
```
**Result**:
```
display_string thread has joined
display_int thread has joined                                                                                  
2 thread are running now
Hello, World !
123                                                                                                                    
2 thread are running now 
Hello, World !
123
2 thread are running now                         
123
Hello, World ! 
123
....
```
# ``std::thread::detach()``
``std::thread::detach()`` detaches the thread it specifies from the main thread, allowing execution to continue independently. Any allocated resources will be freed once the thread exits.
```cpp
void thread_func()
{
    std::cout << "Hello, World !";
}

int main()
{
    std::thread thread_obj(thread_func);
	thread_obj.detach();
    return 0;
}
```
**Result**: NULL/print out nothing as main() thread doesn't wait for thread_obj to finish.

 ``std::thread::detach()`` is useful to avoid blocking the thread by ``std::thread::join()`` while still trying to have its run independently. Some of  ``std::thread::detach()`` implementations:
* [Run 2 thread, which include while(1), independently](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Thread/Fundamental%20concepts.md#stdthreadjoin-will-block-the-process-if-this-thread-has-while1)
* [Multithread HTTP server built on TCP API]()
