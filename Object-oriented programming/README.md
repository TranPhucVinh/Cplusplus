[Fundamental concepts](Fundamental%20concepts.md) include:
* [Definition of class](Fundamental%20concepts.md#what-is-class-), [define variable and function for a class](Fundamental%20concepts.md#define-variable-and-function-for-a-class), [types of variables in class](Fundamental%20concepts.md#types-of-class-variables)
* [Method of class](Method%20of%20class.md): [Private method](), [non-static member methods]() and [static member methods]()
* [Encapsulation](#encapsulation)
* [Constructor and destructor](#constructor-and-destructor)
* [this pointer](this%20pointer.md)
* [Inheritance](Inheritance.md): [Basic inheritance example as polymorphism](Inheritance/README.md#basic-inheritance-example), [generalization](Inheritance/README.md#generalization), [protect method](Inheritance/README.md#protect-method), [Header files with class and public method](), [multilevel inheritance]() and [multiple inheritance]()
* [Virtual function](Inheritance/Virtual%20function.md): [When to use virtual function ?](Inheritance/Virtual%20function.md#when-to-use-virtual-function-), [virtual function definition](Virtual%20function.md#virtual-function-definition) and [implementation](Inheritance/Virtual%20function.md#implementation), [override keyword](Inheritance/Virtual%20function.md#override-keyword), [virtual destructor](Inheritance/Virtual%20function.md#virtual-destructor), [pure virtual function and abstract class](Inheritance/Virtual%20function.md#pure-virtual-function-and-abstract-class)
* [Binding](#binding): [Early binding]() and [late binding]()
* [const function](const%20function.md)

[Example](Example)

# Encapsulation
Encapsulation is defined as the wrapping up of data and information in a single unit. 

We can not access any function from the class directly. We need an object to access that function that is using the member variables of that class. 

The function which we are making inside the class must use only member variables, only then it is called encapsulation.

Encapsulation will help increasing the security of data.

# Constructor and destructor

[Constructor document](Constructor.md) includes:
* [Fundamental concepts](Constructor.md#fundamental-concepts)
* [Multiple constructors in one class with arguments](Constructor.md#multiple-constructors-in-one-class-with-arguments)
* [default keyword](Constructor.md#default-keyword)
* [Constructor initializer list](Constructor.md#constructor-initializer-list)

## Destructor

Destructor is a member function which destructs or deletes an object. Destructors don’t take any argument and don’t return anything

A destructor function is called automatically when the object goes out of scope:
* the function ends
* the program ends
* a block containing local variables ends
* a delete operator is called 

### Destructor is called when program ends
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
### Destructor is called by delete (for pointer object)
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
# Binding

Binding refers to the process of converting identifiers (such as variable and performance names) into addresses. Binding is done for each variable and functions. For functions, it means that matching the call with the right function definition by the compiler. It takes place either at compile time or at runtime.

**Early binding (compile-time time polymorphism)**: In early binding, compiler (or linker) directly associate an address to the function call. C++ uses early binding by default. 

**Late binding (run time polymorphism)**: In late binding, the compiler adds code that identifies the kind of object at runtime then matches the call with the right function definition. This can be achieved by declaring a [virtual function]().
