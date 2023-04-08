A class can also be derived from one class, which is already derived from another class.

In this example, ``class child_class`` derived from ``class derive_class``, which derived from ``class base_class``

```c
#include <iostream>

using namespace std;

class base_class {
	public:
		void display_function(){
			cout << "base_class display_function()\n";
		}
		void base_class_function(){
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

class child_class: public derive_class{
	public:
		void child_class_function(){
			cout << "Child class function\n";
		}
};


int main(){
	child_class child_class_object;
	
	child_class_object.display_function();// derive_class display_function()
	child_class_object.base_class_function();// Base class display function
    child_class_object.derive_class_function();// Derive class function
    child_class_object.child_class_function();// Child class function
}
```
