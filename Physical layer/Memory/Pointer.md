**Reference as function argument**: Change value of variable by pointer in a function

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
