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

# Reference declaration

By using ``&b`` reference declaration, ``&b`` will store the address of ``a`` (as ``&a``).

Pointer can be defined with ``uintptr_t`` (as unsigned int pointer): ``uintptr_t *c`` 

```cpp
int a = 9;
int &b = a;
uintptr_t *c = (uintptr_t*) &a;
std::cout << a << " " << b << std::endl; //9 9
std::cout << &a << " " << &b << std::endl;//0x72fe04 0x72fe04
std::cout << &a << " " << c << std::endl;//0x72fe04 0x72fe04
```

**Note**: If defining pointer like this, there will be error

```cpp
uintptr_t *c = &a;
```

Reference declarion for ``std::string``:

```c
const std::string& str = "Hello, World !";//Must define with const
cout << str << endl;//Hello, World !
cout << &str << endl;//0x4d5060
```

### Reference as function argument with ``uintptr_t``

Change value of variable by pointer in a function. 

Using ``uintptr_t*``:

```cpp
#include <stdio.h>
#include <stdint.h>

int a = 8;

int add_value(uintptr_t *a)
{
	return *a+1;
}

int main(){
   printf("a: %d\n", a);//8
   printf("a: %d\n", add_value((uintptr_t*)&a));//9
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
