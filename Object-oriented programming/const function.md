# const function
**const function** as a class member doesn't allow changing the object value. Be not confused const function of a class with [the function define as const](https://github.com/TranPhucVinh/C/tree/master/Introduction/Keywords#const-as-function-definition) as defining a function as const has no effect.

```cpp
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
However, **object value inside a const function can be changed by [const_cast](../Introduction/Data%20type/Explicit%20type%20conversion.md#const_cast)**.
# const object

``const`` object member must have at least one constructor as the initializer:
```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
        int publicNumber;
        classTest(){
            publicNumber = 123;
            cout << publicNumber;
        }
};

int main(){
	const classTest object;
}
```
# mutable 

**mutable storage class** specifier is used when you want to change the member of a const class object.
## Changing member by assign operator 
```cpp
// THIS PROGRAM GIVES COMPILATION ERROR AND IS USED TO
// DEMONSTRATE THE USE OF mutable
#include <iostream>
using std::cout;

class classTest {
    public:
        int number;
    classTest() { number = 1;}
};
int main()
{
	const classTest obj;
    // As obj is a const object, changing its member number
    // results in compilation error
	obj.number = 2;// This gives compilation error
	cout << obj.number;
	return 0;
}
```
**Error**: ``error: assignment of member 'classTest::number' in read-only object``

In order to change the value of member ``number`` when we use object ``obj`` as ``const`` mandatorily, we must use ``mutable``:
```cpp
#include <iostream>
using std::cout;

class classTest {
    public:
        mutable int number;
    classTest() { number = 1;}
};
int main()
{
	const classTest obj;
	obj.number = 2;
	cout << obj.number;// 2
	return 0;
}
```
## Changing member by function
```cpp
// THIS PROGRAM GIVES COMPILATION ERROR AND IS USED TO
// DEMONSTRATE THE USE OF mutable
#include <iostream>

using namespace std;

class classTest{
	public:
        int publicNumber;
        classTest(){
            publicNumber = 123;
            cout << publicNumber;
        }
        void change_private(int val){
            publicNumber = val; 
            cout << publicNumber;
        }
};

int main(){
	const classTest object;

    // As obj is a const object, changing its member number
    // by this function results in compilation error
    object.change_private(456); // This gives compilation error
}
```
In order to change the value of member ``number`` by function, that function must have type ``const``, along with the ``mutable`` storage class for the member:
```cpp
class classTest{
	public:
        mutable int publicNumber;
        classTest(){
            publicNumber = 123;
            cout << publicNumber << endl;
        }
        // Must set to const to use with mutable
        void change_private(int val) const{
            publicNumber = val; 
            cout << publicNumber << endl;
        }
};

int main(){
	const classTest object;
    object.change_private(456); //456
}
```
