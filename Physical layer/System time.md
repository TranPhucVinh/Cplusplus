Check ``System time.md`` in ``C/Physical layer`` for 3 examples as their implementations are identical:

**Example 1**

* Get current time with ``time.h`` 
* Get day, month and year with ``localtime()``
* Get current time of day in Unix-alike system

**Example 2**: Delay for a number of seconds

**Example 3**: Print out a string after every one second with ``sleep()``

General define for those 3 examples

```c
#include <iostream>

using namespace std;
```

Use ``cout`` to print out