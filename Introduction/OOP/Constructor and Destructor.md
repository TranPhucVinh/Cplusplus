## Constructor

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

### Change variable value by constructor

Public and private variables value can be changed by constructor with ``:`` operator:

```c
#include <iostream>

using namespace std;

class class_test{
	public:
		int public_number = 10;

        //Calling this construct to change value of public_number and private_numer
        class_test() : public_number(12), private_numer(13){
            cout << "Constructor: \n";
            cout << "public_number " << public_number << "; ";
            cout << "private number " << private_numer << endl;
        }

		void get_number(){
            cout << "Get public and private numbers: \n";
            cout << "public_number " << public_number << "; ";
            cout << "private_numer " << private_numer << endl;
		}

	private:
		int private_numer = 20; //Unable to read that value outside
};

int main(){
	class_test object;
	object.get_number();
	cout << object.public_number << endl; //12
}
```

**Result**
```
Constructor:
public_number 12; private number 13
Get public and private numbers:
public_number 12; private_numer 13
12
```

## Destructor

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
