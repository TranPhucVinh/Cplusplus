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
