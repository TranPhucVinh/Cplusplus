## Fundamental concepts

* [For-each loop](#for-each-loop)
* [Initializer list](#initializer-list)
* [Function overloading and function default arguments](Function.md)
* [Namespace](Namespace.md)
* [Template](Template.md)

## For-each loop

C++ support the for-each loop which is introduced in C++ version 11 (2011):

```c
for (type variableName : arrayName) {
  // code block to be executed
}
```

```c
#include <iostream>

int main()
{
    int array[5] = {10, 20, 30, 40, 50};
    for (int i : array) {
        std::cout << i << "\n";
    }
}
```

## Initializer list

Initializer list is a method to initialize a variable's value. Initializer list ``{}`` is only available from C++11 and above:

```cpp
#include <iostream>

int main()
{
    int value {};
    std::cout << value << std::endl;//0

	int number {123};
    std::cout << number << std::endl;//123
    return 0;
}
```

## algorithm library header

```c
#include <iostream>
#include <algorithm>//For min_element

using namespace std;

int main() {
	int a = std::min(12, 34);
	cout << a << endl;
}
```
