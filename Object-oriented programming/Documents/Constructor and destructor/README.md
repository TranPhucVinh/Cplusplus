# Constructor
A **class constructor** is a special member function of a class that is executed whenever we create new objects of that class.

Every class has at least one constructor. **Constructor** is like a function and is used to express the attribute of an object. Constructor doesn't have returned type like ``void``, ``int``,... and doesn't have return value.

All class constructors and destructors **should be put inside public**. If putting them in [private](Constructor.md#private-constructor), they won't be called when object is initialized.

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
* [Private constructor](Constructor.md#private-constructor)
* [default keyword](Constructor.md#default-keyword)
* [Implicit conversion, conversion constructor and explicit keyword]()
* [Shallow copy, deep copy and copy constructor]()
* [Constructor initializer list](Constructor%20initializer%20list.md#constructor-initializer-list), [delegating constructor](Constructor%20initializer%20list.md#delegating-constructor)
