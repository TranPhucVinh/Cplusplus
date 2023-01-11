# string type

## Create and read

``string`` type are included ``iostream``.

Get character index of a string and size, length

```cpp
string displayed_string = "Hello World !";

cout << displayed_string[0] << endl; //H
cout << displayed_string.size() << endl;//13
cout << displayed_string.length() << endl;//13
```

**Define string with reference declaration**: [const std::string& str = "Hello, World !";](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/Pointer.md#reference-declaration)

Append a reference declaration string with ``+``:

```c
string appended = "123";
const std::string& str = "Hello, World !";//Must define with const
cout << str + appended << endl;//Hello, World !123
cout << str + " 456" << endl;//Hello, World ! 456
```

Add character to a string with ``+`` to read:

```cpp
string displayString = "Hello, World ";
cout << displayString+'!'; //Hello, World !
```
**Note**: With ``+`` operator on ``string``, only character is allowed to add. Number are not allow:

```cpp
//This is wrong and must not be done although this give no compilation error
cout << displayString + 123;
```
**Result**: ``lled after throwing an instance of '!``



## Update

### Append string

Using ``append()`` to append string to string:

```cpp
string displayString = "Hello, World ";

cout << displayString.append("!") << endl; //Hello, World !
cout << displayString.append("!") << endl; //Hello, World !!
```

Using ``push_back()``:

```cpp
string displayed_string = "Hello World !";
displayed_string.push_back('A');//Hello World !A
```

``string`` type has no member ``pop_back()``.

Using ``+`` to append an existing string (same operation for a new empty string):

```c
string displayString = "Hello, World ";
displayString += "123";
cout << displayString << endl;//Hello, World 123
```

### Convert other data type to string

Using ``to_string()``: ``to_string()`` is only available in ``MS VC++``

Convert ``string`` to ``const char*`` using c_str():

```cpp
#include <iostream>

using namespace std;

string displayedString = "Hello, World !";

const char *pointerString;//Must be const char for later conversion

int main(){
    pointerString = displayedString.c_str();
    cout << pointerString;
}
```

Unable to converted the ``string`` function with ``c_str()``:

```c
string returnedString;

const char *pointerString;//Must be const char for later conversion

string returnStringFunction(){
    return "Hello, World ! text";
}

int main(){
    pointerString = returnStringFunction().c_str();
    cout << pointerString;
}
```

``pointerString`` is Null.


**Convert string to char stringArray[100] using c_str()**

```c
#include <iostream>
#include <string.h> //for strcpy()

using namespace std;

string returnedString;

char stringArray[100];
const char* tempConstantString; //Must be const char for later conversion

string returnStringFunction(){
    return "Hello, World ! text";
}

int main(){
    returnedString = returnStringFunction();
    tempConstantString = returnedString.c_str();
    strcpy(stringArray, tempConstantString);
    cout << stringArray;
}
```

## Delete

To clear a ``string``, using ``clear()``:

```cpp
string displayed_string = "Hello World !";
cout << displayed_string << endl;//Hello World !
displayed_string.clear();
cout << displayed_string << endl;//(NULL)
```
 
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

**Forming stringstream when using int and uint8_t**:

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

Note that ``ss2 << "ss2 " << int_value`` will concatenate the string ``ss2`` and int value ``int_value`` normally while ``ss1 << "ss1 " << value`` will convert the ``uint8_t value`` ``48`` to its ASCII symbol ``0`` then perform converting to ``ss1 0``.

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
