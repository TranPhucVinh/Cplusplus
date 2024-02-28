# Constructor overloading
We can have **multiple constructors in one class**, where each constructor can have arguments. This is known as **constructor overloading**, which is quite similar to [function overloading](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Function#function-overloading).

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
    	classTest(){
            cout << "Hello, World!" << endl;
	    }
        classTest(string displayString) {
            cout << displayString << endl;
        }
        classTest(int intValue){
             cout << intValue << endl;
        }
        classTest(int a, int b){
            cout << a+b << endl;
        }
};

main(){
	classTest object0;// Hello, World!
    classTest object1("Display string"); //Display string
    classTest object2(19); //19
    classTest object3(1, 2); //3
    classTest object4 = {4, 5}; //9; Initializer list, C++ and above  
}
```

We can use this method to set up values for public and private variables:

```cpp
#include <iostream>

using namespace std;

class class_test{
	public:
		int public_number;
        class_test(int _public_number, int _private_number){
            public_number = _public_number;
            private_number = _private_number;
        }

        class_test(){
            cout << "Call constructor\n";
        }

		void get_number(){
            cout << "Get public and private numbers: \n";
            cout << "public_number " << public_number << "; ";
            cout << "private_numer " << private_number << endl;
		}

	private:
		int private_number;
};

int main(){
	class_test object_1;
	object_1.get_number();

    class_test object_2(1, 2);
	object_2.get_number();
}
```

```
Call constructor
Get public and private numbers:
public_number -427810560; private_numer 21946
Get public and private numbers:
public_number 1; private_numer 2
```
# private constructor

As private constructor is not called during object initialization, this implementation will call the private constructor inside the publicj constructor:

```cpp
class classTest{
	public:
        classTest(int a)
        {
            int b = 1;
            classTest(a, b);
        }
    private:
        classTest(int a, int b){
            cout << a+b << endl;
        }
};

int main(){
	classTest obj(12); // 13
}
```
# default keyword

``default`` keyword, which is supported from ``C++11``, supports performing default operations like setting variables inside the default constructor. This method is useful when having multiple constructor functions:

```cpp
#include <iostream>

using namespace std;

class class_test{
	public:
		int public_number = 1;

		class_test() = default;

        class_test(int _public_number, int _private_number){
            public_number = _public_number;
            private_number = _private_number;
        }

		void get_number(){
            cout << "Get public and private numbers: \n";
            cout << "public_number " << public_number << "; ";
            cout << "private_numer " << private_number << endl;
		}

	private:
		int private_number = 2;
};

int main(){
	class_test object_1;
	object_1.get_number();

    class_test object_2(3, 4);
	object_2.get_number();
}
```
	
Result

```
Get public and private numbers:
public_number 1; private_numer 2
Get public and private numbers:
public_number 3; private_numer 4
```

In this program, calling ``class_test object_1`` will call the default constructor (setup by ``class_test() = default``) to setup default value for variables.
# Implicit conversion, conversion constructor and explicit keyword
## Implicit conversion, conversion constructors
For multiple constructors, beside the setting their arguments [as constructor-overloading as the traditional way](#constructor-overloading), CPP supports **implicit conversion** which allows setting this constructor argument value by the assignment operator (``=``):
```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
        classTest(string displayString) {
            cout << displayString << endl;
        }
        classTest(int intValue){
             cout << intValue << endl;
        }
        classTest(int a, int b){
            cout << a+b << endl;
        }
};

int main(){
	// Must use std::string(); not classTest object1 = "Display string"
    classTest object1 = std::string("Display string"); //Display string
    classTest object2 = 19; //19
    classTest object3 = {4, 5}; //9; Initializer list, C++ and above  
}
```
All the constructors implemented in the above example are **conversion constructors**. **Conversion constructors** are constructors that convert types of its parameter into a type of the class.
## explicit keyword
**Explicit keyword** will **block CPP compiler from implicit conversion** so that you're forced to use the [constructor overloading (as the traditional way)](#constructor-overloading) to set up constructor value:
```cpp
class classTest{
	public:
        explicit classTest(string displayString) {
            cout << displayString << endl;
        }
        explicit classTest(int intValue){
             cout << intValue << endl;
        }
        explicit classTest(int a, int b){
            cout << a+b << endl;
        }
};

int main(){
	// MUST NOT DO THIS. THIS GIVES COMPILATION ERROR
    classTest object1 = std::string("Display string"); //Compilation error
    classTest object2 = 19; //Compilation error
	classTest object3 = {4, 5}; //Compilation error
}
```
