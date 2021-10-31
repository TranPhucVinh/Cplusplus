Reference as function argument:

```c
#include <iostream>

int a = 8;
void foo(uintptr_t &object_ptr)
{
	object_ptr = (uintptr_t)&a;
}
```

**Example**: Get address of a variable then store into a pointer

Use a variable to store the address of other variable then changes that variable value with reference as function argument:

```c
#include <iostream>
#include <stdint.h>

using namespace std;

int a = 8;
int b = 10;

void foo(uintptr_t &object_ptr)
{
	object_ptr = (uintptr_t)&a;
}

int main()
{
    int* ptr;
    ptr = &b;   
  	cout << "*ptr: " << *ptr << endl;
  	foo((uintptr_t&)ptr); 

	  cout << "*ptr: " << *ptr << endl;
  	return 0;
}
```
