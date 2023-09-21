# Create a simple thread

```cpp
#include <iostream>
#include <thread>

void thread_func()
{
    std::cout << "Hello, World !";
}

int main()
{
    std::thread thread_obj(thread_func);
    thread_obj.join();
    return 0;
}
```
Thread can be created by calling it separately like this, which will help creating thread inside class:
```cpp
std::thread thread_obj;
thread_obj = std::thread(display_string);
thread_obj.join();
```
Or using pointer:
```cpp
std::thread *thread_obj = new std::thread(thread_func);
thread_obj->join();
```
Multiple arguments can be passed into thread function handler:
```cpp
void thread_func(int num1, int num2, int num3, int num4)
{
    std::cout << num1 + num2 + num3 + num4 << std::endl;
}

int main()
{
    std::thread thread_obj(thread_func, 1, 2, 3, 4);
    thread_obj.join();
    return 0;
}
```
## ``std::thread::join()``
Just like [pthread_join()](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Thread/API.md#pthread_join), ``std::thread::join()`` will block the current process until this thread finishes its execution.

However, creating std::thread without ``std::thread::join()`` results in error:
```c
//This program gives error when running
int main()
{
    std::thread thread_obj(thread_func);// Don't call thread_obj.join() after this results in error
    return 0;
}
```
When running this program, there will be error: **terminate called without an active exception**

## [``std::thread::join()`` will block the process if this thread has while(1)](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Thread/Fundamental%20concepts.md#stdthreadjoin-will-block-the-process-if-this-thread-has-while1)
## ``std::thread::detach()``
``std::thread::detach()`` separate the thread of execution from the thread object, allowing execution to continue independently. Any allocated resources will be freed once the thread exits.
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
**Result**: (NULL/print out nothing)
 ``std::thread::detach()`` is useful to avoid blocking the thread by ``std::thread::join()`` while still trying to have its run independently. Some of  ``std::thread::detach()`` implementations:
* [Run 2 thread, which include while(1), independently](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Thread/Fundamental%20concepts.md#stdthreadjoin-will-block-the-process-if-this-thread-has-while1)
* [Multithread HTTP server built on TCP API]()
# Create a thread inside a class
```cpp
#include <iostream>
#include <thread>

void display_string(){
	while (1){
        std::cout << "Hello, World !" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

class Thread{
	public:
		Thread(void func_handler()){
			_thread = std::thread(func_handler);
		}
		void run_thread(){
			_thread.join();
		}
	private:
		std::thread _thread;
};

int main()
{
	Thread thread_obj(display_string);
	thread_obj.run_thread();
    return 0;
}
```

# Create a thread with thread function handler as class method

```cpp
#include <iostream>
#include <thread>

using namespace std;

class classTest{
	public:
		void display_string(){
			cout << "Hello, World !\n";
		}
		void display_number(int num){
			cout << num << endl;
		}
};

int main()
{
	classTest obj;
    std::thread thread_1(&classTest::display_string, obj);
	std::thread thread_2(&classTest::display_number, obj, 123);

    thread_1.join();// Hello, World !
	thread_2.join();// 123
    return 0;
}
```
With [static class method](../../Object-oriented%20programming/Method%20of%20class.md#static%20member%20methods), class object must not be passed into the ``std::thread`` constructor. Callback functions ``classTest::display_string`` and ``classTest::display_number`` don't need to be lvalue:

```cpp
class classTest{
	public:
		static void display_string(){
			cout << "Hello, World !\n";
		}
		static void display_number(int num){
			cout << num << endl;
		}
};

int main()
{
    std::thread thread_1(classTest::display_string);
	std::thread thread_2(classTest::display_number, 123);

    thread_1.join();
	thread_2.join();
    return 0;
}
```
Threads can be started from a class method by using this pointer:
```cpp
class classTest{
	public:
		void display_string(){
			cout << "Hello, World !\n";
		}
		void display_number(int num){
			cout << num << endl;
		}
		void start_thread(){
			std::thread thread_1(&classTest::display_string, this);
			std::thread thread_2(&classTest::display_number, this, 123);

			thread_1.join();// Hello, World !
			thread_2.join();// 123
		}
};

int main()
{
	classTest obj;
	obj.start_thread();
    return 0;
}
```
