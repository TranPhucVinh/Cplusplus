# Function overloading

```cpp
#include <iostream>

using namespace std;

void addNumbers(int a, int b){
    cout << a+b << endl;
}

void addNumbers(float a, float b){
    cout << a+b << endl;
}

void addNumbers(int a, int b, int c){
	cout << a+b+c << endl;
}

void addNumbers(void){
	cout << 3 << endl;
}

int main () {
    addNumbers(3, 4); //7
    addNumbers(3.0f, 4.0f); //7
	addNumbers(3, 4, 5); //12
	addNumbers(); //3
}
```

**Notice**  ``addTwoNumbers(3.0f, 4.0f)`` for float number, without ``f`` there will be error ``call of overloaded ‘addTwoNumbers(double, double)’ is ambiguous``, as ``addTwoNumbers(3.1, 4.1)`` is interpreted as double number.
# Different between overload and override/overloading and overriding
* **Overloading**: same method name but different parameters in the same class/same function name but different parameters in the same program.
* **[Overridding](https://github.com/TranPhucVinh/Cplusplus/blob/master/Object-oriented%20programming/Inheritance/Virtual%20function.md#override-keyword)**: Same method signature in both base class and derived class
# Name mangling
Name mangling, which is supported in CPP, not C, is the encoding of function and variable names into unique names so that linkers can separate common names in the language. Name mangling is implemented in function overloading so that the linker knows which functions to use.

```cpp
#include <iostream>

using namespace std;

void addNumbers(int a, int b){
    cout << a+b << endl;
}

void addNumbers(float a, float b){
    cout << a+b << endl;
}

int main () {
    addNumbers(3, 4); //7
    addNumbers(3.0f, 4.0f); //7
}
```

Checking the ``a.out`` from this source file by [nm](https://github.com/TranPhucVinh/C/blob/master/Environment/README.md#nm): ``nm a.out``

```
00000000004015ea T _Z10addNumbersff
00000000004015b0 T _Z10addNumbersii
```

It can be seen that ``addNumbers`` are encoded into ``_Z10addNumbersff`` (for ``addNumbers(float a, float b)``) and ``_Z10addNumbersii`` (for ``addNumbers(int a, int b)``).
