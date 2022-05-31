## Char array for string

```cpp
char displayString[] = "Hello, World !";
cout << displayString;
```

## Char pointer for string

```c
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

```c
char *displayedString;
displayedString = "Hello, World ! txt";

int main () {}
```

## string type

``string`` type are included ``iostream``.

Get character index of a string and size, length

```cpp
string displayed_string = "Hello World !";

cout << displayed_string[0] << endl; //H
cout << displayed_string.size() << endl;//13
cout << displayed_string.length() << endl;//13
```

Add character to a string with ``+``:

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

Using ``append()`` to append string to string:

```c
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

**Convert other data type to string**:

Using ``to_string()``: ``to_string()`` is only available in ``MS VC++``

Convert ``string`` to ``const char*``

```c
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

To clear a ``string``: ``clear()``

```cpp
string displayed_string = "Hello World !";
cout << displayed_string << endl;//Hello World !
displayed_string.clear();
cout << displayed_string << endl;//(NULL)
```

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

## stringstream

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
