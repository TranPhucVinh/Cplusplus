# Hash map
A **hash table**, also known as a **hash map** or a **hash set**, is a data structure that implements an associative array, also called a dictionary, which is an abstract data type that maps keys to values.
# Hash function
A **hashing algorithm** or **hash function**, is a calculation applied to a key, which might be a very large number or a very long string, to transform it to a relatively small indexed number that corresponds to a position in the hash table.
# std::hash 
The ``std::hash`` class template is a general-purpose hash function used primarily for hashing keys. It is not a single function but a template that can be specialized for different types. Its core idea is to provide a lightweight, non-cryptographic hash function, i.e it doesn't provide security guarantees like cryptographic hash functions.

``std::hash`` is supported since C++11
## int
For integer types (int, long, etc.), std::hash by default just returns the integer itself or apply a bit shift to ensure better distribution.
```cpp
#include <iostream>

int main() {
    std::hash<int> int_hash;

    // Using operator() to get hash value
    std::cout << "Int hash values: " << int_hash(123) << std::endl;// Int hash values: 123
    return 0;
}
```
## string
```cpp
#include <iostream>

int main()
{
   std::string origin_str = "Hello, World !";
   std::hash<std::string> std_hash;
 
   // Using operator() to get hash value
   std::cout << "String hash values: " << std_hash(origin_str) << std::endl;
	return 0;
}
```
**Result** ``String hash values: 17643215542638042821``
