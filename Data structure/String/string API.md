# find()

```c
size_t find (const string& str, size_t pos = 0) const;
```

Find if a string is matched with ``str``(as a substring), start finding from index ``0`` by default.

**Return**:

* The position of the first character of the first match, as ``std::size_t found``
* If no matches were found, the function returns ``string::npos``

```c
string str = "123 Hello123456Hello789Hello";
std::size_t index = str.find("Hello");
if ( index != string::npos) cout << index << endl;// 4
```
Found all substring cccurrence inside a string:
```cpp
int found = 0;
string str = "123 Hello123456Hello789Hello";
std::size_t index = str.find("Hello", 0);

cout << "Substring \"Hello\" occurred at indices: "; 
while (index != string::npos) { 
    found += 1;
    cout << index << " ";
    index = str.find("Hello", index + 1);
} 
cout << endl;
cout << "Total found: " << found << endl;
```
# compare()

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
# stoi()
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
# substr()
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
