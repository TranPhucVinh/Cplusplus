Beside conventional [explicit type conversion](https://github.com/TranPhucVinh/C/blob/master/Introduction/Data%20type/Type%20conversion.md#explicit-type-conversion) performed in C, CPP supports explicit type conversion with ``cast``:

* [static_cast](#static_cast)
* Dynamic cast
* Const cast
* Reinterpret cast

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
That's why this example needs [reinterpret cast](Reinterpret%20cast)

# Reinterpret cast

``reinterpret_cast`` is used to convert a pointer of some data type into a pointer of another data type, even if the data types before and after conversion are different. ``reinterpret_cast`` does not check if the pointer type and data pointed by the pointer is same or not.

```cpp
char a = 'a';//ASCII value is 97

int *a_c = (int*)&a; 
int *a_cpp = reinterpret_cast<int*>(&a);

printf("%c\n", *a_c);//a
printf("%c\n", *a_cpp);//a
```
``reinterpret_cast`` for pointer to access to class object value:
```cpp
#include <iostream>
using namespace std;

class classTest {
	public:
		int intVal1;
		int intVal2;
		char charVal;
		bool boolVal;
};

int main()
{
	classTest object;

	object.intVal1 = 5;
	object.intVal2 = 10;
	object.charVal = 'a';
	object.boolVal = true;

	// Cast object to int pointer for later step to access to intVal1 and intVal2
	int* ptr = reinterpret_cast<int*>(&object);

	cout << sizeof(object) << endl;// 12, size of class classTest

	cout << *ptr << endl;// 5; ptr now point to object.intVal1

	ptr++;// Incrementing the *ptr by 1, it will now point to object.intVal2

	cout << *ptr << endl;// 10; *ptr now point to object.intVal2

	ptr++;// Incrementing the *ptr by 1, it will now point to object.charVal

	// Cast int pointer *ptr to char pointer *ch
	/*
		As *ptr now point to object.charVal, it needs to have the same type to
		access to object.charVal so we need a casting here
	*/
	char* ch = reinterpret_cast<char*>(ptr);

	cout << *ch << endl;// *ch now point to object.charVal

	ch++;// Incrementing the *ch by 1, it will now point to object.boolVal

	// Cast char pointer *ch to bool pointer *b
	/*
		As *ch now point to object.boolVal, it needs to have the same type to
		access to object.boolVal so we need a casting here
	*/
	bool* b = reinterpret_cast<bool*>(ch);
	cout << *b << endl;

	// We can also use this line of code to print the value pointed by (*ch)
	// cout << *(reinterpret_cast<bool*>(ch));

	return 0;
}
```