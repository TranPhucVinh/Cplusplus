* Insertion operator: ``<<``
* Extraction operator: ``>>``

# Header file

## hpp file

``.hpp`` file is header file like ``.h`` file. Its usage is identically to ``.h`` file.

Example: ``header.hpp``

```h
#include <iostream>
#ifndef header_hpp
#define header_hpp
//Other definitions go here
```

# Keywords

## constexpr

``constexpr`` can be understand simply as a constant.

There are 2 difference between [const](https://github.com/TranPhucVinh/C/blob/master/Introduction/Keywords/README.md#const) and ``constexpr`` variables:

1. The initialization of a ``const`` variable can be deferred until run time, i.e the value of the ``const`` variable is sent to it at runtime. A ``constexpr`` variable must be initialized at compile time.

2. A ``constexpr`` variable can't be changed by pointer, not like [const (change value of a const by pointer)](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Memory/Pointer/Implementations.md#change-value-of-a-variable-with-pointer).

```c
#include <iostream>

volatile constexpr int x = 123;

int main()
{
	int *ptr;
	ptr = (int*)&x;
	printf("%d\n", x);//123
	*ptr = 456;
	printf("%d\n", x);//123, not changed to 456
	return 0;
}
```
