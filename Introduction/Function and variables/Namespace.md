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

## using keyword

The ``using`` keyword is used to:
1. Bring a specific member from the namespace into the current scope.

**Bring a specific member from the namespace into the current scope**

Bring member ``number`` from namespace ``name_space`` into ``main()``:

```c
#include <iostream>

using namespace std;

namespace name_space
{
    int number = 2;
}

using name_space::number;

int main () {
    cout << number << endl;//2
    cout << name_space::number << endl;//2
}
```

If there is a variable with the same name to namespace member, there will be error:

```cpp
int number = 1;

namespace name_space
{
    int number = 2;
}
```

**Error**

```
test.cpp:14:19: error: 'int name_space::number' conflicts with a previous declaration
```
