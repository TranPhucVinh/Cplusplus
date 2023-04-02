**Class** is a group of objects having the same properties. Every class has at least one constructor. **Constructor** is like a function and is used to express the attribute of an object. Constructor doesn't have returned type like ``void``, ``int``,... and doesn't have return value.

**Default constructors** have the same name with the class

Fundamental concepts include:
* [Define variable and function for a class](Fundamental%20concepts.md#define-variable-and-function-for-a-class)
* [Types of variables in class](Fundamental%20concepts.md#types-of-variables-in-class)
* [Method of class](Method%20of%20class.md)
* [Constructor and destructor](#constructor-and-destructor)
* [this pointer](this%20pointer.md)
* [Inheritance](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/OOP/Inheritance.md)

Examples: [Example](Example)

# Constructor and destructor

[Constructor document](Constructor.md) includes:
* Fundamental concepts
* [Multiple constructors in one class with arguments](Constructor.md#multiple-constructors-in-one-class-with-arguments)
* [default keyword](Constructor.md#change-variable-value-by-constructor)
* [Change variable value by constructor](Constructor.md#change-variable-value-by-constructor)

## Destructor

Destructor is a member function which destructs or deletes an object. Destructors don’t take any argument and don’t return anything

A destructor function is called automatically when the object goes out of scope:
* the function ends
* the program ends
* a block containing local variables ends
* a delete operator is called 

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
