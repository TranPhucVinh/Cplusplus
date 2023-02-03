# nullptr

``nullptr`` is NULL pointer and is available since C++11.

```cpp
int *ptr = nullptr;
int a = 123;

ptr = &a;
std::cout << *ptr;//123
```

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

# uintptr_t

``uintptr_t`` is used to convert a pointer to integer. ``uintptr_t`` is ``unsigned __int64``.

```cpp
int a = 9;
uintptr_t *b = (uintptr_t*) &a;
std::cout << &a << " " << b << std::endl; //0x72fe14 0x72fe14
```

``uintptr_t`` can't be used to get the value of the pointer.

```c
//With define like above
std::cout << *b << " " << std::endl; //3236750919781, not 9 as value of variable a
```

**Note**: If defining pointer like this, there will be error

```cpp
uintptr_t *c = &a;
```

## Change value of variable by uintptr_t

Using ``uintptr_t*``:

```cpp
#include <stdio.h>
#include <stdint.h>

int a = 8;

void add_value(uintptr_t *a)
{
    *a += 1;
	return;
}

int main(){
   printf("a: %d\n", a);//8
   add_value((uintptr_t*)&a);
   printf("a: %d\n", a);//9
}
```

Using ``uintptr_t&``:

```cpp
int a = 8;
int add_value(uintptr_t &a)
{
	return a+1;
}

int main(){
   printf("a: %d\n", a);//8
   printf("a: %d\n", add_value((uintptr_t&)a));//9
}
```
