# Static variables

Static variables exist as members of the class rather than as an instance in each object of the class, i.e a static variable can be shared to all objects of a class. There is only a single instance of each static data member for the entire class. 

Defining static variables inside the CPP source file (e.g [header.cpp](Example/header.cpp)) must not have **static** storage class. Check [int exampleClass::static_var = 10](https://github.com/TranPhucVinh/Cplusplus/blob/master/Object-oriented%20programming/Example/header.cpp#L8) in [header.cpp](Example/header.cpp) for this implementation.

**We cannot initialize a static member variable inside its class definition without const keyword**. That's because the definition is a description of how memory is to be allocated, but it doesn't allocate memory.

Static variables can be defined with: ``className::staticVariable = value``, its value can then be changed by a method, like **change_static()** in this example:

**Example**: ``main.cpp``

```cpp
#include <iostream>
using namespace std;

class ClassTest
{
  	public:
    	static int a;
        void change_static(){
            ClassTest::a = 123;
			// Or simply: 
			// a = 123;
        }
};

int ClassTest::a = 100;

int main(){
    ClassTest obj1;
    cout << ClassTest::a << endl;//100
    cout << obj1.a << endl; //100

    ClassTest::a++;
    cout << ClassTest::a << endl;//101

    obj1.a++;
    cout << ClassTest::a << endl;//102

    ClassTest obj2;
    cout << ClassTest::a << endl;//102
    cout << obj2.a << endl;//102

    obj2.change_static();
    cout << ClassTest::a << endl;//123
    cout << obj2.a << endl;//123
}
```

You can't initialize non-const static member

```cpp
class Header
{
  public:
    static int a = 12;
};
```

This will give error: ``ISO C++ forbids in-class initialization of non-const static member``

Static variable can be defined normally in another source file:

``header.cpp`` (``header.h`` and ``main.cpp`` are kept the same)

```cpp
#include <iostream>
#include "header.h"
using namespace std;

int Header::a = 10;
```
**Application**: static must be implemented in [singleton class]().
# Static member methods

## Static member methods can only operate on static variables, static functions and variables and functions outside its class

**Static member methods** can only operate on static variables, static functions and variables and functions outside its class. It can't call non-static variables and non-static functions. Example: Check ``read_static_var()`` function in [header.cpp](Example/header.cpp). Also note that defining function ``read_static_var()`` inside the CPP source file must not have ``static`` storage class.

Use **::** operator to call static method, only static method can be called by that operator:

```cpp
exampleClass::static_print_argument(789);
```

Static member method works with variables and functions outside the class like this example:

``header.h``

```cpp
#include <iostream>
#ifndef header_h
#define header_h

using namespace std;

class exampleClass
{
  	public:
		static int 	static_return_int();
		static void static_print_argument(int argument);
};
#endif
```
``header.cpp``
```cpp
#include "header.h"

int exampleClass::static_return_int(){
    return 123;
}
void exampleClass::static_print_argument(int argument){
    cout << argument << endl;
}
```

``main.cpp``

```cpp
#include "header.h"

int a = 456;
main(){
	exampleClass object;
	object.static_print_argument(a);//456

	int b = object.static_return_int();
	object.static_print_argument(b);//123

	// Only static method can be called by :: operator
    exampleClass::static_print_argument(789);// 789
}
```

Refer to [header.cpp](https://github.com/TranPhucVinh/Cplusplus/blob/master/Object-oriented%20programming/Example/header.cpp) for static variable and method implementations.

## static constexpr const char
For **const char pointer as string**, **static member method** must use [constexpr](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/README.md#constexpr):

```cpp
class ClassTest
{
  	public:
		static void return_string();
  	private:  
		static constexpr const char *_string = "static_string";
};

void ClassTest::return_string(){
    cout << _string << endl;
}

int main () {
    ClassTest obj;
    obj.return_string();// static_string
}
```
## Must use static for function pointers to be called inside class method
```cpp
#include <stdio.h>

class ClassTest {
    public:
        ClassTest(){
            int (*p)(int, int);

            p = add_int_numbers;
            printf("%d \n",p(5,6)); //11

            p = subtract;
            printf("%d \n",p(5,8)); //-3
        }
    private:
        static int add_int_numbers(int a, int b){// Must use static
            return a+b;
        }
        static int subtract(int a, int b){// Must use static
            return a-b;
        }
};

int main()
{  
    ClassTest obj;
}
```