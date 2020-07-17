### Constructor

A **class constructor** is a special member function of a class that is executed whenever we create new objects of that class, and have **no return value**.

```cpp
#include <iostream>

using namespace std;

class helloWorld{
	public:
	helloWorld(){
		cout << "hello world" << endl;
	}
};

main(){
	helloWorld hi; //hello world
}
```

### More than 1 constructor in one class with arguments

```c++
#include <iostream>

using namespace std;

class classTest{
	public:
    	classTest(){
            cout << "Hello, World!" << endl;
	    }
        classTest(string displayString) {
            cout << displayString << endl;
        }
        classTest(int intValue){
             cout << intValue << endl;
        }
        classTest(int a, int b){
            cout << a+b << endl;
        }
};

main(){
	classTest object0;// Hello, World!
    classTest object1("Display string"); //Display string
    classTest object2(19); //19
    classTest object3(1, 2); //3   
}
```

### Destructor

**What is destructor ?**

* Destructor is a member function which destructs or deletes an object
* Destructors don’t take any argument and don’t return anything

**When is destructor called ?**

A destructor function is called automatically when the object goes out of scope:
* (1) the function ends
* (2) the program ends
* (3) a block containing local variables ends
* (4) a delete operator is called 

**Example**

```cpp
#include <iostream>

using namespace std;

class helloWorld{
	public:
	helloWorld(){
		cout << "hello world" << endl;
	}
	~helloWorld(){
		cout << "Object is being deleted" << endl;
	}
};

main(){
	helloWorld hi;
}
```
**Result**
```
hello world
Object is being deleted
```