# Basic inheritance example

```cpp
#include <iostream>

using namespace std;

class base_class {
public:
    base_class() {
        cout << "base_class constructor\n";
    }
    void display_function() {
        cout << "base_class display_function()\n";
    }
    void base_class_function() {
        cout << "Base class display function \n";
    }
};

class derive_class: public base_class{
	public:
		//Function display_function() of base_class class is redefine in derive_class class
		void display_function(){
			cout << "derive_class display_function()\n";
		}
		
		void derive_class_function(){
			cout << "Derive class function\n";
		}
		
};

int main(){
	base_class base_class_obj;
	derive_class derive_class_obj;
	
	base_class_obj.display_function();// base_class display_function()
	derive_class_obj.derive_class_function(); // Derive class function
	derive_class_obj.display_function(); // derive_class display_function()

	//derive_class_obj call the base_class_function function, which isn't defined in class derive_class
	derive_class_obj.base_class_function();// Base class display function
}
```
**Result**
```
base_class constructor
base_class constructor
base_class display_function()
Derive class function
derive_class display_function()
Base class display function
```
``void display_function()`` are defined in the base_class and in the derived class with different ways. This is known as **polymorphism**, as a function in inheritance can have many form in both the base class and the derive classes.
# Calling constructor in inheritance
```cpp
#include <iostream>

using namespace std;

class base_class {
public:
    base_class(int num) {
        _num = num;
    }
    void display() {
        cout << "num: " << _num << endl;
    }
private:
    int _num;
};

class derive_class: public base_class{
public:
    derive_class(int num): base_class(num) {}
};

int main(){
	derive_class derive_class_obj(123);
    derive_class_obj.display(); // num: 123
}
```
# protect method

``protected`` access modifier is similar to ``private`` access modifiers, the difference is that the class member declared as ``protected`` are inaccessible outside the class but they can be accessed by any subclass (derived class) of that class.

## Change value of protected variable ``addValue`` in inherited class.

```cpp
#include <iostream>
using namespace std;

class changeNumber{
	protected: 
		int addValue;
};

class changeNumberInherit: public changeNumber{
    public:
		changeNumberInherit(){
            cout << "addValue before: " << addValue << endl;
            addValue = 10;
            cout << "addValue after: " << addValue << endl;
		}
};

int main (){
	changeNumberInherit object;
}
```

**Result**

```
addValue before: -1604079712
addValue after: 10
```

# Header files with class and public method

**header.h**

```cpp
#include <iostream>
using namespace std;

#ifndef integerValue
#define integerValue 190
#endif

class numberProcess{
public:
	int addNumber(int a);
	void unchanged();
};
```

**header.cpp**

```cpp
#include "header.h"

int numberProcess::addNumber(int a){
	return a + integerValue;
}

void numberProcess::unchanged(){
	cout << "hello world";
}
```

**main.cpp**

```cpp
#define integerValue 2000

#include "header.h"

class cloneNumberProcess: public numberProcess{
public:
	int addNumber(int a){
		return a+integerValue;
	}
};

int main (){
	cloneNumberProcess classObject;
	numberProcess numberProcessObject;
 	cout << "Result from cloneNumberProcess class is " << classObject.addNumber(90) << endl;
 	cout << "Result from numberProcess class is " << numberProcessObject.addNumber(90) << endl;
 	classObject.unchanged();
}
```
**Result**
```
Result from cloneNumberProcess class is 2090
Result from numberProcess class is 280
hello world
```
# Generalization
In C/C++ domain modeling class diagrams, a **generalization relationship**, which is also called an inheritance or "an A is a B" (a human is a mammal, a mammal is an animal) relationship, implies that a specialized, child class is based on a general, parent class.
