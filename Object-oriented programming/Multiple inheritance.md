Multiple inheritance is when a class is inherited from several classes.

# Simple multiple inheritance

```cpp
#include <iostream>

using namespace std;

class base_class_1 {
	public:
		void base_class_1_function(){
			cout << "Base class 1 display function \n";
		}
};

class base_class_2 {
	public:
		void base_class_2_function(){
			cout << "Base class 2 display function\n";
		}
};

class derive_class: public base_class_1, public base_class_2 {
	public:
		void derive_class_function(){
			cout << "Derive class function\n";
		}
};

int main(){
	derive_class derive_class_object;
	
	derive_class_object.base_class_1_function();// Base class 1 display function
    derive_class_object.base_class_2_function();// Base class 2 display function
    derive_class_object.derive_class_function();// Derive class function
}
```
## Inheritance ambiguity
``class base_class_1`` and ``class base_class_2`` define the same ``display()``, which will cause **inheritance ambiguity** error when calling this function in ``class derive_class``.

To solve this issue, specify the class name when calling:

```cpp
#include <iostream>

using namespace std;

class base_class_1 {
	public:
        void display(){
            cout << "Base class 1 display\n";
        }
};

class base_class_2 {
	public:
        void display(){
            cout << "Base class 2 display\n";
        }
};

class derive_class: public base_class_1, public base_class_2 {};

int main(){
	derive_class derive_class_object;
    derive_class_object.base_class_1::display();// Base class 1 display
	derive_class_object.base_class_2::display();// Base class 2 display
}
```
