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

# Thread function handler with lvalue, std::ref()
**std::ref()** is a function used to pass lvalue variable as an argument to CPP thread:
```cpp
void thread_func(int &a) {
    a += 1;
}

int main() {
    int a = 1;
    std::thread thread_obj(thread_func, std::ref(a));
    thread_obj.join();
    std::cout << a << std::endl;// 2
    return 0;
}
```
# Create a thread inside a class
```cpp
#include <iostream>
#include <thread>

void display_string() {
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
# Delay inside thread

Delay inside thread with ``sleep_for()`` and ``chrono``:

```cpp
void thread_func()
{
    while (1){
        std::cout << "Hello, World !" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::thread thread_obj(thread_func);
    thread_obj.join();
    return 0;
}
```
