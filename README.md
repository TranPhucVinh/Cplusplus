# Cplusplus

C++ document and software for Unix-based applications, followed its OS architecture.

## G++ compiler

``g++ main.cpp``

As ``G++`` can compile all library belong with to ``GCC`` like ``stdio.h``, ``stdlib.h``, ``string.h``... so all ``GCC`` library and their functions can be included inside a ``CPP`` program.

**Example**

Stream out with ``printf()``

```cpp
#include <iostream>
#include <stdio.h> //For printf

using namespace std;

main(){
	cout << "Hello, World!" << endl;
    printf("Hello, World!\n");
}
```

## GCC compiler

``gcc test.cpp``: This will give **linking error** because of missing linker

```cpp
gcc test.cpp -lstdc++
```

This will normally compile a ``CPP`` file with ``C`` syntax:

**Example**: ``test.cpp``

```cpp
#include <stdio.h>

main(){
	printf("hello");
}
```