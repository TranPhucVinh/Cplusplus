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
## Found all substring occcurrence inside a string
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
## Split a string into substrings by a delimiter, e.g a space
```cpp
vector<string> splitStringByDelimiter(string s, string delim) {
    vector<string> all_substr;
    std::size_t index = s.find(delim, 0);
    string sub_str  = s.substr(0, index);
    string new_string = s.substr(index+1);

    while (index != string::npos) { 
        if (sub_str != delim && sub_str.size() >= 1) {
            all_substr.push_back(sub_str);
        }

        index = new_string.find(delim, 0);
        sub_str  = new_string.substr(0, index);
        new_string = new_string.substr(index+1);
    }

    if (sub_str != delim && sub_str.size() >= 1) {
        all_substr.push_back(sub_str);
    }

    for (int i = 0; i < all_substr.size(); i++){
        cout << all_substr[i] << endl;
    }
    return all_substr;
}
```
Test cases:
1. "Hello, World !"
2. "          H e llo,          world !         "

# Form a full string from substrings
Reform the original full string from substrings which are separated from that original string by space
```cpp
// Take splitStringByDelimiter() from "Split a string into substrings by a delimiter" as the input
string formStringFromSubstr(vector<string> all_substr) {
    string full_str;
    for (int i = 0; i < all_substr.size(); i++){
        full_str += all_substr[i] + " ";
    }
    full_str.erase(full_str.size() - 1, 1);// Delete the last " " character of full_str

    return full_str;
}
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
std::cout << stoi(number, 0, 10) << std::endl;// 123
std::cout << stoi("12a34") << std::endl;// 12
std::cout << stoi("100", 0, 2) << std::endl;// 4; convert binary string 100 to decimal number 0d4
```
```cpp
// This will give error: 'std::invalid_argument'
stoi("abc123");// MUST NOT DO THIS
```
To convert only the string which contains only numbers, use ``all_of()`` to check:
```cpp
std::string number = "123a";

if (all_of(number.begin(), number.end(), ::isdigit)) std::cout << stoi(number) << std::endl;
else std::cout << "String doesn't contain only numbers";
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
# replace()
``replace()`` is used to replace a substring of a string, start at index i, with the length of ``length``:
```cpp
std::string str = "Hello, World!";

// Indices to replace from (i) and to (j)
int i = 7;
int j = 12;

std::string replacement = "Universe";// Replacement string

str.replace(i, j - i, replacement);

std::cout << "Modified string: " << str << std::endl;// Modified string: Hello, Universe!
```
