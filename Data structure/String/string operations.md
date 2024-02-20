# Create and read

``string`` type are included ``iostream``.

Get character index of a string and size, length

```cpp
std::string displayed_string = "Hello World !";

std::cout << displayed_string[0] << std::endl; //H
std::cout << displayed_string.size() << std::endl;//13
std::cout << displayed_string.length() << std::endl;//13

//Define std::string with const
const std::string const_str = "const string";
std::cout << const_str << std::endl;
```
**[constexpr](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/README.md#constexpr) can't be used for std::string**.
## Define string with lvalue reference/reference declaration

[const std::string& str = "Hello, World !";](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/lvalue.md#define)

## Define string with formatted string for used in snprintf()
```cpp
std::string displayed_string = "String: %s ";
char buffer[50];

snprintf(buffer, 50, displayed_string.c_str(), "Hello, World !");
printf("%s", buffer);//String: Hello, World ! 
 ```

## Set default value for a string

```cpp
std::string displayed_string("Hello, World !");// Set default value for displayed_string
std::cout << displayed_string << std::endl; //Hello, World !

//Then change the value of displayed_string
displayed_string = "Another new string";
std::cout << displayed_string << std::endl; //Another new string
```

# Update

## Append string

Using **append()** to append string to string:

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

Using **+** operator to add a character to a string (same operation for a new empty string):

```cpp
std::string displayString = "Hello, World ";
displayString += "123";
std::cout << displayString << endl;//Hello, World 123
```
**Note**: With ``+`` operator on ``string``, only character is allowed to add. Number are not allow:

```cpp
//This is wrong and must not be done although this give no compilation error
cout << displayString + 123;
```
**Result**: ``lled after throwing an instance of '!``

Append a **reference declaration string** with **+** operator:

```cpp
std::string appended = "123";
const std::string& str = "Hello, World !";//Must define with const
std::cout << str + appended << std::endl;//Hello, World !123
std::cout << str + " 456" << std::endl;//Hello, World ! 456
```
## std::string as function argument
Use function argument with lvalue to update string:

```cpp
void change_str(string &hw){
    hw = "new string";
}

int main(){
	   string str = "Hello, World !";
    cout << str << "; " << str.size() << endl;
   	change_str(str); //Hello, World ! 14
    cout << str << "; " << str.size() << endl;
}
```
## Conversion

**std::to_string()**, which is supported sinced C++11, is used to convert data type like int, float to **std::string()**; for **const char*** to **std::string**, simply use explicit cast with **std::string()**:
```cpp
#include <iostream>

#define NAME "NAME"

std::string displayedString = "Hello, World !";

int main(){
    const char *const_char_str = "const_char_str";
    std::cout <<  std::string(const_char_str) << std::endl;// Hello, World !456 

    displayedString +=  std::to_string(456) + " ";
    std::cout << displayedString << std::endl;// Hello, World !456 
    displayedString +=  std::to_string(12.34);
    std::cout << displayedString << std::endl;// Hello, World !456 12.340000
    displayedString +=  NAME;
    std::cout << displayedString << std::endl;// Hello, World !456 12.340000NAME
}
```

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

Unable to converted the ``std::string`` returned from function by ``c_str()``:

```c
string returnedString;

const char *pointerString;//Must be const char for later conversion

string returnStringFunction(){
    return "Hello, World ! text";
}

int main(){
    pointerString = returnStringFunction().c_str();
    cout << pointerString;// NULL; pointerString is NULL
}
```

**Convert std::string to char stringArray[100] using c_str()**

```cpp
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
