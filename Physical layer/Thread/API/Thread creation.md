# ``std::thread::join()`` will block the process if this thread has while(1)
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
**Problem solved**: Use **[std::thread::detach](Create%20thread.md#stdthreadjoin)** to separate the thread of execution from the thread object, allowing execution to continue independently.

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
