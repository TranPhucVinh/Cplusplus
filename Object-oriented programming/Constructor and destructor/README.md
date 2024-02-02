# Constructor
A **class constructor** is a special member function of a class that is executed whenever we create new objects of that class.

Every class has at least one constructor. **Constructor** is like a function and is used to express the attribute of an object. Constructor doesn't have returned type like ``void``, ``int``,... and doesn't have return value.

All class constructors and destructors **should be put inside public**. If putting them in private, they won't be called when object is initialized.

**Default constructors** have the same name with the class

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
[Constructor document](Constructor.md) includes:
* [Constructor overloading](Constructor.md#constructor-overloading)
* [default keyword](Constructor.md#default-keyword)
* [Implicit conversion, conversion constructor and explicit keyword]()
* [Shallow copy, deep copy and copy constructor]()
* [Constructor initializer list](Constructor%20initializer%20list.md#constructor-initializer-list), [delegating constructor](Constructor%20initializer%20list.md#delegating-constructor)

# Destructor

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
