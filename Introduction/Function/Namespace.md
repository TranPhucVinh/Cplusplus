# Fundamental concepts

A ``namespace`` is a declarative region that provides a scope to the identifiers (names of the types, function, variables etc) inside it.

``namespace`` declarations appear only at global scope.

``namespace`` is a feature added in C++ and not present in C.

``using namespace std`` is used for ``cout``, ``cin``, ``endl``.

# namespace for variables

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

# namespace for variables and functions

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
# namespace in header file
``header.h``
```cpp
#include <iostream>

namespace hdr_file
{
    int a = 123;
    void display_string(){
        std::cout << "Display string in header file\n";
   }
}
```
``main.cpp``
```cpp
#include <iostream>
#include "header.h"

using namespace hdr_file;

int main(){
	std::cout << hdr_file::a << std::endl;
    hdr_file::display_string();
}
```
# Unnamed namespace

Unnamed namespace is used to limit the scope of its variable and function to be inside its source file, as [internal linkage](https://github.com/TranPhucVinh/C/blob/master/Introduction/Linkage.md#internal-linkage), so that the same function names and variables can be reused in other files. In this manner, unnamed namespace behaves like [global static variable and global static function](https://github.com/TranPhucVinh/C/blob/master/Introduction/Keywords/static.md#global-static-variable-and-static-function).

``head1.c``

```c
#include <stdio.h>

namespace
{
    int a = 123;
    void display_string(){
        printf("Display string in head1.c\n");
    }
}

void head1(){
    display_string();
    printf("head1 a %d\n", a);
}
```
``head2.c``
```c
#include <stdio.h>

namespace
{
    int a = 456;
	void display_string(){
		printf("Display string in head2.c\n");
	}
}

void head2(){
	display_string();
	printf("head2 a %d\n", a);
}
```
``main.c``
```c
#include <stdio.h>

void head1();
void head2();

int main(){
	head1();
	head2();
}
```
**Result**
```
Display string in head1.c
head1 a 123
Display string in head2.c
head2 a 456
```
# using keyword for template

In template, the **using** keyword is used to:
1. Bring a specific member from the namespace into the current scope.
2. Bring all members from the namespace into the current scope.

**Example**

* Bring member ``number`` from namespace ``name_space`` into ``main()``
* Bring the entire ``std`` namespace in the current scope

```c
#include <iostream>

using namespace std;//Bring the entire std namespace in the current scope

namespace name_space
{
    int number = 2;
}

using name_space::number;//bringing number to current scope

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
# using keyword is similar to typedef

Define ``std::vector<int>`` as ``Vector_Int`` by using keyword, this is similar to typedef:

```cpp
using Vector_Int = std::vector<int>;
Vector_Int vec{10, 20, 30};
```
