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

As **std::string includes an internal dynamically allocated buffer**, there is no need to do any dynamically allocation for it.

## Define string with lvalue reference/reference declaration

[const std::string& str = "Hello, World !";](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/lvalue.md#define)

## Define char array as string with formatted std::string for used in snprintf()
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

# [Update](string%20update.md)
* [Append string at the last index](string%20update.md#append-string-at-the-last-index)
* [Append string at a specific index by std::string::insert()]()
* [std::string as function argument: Use function argument with lvalue to update string](string%20update.md#stdstring-as-function-argument-use-function-argument-with-lvalue-to-update-string)
* [Conversion std::string to other data type](string%20update.md#conversion)

# Delete

To clear a ``string``, use **clear()** and **erase()**:

```cpp
string displayed_string = "Hello World !";
cout << displayed_string << endl;//Hello World !
displayed_string.clear();
cout << displayed_string << endl;//(NULL)
```
```cpp
cout << displayed_string << endl;//Hello World !
displayed_string.erase();
cout << displayed_string << endl;//(NULL)
```
Delete **len** characters from index **idx**:
```cpp
string& string ::erase(size_type idx, size_type len)
```
```cpp
displayed_string.erase(1, 1);// Delete 1 character from index 1
cout << displayed_string << endl;// Hllo World !
```
