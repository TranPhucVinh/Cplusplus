Beside conventional [explicit type conversion](https://github.com/TranPhucVinh/C/blob/master/Introduction/Data%20type/Type%20conversion.md#explicit-type-conversion) performed in C, CPP supports explicit type conversion with ``cast``:

* [static_cast](#static_cast)
* [dynamic_cast](#dynamic_cast)
* [const_cast](#const_cast)
* [reinterpret_cast](#reinterpret_cast)

Be not to confused the **explicit type conversion** to the **[explicit keyword](https://github.com/TranPhucVinh/Cplusplus/blob/master/Object-oriented%20programming/Constructor%20and%20destructor/Constructor.md#implicit-conversion-and-explicit-keyword)** which is used for the constructor function which only has one argument.
# static_cast

* ``static_cast`` does things like implicit conversions between types (such as ``int`` to ``float``, or ``pointer`` to ``void*``), and it can also call explicit conversion functions.
* ``static_cast`` is a compile time cast.

```cpp
float f = 3.5;
int a = f; // this is how you do in C
int b = static_cast<int>(f);
cout << a << endl;// 3
cout << b << endl;// 3 
```

There are cases that ``static_cast`` can't be implemented although its corresponding implementation in C performed successfully:

```cpp
char a = 'a';//ASCII value is 97
  
int *a_c = (int*)&a; 
int *a_cpp = static_cast<int*>(&a);//Error at compilation:  invalid static_cast from type 'char*' to type 'int*'

printf("%c", *a_c);//a
printf("%c", *a_cpp);//Error at compilation:  invalid static_cast from type 'char*' to type 'int*'
```
That's why this example needs [reinterpret_cast](#reinterpret_cast)
# dynamic_cast
``dynamic_cast`` is used for upcasting and downcasting in [polymorphism](../../Object-oriented%20programming/Inheritance/README.md#Basic%20inheritance%20example) with [virtual function](../../Object-oriented%20programming/Inheritance/Virtual%20function.md)

**Downcasting** is when a base class object is casted to the derived class object.

**Upcasting** is when a derived class object is casted to the base class object.

For virtual function, like in [Assign derive class object to base class pointer to call this derive class function](../../Object-oriented%20programming/Inheritance/Virtual%20function.md#assign-derive-class-object-to-base-class-pointer-to-call-this-derive-class-function)
, it's a safe practice to use ``dynamic_cast`` for downcasting and upcasting

```cpp
#include <iostream>

class base_class {
	public:
		virtual void display_function(){
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
	derive_class dc_1;

	// Upcast from derive_class to base_class
	base_class *b_ptr = dynamic_cast<base_class*>(&dc_1);
	b_ptr->display_function();

	derive_class *dc_2;

	// Downcast from base_class to derive_class
	dc_2 = dynamic_cast<derive_class*>(b_ptr);
	dc_2->display_function();
	b_ptr->display_function();
}
```

# const_cast

``const_cast`` is used to cast away the constness of variables. The type in a ``const_cast`` must be a pointer, reference, or pointer to member to an object type.

``const_cast`` help changing the object value inside a [const function](../../Object-oriented%20programming/README.md#const-function)

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int publicNumber;
        classTest(int _public, int _private){
            publicNumber = _public;
            privateNumber = _private;
        }
        void change_value(int _public, int _private) const {
			(const_cast <classTest*>(this))->publicNumber = _public;
			(const_cast <classTest*>(this))->privateNumber = _private;
			return;
        }
		int get_private_number(){
			return privateNumber;
		}
    private:
        int privateNumber;
};

int main(){
	classTest object(1, 2);
	cout << object.publicNumber << endl; //1
	cout << object.get_private_number() << endl;// 2

	object.change_value(12, 34);

	cout << object.publicNumber << endl; //12
	cout << object.get_private_number() << endl;// 34
}
```
# reinterpret_cast

``reinterpret_cast`` is used to convert a pointer of some data type into a pointer of another data type, even if the data types before and after conversion are different. ``reinterpret_cast`` does not check if the pointer type and data pointed by the pointer is same or not.

```cpp
char a = 'a';//ASCII value is 97

int *a_c = (int*)&a; 
int *a_cpp = reinterpret_cast<int*>(&a);

printf("%c\n", *a_c);//a
printf("%c\n", *a_cpp);//a
```
``reinterpret_cast`` for pointer to access to class object value: [reinterpret_cast_for_class_object.cpp](reinterpret_cast_for_class_object.cpp)
