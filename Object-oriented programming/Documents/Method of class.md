# Private methods

**Private methods**, i.e variables and functions, can't be access outside the class internal definition and can only be called from outisde the class by public functions. Check ``call_private_function()`` function in [header.cpp](Example/header.cpp)

**Private variables** are available only inside the class function definition (check [examples](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/OOP/Example) for that implementation), class object is unable to access it

Any members defined out specified **public** or **private** are **private** by default:
```cpp
class classTest{
    int privateNumer; //This is a private member
	public:
		int publicNumber;
		void displayStringhello(){
            publicNumber = 123;
		}
};
```

# Non-static member methods

**Non-static member methods** can access all data members (static and non-static variables) of the class. Example: Check ``add_number()`` function in [header.cpp](Example/header.cpp)
# [Static member methods](static.md#static-member-methods)
* Static member methods can only operate on static variables, static functions and variables and functions outside its class
* **static constexpr const char** for **const char pointer as string**
* Must use static for function pointers to be called inside class method
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
