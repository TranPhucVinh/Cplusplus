
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
