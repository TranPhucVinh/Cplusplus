[Fundamental concepts](Fundamental%20concepts.md) include:
* [What is class ?](), [define variable and function for a class](Fundamental%20concepts.md#define-variable-and-function-for-a-class)
* [Types of variables in class](Fundamental%20concepts.md#types-of-variables-in-class)
* [Method of class](Method%20of%20class.md)
* [Constructor and destructor](#constructor-and-destructor)
* [this pointer](this%20pointer.md)
* [Inheritance](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/OOP/Inheritance.md)

Examples: [Example](Example)

# Constructor and destructor

[Constructor document](Constructor.md) includes:
* [Fundamental concepts](Constructor.md#fundamental-concepts)
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
}
```
**Result**
```
Constructor of classTest
Destructor of classTest
```
