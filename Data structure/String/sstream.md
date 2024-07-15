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
    stream << std::fixed << std::setprecision(2) << number;// Format the number with 2 decimal places
    displayedString += stream.str();

    std::cout << displayedString << std::endl;

    return 0;
}
```
# istringstream
istringstream allows you to create an input stream from a string, enabling you to use the same extraction operators (``>>``) and functions that you would use with other standard input streams (like ``std::cin``).

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string data = "123 456.78 Hello World";
    std::istringstream iss(data);
    
    int intVal;
    double doubleVal;
    std::string strVal1, strVal2;
    
    // Extract data from the string stream
    iss >> intVal >> doubleVal >> strVal1 >> strVal2;
    
    // Output the extracted values
    std::cout << "Integer: " << intVal << std::endl;
    std::cout << "Double: " << doubleVal << std::endl;
    std::cout << "String 1: " << strVal1 << std::endl;
    std::cout << "String 2: " << strVal2 << std::endl;

    return 0;
}
```
## Split a string to substring separated by spaces
```cpp
string data = "a bc cd Hello World";
istringstream iss(data);
string substr;

while (iss >> substr) { 
	cout << substr << endl;
}
```
