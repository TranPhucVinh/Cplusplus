[Fundamental concepts](Fundamental%20concepts.md) include:
* [Definition of class](Fundamental%20concepts.md#what-is-class-), [define variable and function for a class](Fundamental%20concepts.md#define-variable-and-function-for-a-class)
* [Types of variables in class](Fundamental%20concepts.md#types-of-variables-in-class)
* [Method of class](Method%20of%20class.md)
* [Constructor and destructor](#constructor-and-destructor)
* [this pointer](this%20pointer.md)
* [Inheritance](Inheritance.md): [Basic inheritance example as polymorphism](), [protect method]() and [Header files with class and public method]()
* [Virtual function](Virtual%20function.md): [When to use virtual function ?](Virtual%20function.md#when-to-use-virtual-function-), [virtual function definition](Virtual%20function.md#virtual-function-definition) and [implementation](Virtual%20function.md#implementation), [override keyword](Virtual%20function.md#override-keyword), [virtual destructor](Virtual%20function.md#virtual-destructor), [pure virtual function and abstract class](Virtual%20function.md#pure-virtual-function-and-abstract-class)
* [Binding](#binding): [Early binding]() and [late binding]()
* [const function]()

[Example](Example)

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

# Binding

Binding refers to the process of converting identifiers (such as variable and performance names) into addresses. Binding is done for each variable and functions. For functions, it means that matching the call with the right function definition by the compiler. It takes place either at compile time or at runtime.

**Early binding (compile-time time polymorphism)**: In early binding, compiler (or linker) directly associate an address to the function call. C++ uses early binding by default. 

**Late binding (run time polymorphism)**: In late binding, the compiler adds code that identifies the kind of object at runtime then matches the call with the right function definition. This can be achieved by declaring a [virtual function]().

# const function

**const function** as a class member doesn't allow changing the object value. Be not confused const function of a class with [the function define as const](https://github.com/TranPhucVinh/C/tree/master/Introduction/Keywords#const-as-function-definition) as defining a function as const has no effect.

```c
#include <iostream>

using namespace std;

class classTest{
	public:
		int publicNumber;
        classTest(){
            publicNumber = 1;
            privateNumber = 2;
        }
        int function(int a) const {
            /*
                Doing any suff inside the class member const function which effect publicNumber
                and privateNumber will give compilation error
            */
            a += 1;// Any stuff can be done as long as they don't effect the variable of publicNumber
            return publicNumber;
	    // return privateNumber; privateNumber returns normally
        }
    private:
        int privateNumber;
};

int main(){
	classTest object;
    cout << object.function(12) << endl; //1 as function() returns publicNumber
}
```

If define:

```cpp
// Must not do this
int function(int a) const {
    publicNumber = a;// Compilation error here
    privateNumber = a;// Compilation error here
    return publicNumber;
}
```
This gives compilation error as trying to modify the class member (``publicNumber`` and ``privateNumber``) inside a const function:

```
error: assignment of member 'classTest::publicNumber' in read-only object
error: assignment of member 'classTest::privateNumber' in read-only object
```
