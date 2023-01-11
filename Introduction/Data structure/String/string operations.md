# Create and read

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

# Update

## Append string

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

## Convertion

Using ``to_string()``: ``to_string()`` is only available in ``MS VC++``

Convert ``string`` to ``const char*`` using ``c_str()``:

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

Convert char array to string:

```cpp
char ch[] = "Hello, World 11111";
string str(ch);
cout << str;
```

# Delete

To clear a ``string``, using ``clear()``:

```cpp
string displayed_string = "Hello World !";
cout << displayed_string << endl;//Hello World !
displayed_string.clear();
cout << displayed_string << endl;//(NULL)
```
