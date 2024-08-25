# Hash map
A **hash table**, also known as a **hash map** or a **hash set**, is a data structure that implements an associative array, also called a dictionary, which is an abstract data type that maps keys to values.
# Hash function
A **hashing algorithm** or **hash function**, is a calculation applied to a key, which might be a very large number or a very long string, to transform it to a relatively small indexed number that corresponds to a position in the hash table.

``std::hash`` is supported since C++11

```c
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
