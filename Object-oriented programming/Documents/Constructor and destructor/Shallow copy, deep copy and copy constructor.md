# Shallow copy
**Shallow copy** is used to initialize the members of a newly created object by copying the members of an already existing object.
```cpp
// There is no copy constructor in this shallow copy implementation
#include <iostream>
using namespace std;

class classTest{
	public:
        int public_num;
        classTest(int a, int b){
            cout << a+b << endl;
        }
};

int main(){
    classTest object(1, 2); //3   
    object.public_num = 123;

    classTest object1(object); //object1 is the copy construct of object, using ()
    cout << object.public_num << endl;// 123
    cout << object1.public_num << endl;// 123 

    classTest object2 = object; //object1 is the copy construct of object, using = (assignment operator)
    cout << object2.public_num << endl;// 123 
}
```
# Copy constructor
A **copy constructor** is a member function that initializes an object using an existing object of the same class. Copy constructor will be called during the shallow copy:
```cpp
#include <iostream>
using namespace std;

class classTest{
	public:
        classTest(int a, int b){
            cout << a+b << endl;
            cout << "classTest(int a, int b) is called\n";
        }

        // This is a copy constructor which will be called for
        // classTest object1(object);
        // classTest object2 = object;
        classTest(classTest &obj){
            cout << "classTest(const classTest &obj) is called\n";
        }
};

int main(){
    classTest object(1, 2);// 3   

    classTest object1(object); //object1 is the copy construct of object, using ()
    classTest object2 = object; //object1 is the copy construct of object, using = (assignment operator)
}
```
**Result**
```
3 
classTest(int a, int b) is called
classTest(const classTest &obj) is called // classTest object1(object)
classTest(const classTest &obj) is called // classTest object2 = object   
```
# Problem when using shallow copy for pointer object
```cpp
#include <iostream>
#include <stdio.h>
using namespace std;

class classTest{
	public:
        int *ptr;
        classTest(): ptr(new int(0)){}
        void setPtr(int val){ *ptr = val;}
};

int main()
{
    classTest object; 
    object.setPtr(123);
    cout << *object.ptr << endl;// 123

    classTest object1(object);   
    object1.setPtr(456);

    cout << object.ptr << endl;//0x558f6fab4e70
    cout << object1.ptr << endl;//0x558f6fab4e70
    cout << *object.ptr << endl;//456, expected 123
    cout << *object1.ptr << endl;//456
}
```
**Shallow copy will copy the whole member, including the memory address**, from ``object`` to ``object1`` so that ``object1`` now will point to the address memory of ``object``. So setting ``object1.setPtr(456)`` will also set ``object.ptr`` to ``456``.

To solve that issue, i.e changing ``object1.ptr`` won't change ``object.ptr``, use **deep copy**.

# Deep copy

A deep copy of an object is a copy whose properties do not share the same references (memory location) as those of the source object from which the copy was made. 

In order to perform Deep copy, we need to explicitly define the copy constructor and assign dynamic memory as well, if required. Also, it is required to dynamically allocate memory to the variables in the other constructors, as well.

```cpp
#include <iostream>
#include <stdio.h>
using namespace std;

class classTest{
	public:
        int *ptr;
        classTest(): ptr(new int(0)){}
        classTest(const classTest &obj){
            ptr = new int(0);
            *ptr = *obj.ptr;
            return;
        }

        void setPtr(int val){ *ptr = val;}
};

int main()
{
    classTest object;
    object.setPtr(123);
    cout << *object.ptr << endl;// 123

    classTest object1(object);   
    object1.setPtr(456);

    cout << object.ptr << endl;// 0x55f5b700be70
    cout << object1.ptr << endl;// 0x55f5b700c2a0
    cout << *object.ptr << endl;// 123
    cout << *object1.ptr << endl;// 456
}
```
