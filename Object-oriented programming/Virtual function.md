# When to use virtual function ?

## Assign derive class object to base class pointer to call this derive class function

In this example, we want pointer ``*b_ptr`` to use the ``display_function()`` defined by ``class derive_class``:

```cpp
#include <iostream>

class base_class {
	public:
		void display_function(){
			std::cout << "base_class display_function()\n";
		}
};

class derive_class: public base_class{
	public:
		void display_function(){
			std::cout << "derive_class display_function()\n";
		}
};

int main(){
	base_class *b_ptr;
	derive_class dc;
	b_ptr = &dc;

	b_ptr->display_function();// base_class display_function()
}
```

## Pass derive class object by reference to function with base class object pointer

In this example, we want to call the ``display_function()`` of every class object pointer passed to ``void print_function(base_class *b_ptr)``

```cpp
#include <iostream>

class base_class {
	public:
		void display_function(){
			std::cout << "base_class display_function()\n";
		}
};

class derive_class_1: public base_class{
	public:
		void display_function(){
			std::cout << "derive_class_1 display_function()\n";
		}
};

class derive_class_2: public base_class{
	public:
		void display_function(){
			std::cout << "derive_class_2 display_function()\n";
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

# Virtual function definition

In computer science, especially with OOP, dynamic dispatch is the process of selecting which implementation of a polymorphic operation (method or function) to call at run time.

A virtual function or virtual method is an inheritable and overridable function or method for which dynamic dispatch is facilitated. In short, a virtual function defines a target function to be executed, but the target might not be known at compile time.

Dynamic dispatch's compilation process includes a V table. V table is a table contains a mapping for all virtual functions inside the **base class** so that we can actually map them to the correct overwritten function in the **derived classes** at runtime

# Implementation

## Assign derive class object to base class pointer to call this derive class function

Add ``virtual`` to ``void display_function()`` of ``base_class``

```cpp
//Other part of the program kept as above
class base_class {
	public:
		virtual void display_function(){
			std::cout << "base_class display_function()\n";
		}
};
// Other part of the program kept as above
int main(){
    // Other part of the program kept as above

	b_ptr->display_function();// derive_class display_function()
}
```
## Pass derive class object by reference to function with base class object pointer

```cpp
// Other part of the program kept as above
class base_class {
	public:
		virtual void display_function(){
			std::cout << "base_class display_function()\n";
		}
};
// Other part of the program kept as above
int main(){
	derive_class_1 dc_1;
	derive_class_2 dc_2;
	print_function(&dc_1);// derive_class_1 display_function()
	print_function(&dc_2);// derive_class_2 display_function()
}
```
# override keyword

It's better to add the ``override`` keyword, **which is supported since C++11**, to the function in the derived class which used the virtual function, atlthough don't call it give no compilation error. This will be easier to to read the code as ``override`` will state that the function calling it is the derived function of the virtual function.

Adding ``override`` to the function which isn't derived from the virtual function gives compilation error.

In [Pass derive class object by reference to function with base class object pointer](#pass-derive-class-object-by-reference-to-function-with-base-class-object-pointer):

```cpp
// Other part of the program kept as above
class derive_class_1: public base_class{
	public:
		void display_function() override {
			std::cout << "derive_class_1 display_function()\n";
		}
};

class derive_class_2: public base_class{
	public:
		void display_function() override{
			std::cout << "derive_class_2 display_function()\n";
		}
};
```
# Virtual destructor

For safety purpose as expecting the derived class is destructed properly, ``virtual`` is added to the destructor function:

```cpp
//Other part of the program kept as above
class base_class {
	public:
		virtual void display_function(){
			std::cout << "base_class display_function()\n";
		}
		virtual ~base_class(){
			std::cout << "base_class destructor\n";
		}
};
```