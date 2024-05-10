# std::string

## [Operations](string%20operations.md)

* [Create and Read](string%20operations.md#create-and-read), **std::string includes an internal dynamically allocated buffer**
* Update: [Append](string%20operations.md#append-string), [std::string as function argument](string%20operations.md#stdstring-as-function-argument), [convert other data type to string](string%20operations.md#conversion)
* [Delete](string%20operations.md#delete)

## [API](string%20API.md)
* [find()](#stringfind): [Found all substring occcurrence inside a string](), [Split a string into substring separated by space]()
* [compare()](#stringcompare)
* [stoi(): convert string to int]()
* [substr()](string%20API.md#substr)
# stringstream

``stringstream`` is a stream that doesn't do IO operation. It is used to read and write string

```c
#include <iostream>
#include <sstream>//std::stringstream

using namespace std;
stringstream ss1, ss2;

int main() {
    ss1 << 123 << " " << "Hello, World !";
    ss2.str("This is a string");
    cout << ss1.str() << endl;//123 Hello, World !
    cout << ss2.str() << endl;//This is a string

    //Then append ss1
    ss1 << " Append string";
    cout << ss1.str() << endl;//123 Hello, World ! Append string
}
```

After forming with ``ss2.str()``, ``ss2`` can't be appended with ``<<``

## Forming stringstream when using int and uint8_t

```c
stringstream ss1, ss2;
int int_value = 123;
uint8_t value = 48;

int main() {
	ss1 << "ss1 " << value;
	cout << ss1.str() << endl;//ss1 0

	ss2 << "ss2 " << int_value;
	cout << ss2.str() << endl;//ss2 123
}
```

Note that ``ss2 << "ss2 " << int_value`` will concatenate the string ``ss2`` and int value ``int_value`` normally while ``ss1 << "ss1 " << value`` will convert the ``uint8_t value`` ``48`` to its ASCII symbol ``0`` then perform converting to ``ss1 0``, as G++ will treat **std::cout** with **uint8_t** as a character symbol.

For clearing the contents of a stringstream, using: ``ss.str("")``

Value formed by stringsteam can be splitted by ``space``.

Add and read value with ``stringstream``:

```c
#include <iostream>
#include <sstream>//std::stringstream

using namespace std;
stringstream ss;

int a;
string b, c;
int main() {
    //Add value to ss
    ss << 123 << " " << "Hello, World !";

    //Read value from ss
    ss >> a;
    cout << a << endl;//123

    ss >> b;
    cout << b << endl;//Hello,

    ss >> c;
    cout << c << endl;//World
}
```
## Floating point format with stringstream
```cpp
#include <iostream>
#include <iomanip> // Include for std::fixed and std::setprecision
#include <string>

int main() {
    std::string displayedString;
    double number = 12.34;

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << number;    // Format the number with 2 decimal places
    displayedString += stream.str();

    std::cout << displayedString << std::endl;

    return 0;
}
```
# Applications
* Parse a complex number with this format "1+1i", "123+-456i",... into their real and img part (e.g real = 123, imagine = -456); and do multiply between 2 complex numbers: [string_complex_number_parsing.cpp](src/string_complex_number_parsing.cpp)

# Char array for string

```cpp
char displayString[] = "Hello, World !";
cout << displayString;
```

# Char pointer for string

```cpp
char *displayedString;

int main(){
    displayedString = "Hello, World !";
    cout << displayedString;//Hello, World !
}    
```

Compile with both ``G++`` and ``GCC`` gives warning:

```
warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
```

Compile error with G++ and GCC:

```cpp
char *displayedString;
displayedString = "Hello, World ! txt";

int main () {}
```
