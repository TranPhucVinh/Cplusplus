# Private methods

**Private methods** can't be access outside the class internal definition and can only be called from outisde the class by public functions. Check ``call_private_function()`` function in [header.cpp](Example/header.cpp)

# Non-static member methods

**Non-static member methods** can access all data members (static and non-static variables) of the class. Example: Check ``add_number()`` function in [header.cpp](Example/header.cpp)

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
# Calling multiple method at one time

## Simple call

```cpp
#include <iostream>

using namespace std;
class classTest{
	public:
		classTest display_string(){
            classTest new_object;
			cout << "Hello, World !\n";
            return new_object;
		}
        void display_number(){
			cout << 123;
		}
};

int main(){
	classTest object;
    object
        .display_string()
        .display_number()
    ;
}
```
  
``display_number()`` can be called after ``display_string()`` as ``display_string()`` return object ``new_object`` as having type ``classTest``. ``new_object`` will then be used for calling ``display_number()``.

**Result**

```
Hello, World !
123
```

Can also call by this way:

```cpp
classTest object;
object.display_string().display_number();
```

## Using this pointer

To keep the same object when calling multiple methods, it's better to use ``this`` pointer.

```cpp
classTest display_string(){
    cout << "*this Hello, World !\n";
    return *this;
}

//Other operations keep as above

int main(){
	classTest object;
    object.display_string().display_number();
}
```
## Using rvalue class object
```cpp
#include <iostream>
#include <typeinfo>

using namespace std;
template <typename class_type>
void call_object_method(class_type&& object){
    object
        .display_string()
        .display_number()
    ;
}

class classTest{
	public:
		classTest& display_string(){
			cout << "Hello World \n";
            return *this;
		}
        void display_number(){
			cout << 123;
		}
};

int main(){
	classTest&& rval_object = classTest();
    call_object_method<classTest&&>(move(rval_object));
}
```
