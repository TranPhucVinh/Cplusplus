# Pointer object of a class

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int public_number = 10;
		void hello(){
			cout << "Hello World \n";
		}
};

int main(){
	classTest *pointer_object, object;
	pointer_object = &object;
	pointer_object->hello(); //Hello World
	cout << pointer_object->public_number << endl; //10
}
```

**Note**: Pointer object of a class must be mapped to an object of that class. If not mapping, this pointer object will be a wild pointer and can't access the variable value of that object (cause **Segmentation fault** error)

```cpp
//This cause Segmentation fault error and must not be done
classTest *pointer_object;
cout << pointer_object->public_number << endl;//Segmentation fault
```

# Reference as function argument

Change value of variable by pointer in a function

```cpp
#include <stdio.h>
#include <stdint.h>

int a = 8;

int add_value(uintptr_t &a)
{
	return a+1;
}

int main(){
   printf("a: %d\n", a);
   printf("a: %d\n", add_value((uintptr_t&)a));
}
```
