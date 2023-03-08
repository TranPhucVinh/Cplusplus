* Insertion operator: ``<<``
* Extraction operator: ``>>``

# Header file

### hpp file

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

The primary difference between ``const`` and ``constexpr`` variables is that the initialization of a ``const`` variable can be deferred until run time, i.e the value of the ``const`` variable is sent to it at runtime. A ``constexpr`` variable must be initialized at compile time.

``x`` declared as ``constexpr`` can't be changed by pointer, not like ``const``.

```c
#include <iostream>
#include <stdio.h>

volatile constexpr int x = 123;

int main()
{
   int *ptr;
   ptr = (int*)&x;
   printf("%d\n", x);//123
   *ptr = 456;
   printf("%d\n", x);//456
	return 0;
}
```

# Examples

[Examples](Examples)
