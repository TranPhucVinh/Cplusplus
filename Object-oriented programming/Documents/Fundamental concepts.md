# What is class ?

**Class** is a group of objects having the same properties. An instance of a class is called an **object**.

If not declaring **public** or **[private](#private-variables)**, members of a class are private by default.

# Define variable and function for a class; Use class object as a pointer

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int publicNumber = 10;
		void hello(){
			cout << "Hello World \n";
		}
	private:
		int privateNumer = 20; //Unable to read that value outside
};

int main(){
	classTest object, *obj_ptr;
	object.hello(); //Hello World
	cout << object.publicNumber << endl; //10

	// cout << object.privateNumber << endl; // As privateNumber is private variable, this line will give error
	obj_ptr = &object;
	obj_ptr->hello(); //Hello World
	cout << obj_ptr->publicNumber << endl; //10
}
```

**Note 1**: If compiling with default G++ (C++98: ``g++ test.cpp``) and GCC (``gcc test.cpp -lstd++``), there will be warning: 

```
test.cpp:33:22: warning: non-static data member initializers only available with -std=c++11 or -std=gnu++11
   int publicNumber = 10;
                      ^
test.cpp:38:22: warning: non-static data member initializers only available with -std=c++11 or -std=gnu++11
   int privateNumer = 20; //Unable to read that value outside
```

So initilize variable variable inside a class is prefered to be implemented with ``C++11`` and the above ``C++`` standard.

**Note 2**: For pointer object ``obj_ptr``, like all normal pointer, it must be mapped to an object of that class. If not mapping, this pointer object will be a wild pointer and can't access the variable value of that object (cause Segmentation fault error)

```cpp
//This cause Segmentation fault error and must not be done
classTest *obj_ptr;
cout << obj_ptr->public_number << endl;//Segmentation fault
```

``new`` keyword can be used to allocate memory for ``*obj_ptr``:

```cpp
classTest *obj_ptr = new classTest();

obj_ptr->hello(); //Hello World
cout << obj_ptr->publicNumber << endl; //10
```

# Types of class variables

* **Instance variables**
* [Static variables](static.md#static-variables)

**Instance variables**

* Instance variables are **created when an object of the class is created** and **destroyed when the object is destroyed**.
* Instance variables can be accessed **only by creating objects**.

CPP **doesn't support** [flexible array member](https://github.com/TranPhucVinh/C/blob/master/Data%20structure/struct/Documents/Fundamental%20concepts.md#flexible-array-member) like in C.

# Function pointer as method signature
```cpp
#include <iostream>
#include <functional>

using namespace std;

class classTest{
public:
    classTest(function<void (int)> function_ptr, int value) {
        function_ptr(value);
    }
};

void func_int(int a) {
    cout << a << endl;
}

int main() {
    function<void(int)> ptr = func_int;
	classTest object(ptr, 6);
}
```
# Function pointer with lvalue argument as method signature
```cpp
class classTest{
public:
    classTest(function<void (int&)> function_ptr, int &value) {
        function_ptr(value);
    }
};

void func_int(int &a) {
    a += 1;
}

int main() {
    int a = 1;
    function<void(int&)> ptr = func_int;
	classTest object(ptr, a);
    cout << a << endl; // 2
}
```
# Function pointer as class method
```cpp
class classTest{
public:
    classTest(function<void (int)> function_ptr, int value) {
        _func_ptr = function_ptr;
        _func_ptr(value);
    }
private:
    function<void(int)> _func_ptr;
};

void func_int(int a) {
    cout << a << endl;
}

int main() {
    function<void(int)> ptr = func_int;
	classTest object(ptr, 6);
}
```
# struct

``struct`` in CPP can be treated as a class as it supports all class feature: public, private, constructor, destructor, inheritance, polymorphism, virtual function and abstract class.

* [A struct works like a class](struct.md#a-struct-works-like-a-class)
* [Inheritance with struct](struct.md#inheritance-with-struct)
* [Pure virtual function and abstract class in struct](struct.md#pure-virtual-function-and-abstract-class-in-struct)
