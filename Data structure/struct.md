struct in CPP can be treated as a class as it supports all class feature: public, private, constructor, destructor, inheritance, polymorphism, virtual function and abstract class.

An instance of a struct is called the **struct variable**, not object like class object. Members of a struct are **public by default**, which is different from class, as class object are private by default.

# A struct works like a class
```cpp
#include <iostream>

using namespace std;

struct classTest{
	public:
		int publicNumber;
		classTest(){
			publicNumber = 1;
			privateNumer = 2;
			cout << privateNumer << endl;
		}
		void hello(){
			cout << "Hello World \n";
		}
	private:
		int privateNumer;
};

int main(){
	classTest object, *obj_ptr;
	object.hello(); //Hello World
	cout << object.publicNumber << endl; //11

	obj_ptr = &object;
	obj_ptr->hello(); //Hello World
	cout << obj_ptr->publicNumber << endl; //1
}
```

**Result**
```
2
Hello World
1
Hello World
1
```

# Inheritance with struct

```c
#include <iostream>

using namespace std;

struct base_class {
	public:
		void display_function(){
			cout << "base_class display_function()\n";
		}
		void base_class_function(){
			cout << "Base class display function \n";
		}

};

struct derive_class: public base_class {
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
	base_class base_class_object;
	derive_class derive_class_object;
	
	base_class_object.display_function();// base_class display_function()
	derive_class_object.derive_class_function(); // Derive class function
	derive_class_object.display_function(); // derive_class display_function()

	//derive_class_object call the base_class_function function, which isn't defined in class derive_class
	derive_class_object.base_class_function();// Base class display function
}
```

# Pure virtual function and abstract class in struct

```c
#include <iostream>

struct base_class {
	public:
		virtual void display_function() = 0;
};

struct derive_class_1: public base_class{
	public:
		void display_function(){
			std::cout << "struct 1 derive_class_1 display_function()\n";
		}
};

struct derive_class_2: public base_class{
	public:
		void display_function(){
			std::cout << "struct 2 derive_class_2 display_function()\n";
		}
};

void print_function(base_class *b_ptr){
	b_ptr->display_function();
}

int main(){
	derive_class_1 dc_1;
	derive_class_2 dc_2;
	print_function(&dc_1);// base_class display_function()
	print_function(&dc_2);// base_class display_function()
}
```
