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

# std::string

## [Operations](string%20operations.md)

### Basic operations

* [Create and Read](string%20operations.md#create-and-read)
* Update: [Append](string%20operations.md#append-string), [std::string as function argument](string%20operations.md#stdstring-as-function-argument), [convert other data type to string](string%20operations.md#conversion)
* [Delete](string%20operations.md#delete)

### Other operation

* [find with find()](#stringfind)
* [compare with compare()](#stringcompare)

## API

### string::find()

```c
size_t find (const string& str, size_t pos = 0) const;
```

Find if a string is matched with ``str``(as a substring), start finding from index ``0`` by default.

**Return**:

* The position of the first character of the first match, as ``std::size_t found``
* If no matches were found, the function returns ``string::npos``

```c
#include <string>//string::npos

string str = "Hello, World !";
if ( std::size_t index = str.find("Hello") != string::npos) cout << str << endl;
```
### string::compare()

```cpp
int compare (const string& str) const;
```
**Return**: ``0`` if string is matched.

```cpp
string str = "Hello";
int ret = str.compare("Hello");
if (!ret) cout << str;
else cout << "Not equal";
```
**Result**: ``Hello``
### stoi()
Convert string to int; return the first occurence int numbers inside the given ``string s`` **if and only if** ``string s`` starts with numbers:
```cpp
int stoi (string s, size_t* position = 0, int base = 10);
```
```cpp
std::string number = "123";
std::cout << stoi(number, 0, 10) << std::endl;
std::cout << stoi("12a34") << std::endl;// 12
```
```cpp
// This will give error: 'std::invalid_argument'
stoi("abc123");// MUST NOT DO THIS
```
### substr()
```cpp
string substr (size_t pos = 0, size_t len = npos);// Split from position "pos" with "npos" of characters
string substr (size_t pos = index);// Split from position "pos=index" till the end
```
```cpp
#define START_POSITION          2
#define TOTAL_CHARS_TO_SPLIT    5
std::string str = "Hello,World !";
std::string sub_str_1 = str.substr(START_POSITION, TOTAL_CHARS_TO_SPLIT);// llo,W
std::string sub_str_2 = str.substr(1);// Split from index "1" till the end of str; Result: "ello,World !"
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
