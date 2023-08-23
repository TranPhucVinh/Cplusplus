# [Base number system](Base%20number%20system.md)

* [hex](Base%20number%20system.md#hex)
* [dec](Base%20number%20system.md#dec)
* [oct](Base%20number%20system.md#oct)
# [Explicit type conversion](Explicit%20type%20conversion.md)
Beside conventional [explicit type conversion](https://github.com/TranPhucVinh/C/blob/master/Introduction/Data%20type/Type%20conversion.md#explicit-type-conversion) performed in C, CPP supports explicit type conversion with ``cast``:

* [static_cast](Explicit%20type%20conversion.md#static_cast)
* [dynamic_cast](Explicit%20type%20conversion.md#dynamic_cast)
* [const_cast](Explicit%20type%20conversion.md#const_cast)
* [reinterpret_cast](Explicit%20type%20conversion.md#reinterpret_cast)

Be not to confused the **explicit type conversion** to the **[explicit keyword](https://github.com/TranPhucVinh/Cplusplus/blob/master/Object-oriented%20programming/Constructor%20and%20destructor/Constructor.md#implicit-conversion-and-explicit-keyword)** which is used for the constructor function which only has one argument.
# auto keyword

``auto`` keyword is available since C++11 and allows to automatic deduct of the data type of an expression. ``auto`` in CPP doesn't work like [C auto](https://github.com/TranPhucVinh/C/tree/master/Introduction/Keywords#auto), which intended for local variable.

```cpp
#include <iostream>
#include <typeinfo>

using namespace std;

class autoClass{
  public:
    int a;
};

auto a = 10;
auto b = "Hello";
auto c = 1.23;
auto d = new autoClass();//d now is a pointer

int main()
{
  cout << a << endl;//10
  cout << b << endl;//Hello
  cout << c << endl;//1.23
  d->a = 10;
  cout << d->a << endl;//10
  
  //Then get type
  cout << typeid(a).name() << endl;//i
  cout << typeid(b).name() << endl;//PKc
  cout << typeid(c).name() << endl;//d
  cout << typeid(d).name() << endl;//P9autoClass
}
```

Must not use auto for array like this: ``auto d[3] = {1, 2, 3};//Must not used``

``auto`` in for loop:

```cpp
int array[5] = {10, 20, 30, 40, 50};
for (auto i : array) {
    std::cout << i << "\n";
}
```
