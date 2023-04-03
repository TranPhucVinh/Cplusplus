[Fundamental concepts](Fundamental%20concepts.md) include:
* [Definition of class](Fundamental%20concepts.md#what-is-class-), [define variable and function for a class](Fundamental%20concepts.md#define-variable-and-function-for-a-class)
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
