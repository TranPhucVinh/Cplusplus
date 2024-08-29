Destructor is a member function which destructs or deletes an object. Destructors don’t take any argument and don’t return anything

A destructor function is called automatically when the object goes out of scope:
* the function ends
* the program ends
* a block containing local variables ends
* a delete operator is called 

## Destructor is called when program ends
```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
        classTest(){
			cout << "Constructor of classTest\n";
		}
        ~classTest(){
			cout << "Destructor of classTest\n";
		}
};

int main(){
	classTest object;
    	cout << "Destructor is called when program ends\n";
}
```
**Result**
```
Constructor of classTest
Destructor is called when program ends
Destructor of classTest
```
## Destructor is called by delete (for pointer object)
```cpp
class classTest{
	public:
		int publicNumber;
		void hello(){
            publicNumber = 10;
			cout << "Hello World \n";
		}
        ~classTest() {cout << "Destructor\n";}
};

int main(){
    classTest *obj_ptr = new classTest();
	obj_ptr->hello(); //Hello World
	cout << obj_ptr->publicNumber << endl; //10
    delete obj_ptr;
    cout << "Call pointer\n";
}
```
```
Hello World
10
Destructor
Call pointer
```
# Destructor won't be called when program terminates abnormally
When program terminates abnormally, e.g by SIGKILL, destructors for objects won't be called:
```cpp
// Self-terminated a process after printing from 0 to ``10
#include <iostream>
#include <unistd.h>
#include <signal.h>   

using namespace std;

class classTest{
public:
    classTest(){
        cout << "Constructor of classTest\n";
    }
    ~classTest(){
        cout << "Destructor of classTest\n";
    }
};

int pid;
int number;

int main(){
	classTest object;

    pid = getpid();
    while (1){
        printf("%d\n", number);
        if (number == 10) kill(pid, SIGKILL);
        else number += 1;
    }
}
```
**Result**: Destructor function won't be called
