# Fundamental concepts

A ``namespace`` is a declarative region that provides a scope to the identifiers (names of the types, function, variables etc) inside it.

``namespace`` declarations appear only at global scope.

``namespace`` is a feature added in C++ and not present in C.

``using namespace std`` is used for ``cout``, ``cin``, ``endl``.

**Example**: ``namespace`` for variables

```cpp
#include <iostream>
#include <stdio.h>

int number = 1;

// Variable created inside namespace
namespace name_space
{
    int number = 2;
}

int main () {
    printf("%d\n", number);//1
    printf("%d\n", name_space::number); //2
}
```

**Example**: ``namespace`` for variables and functions

```cpp
#include <iostream>
#include <stdio.h>

namespace ns1
{
    int return_number()    { return 1; }
}
namespace ns2 
{
    int number = 2;
    int return_number() { return 3; }
}

int main () {
    printf("%d\n", ns1::return_number());//1
    printf("%d\n", ns2::return_number()); //3
    printf("%d\n", ns2::number); //2
}
```