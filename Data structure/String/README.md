# std::string

## [Operations](string%20operations.md)

* [Create and Read](string%20operations.md#create-and-read), **std::string includes an internal dynamically allocated buffer**
* Update: [Append](string%20operations.md#append-string), [std::string as function argument](string%20operations.md#stdstring-as-function-argument), [convert other data type to string](string%20operations.md#conversion)
* [Delete](string%20operations.md#delete)

## [API](string%20API.md)
* [find()](#stringfind): [Found all substring occcurrence inside a string](string%20API.md#found-all-substring-occcurrence-inside-a-string), [Split a string into substring separated by space](string%20API.md#split-a-string-into-substrings-by-a-delimiter-eg-a-space)
* [compare()](string%20API.md#compare)
* [stoi(): convert string to int]()
* [substr()](string%20API.md#substr)
# [sstream](sstream.md)
* stringstream
* istringstream
# [Implementations](Implementations.md)

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
