## Fundamental concepts

* [Initializer list](#initializer-list)
* [Function overloading and function default arguments](Function.md)
* [Namespace](Namespace.md)
* [Template](Template.md)

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
