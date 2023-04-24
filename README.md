# About

Documents, implementation and examples for:

* C++ software for Unix-based applications, followed its OS architecture.
* Fundamental C++ programming concepts

# OS

Main OS: Ubuntu 16.04

Other OS:

* Windows (specifically noted on any software that are built on Windows)
* WSL Ubuntu 18.04

# G++ compiler

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

# GCC compiler

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

# C++ standard

| Standard| __cplusplus output |
| ------- |:------:|
|C++98    | 199711    |
|C++11    | 201103  |
|C++14| 201402|
|C++17|201500 or 201703 |

GCC version with C++ standard

```
GCC Version   C++ Standard
4.9             C++11
5               C++14
6               C++14
7               C++17
8               C++17
9               C++20
```

Environment variable ``__cplusplus`` is the C++ standard value:

```cpp
cout << __cplusplus << endl;
```

Compile G++: ``g++ test.cpp``. Result: ``199711``

Compile G++ with specific standard, e.g ``C++14``: ``g++ -std=c++14 test.cpp``.  Result: ``201402``

## C++11

Those features are supported since C++11:

* [thread with thread class](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Thread.md)
* [std::move](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/README.md#stdmove)
* Pointer: [nullptr](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/Pointer.md#nullptr), [rvalue reference](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/Pointer.md#rvalue-reference)
## C++17
* [filesystem](Physical%20layer/File%20IO#filesystem)
* [Template parameter pack](Introduction/Function/Template.md#template-with-class-as-type)
