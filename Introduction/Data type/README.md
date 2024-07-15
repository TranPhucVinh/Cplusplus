# [Base number system](Base%20number%20system.md)

* [binary](Base%20number%20system.md#binary)
* [hex](Base%20number%20system.md#hex)
* [dec](Base%20number%20system.md#dec)
* [oct](Base%20number%20system.md#oct)
# Float
Format a floating-point number to print with a specific number of decimal places
```cpp
#include <iostream>
#include <iomanip> // Include the header for std::setprecision

int main() {
    double number = 3.14159;
    std::cout << std::fixed << std::setprecision(2) << number << std::endl;// 3.14

    return 0;
}
```
Float has comparatively less precision compared to double and is used to store decimal numbers with fewer digits.
# Double 
Double has almost twice the precision as float and is used to store decimal numbers with more digits. It has a 32-bit floating-point precision according to IEEE.

This example convert a string number to float and double then perform the percentage calculation. With float, it gives the wrong result
```cpp
string num_str = "7383692";
int discount = 36;

float price = stof(num_str) * (discount)/100.0;
stringstream price_ss;
price_ss << std::fixed << std::setprecision(2) << price;
cout << price_ss.str() << endl;// 2658129.00 -> WRONG, 2658129.12 is correct
```
Only double gives the right result
```cpp
double price = stod(num_str) * (discount)/100.0;
stringstream price_ss;
price_ss << std::fixed << std::setprecision(2) << price;
cout << price_ss.str() << endl; // 2658129.12
```
# isdigit()
Check if a character is a digit number
```cpp
char a = 'a', b = '1';
cout << std::isdigit(a) << endl; // 0 (false)
cout << std::isdigit(b) << endl; // 1 (true)
```
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
# enum

Since C++11, ``enum`` allows accessing its member with ``::``:

```c
enum enum_object {value0 = 10, value1, value2, value3, value4 = 10, value5 = 16, value6};
printf("%d\n", enum_object::value0);
```
## enum class

```c
#include <iostream>
using namespace std;
enum class enum_class : int
{
    int_1 = 0,
    int_2 = 1,
    int_3 = 1,
};

int main(){
    enum_class a;
    a = enum_class::int_1; 
    cout << int(a) << std::endl;

    /*  
        Must have conversion for std::cout
        Without int(), there will be error
    */
    cout << int(enum_class::int_1) << std::endl;//0
}
```
