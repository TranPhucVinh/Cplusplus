A tuple is an object that can hold multiple elements with different data types.

# Create and read all value of a tuple

```cpp
#include <iostream>
#include <tuple>
using namespace std;

int main()
{
	tuple <char, int, float, std::string> tuple_obj;

	// Assigning values to tuple using make_tuple()
	tuple_obj = make_tuple('a', 123, 45.6, "Hello, World !");

	std::cout << get<0>(tuple_obj) << " " 
	<< get<1>(tuple_obj) << " " << get<2>(tuple_obj) << 
	" " << get<3>(tuple_obj) << std::endl;
	return 0;
}
```

```
a 123 45.6 Hello, World !
```

# Update value of tuple object

```cpp
tuple <char, int, float, std::string> tuple_obj;

// Assigning values to tuple using make_tuple()
tuple_obj = make_tuple('a', 123, 45.6, "Hello, World !");

std::cout << "Before updating:";
std::cout << get<0>(tuple_obj) << " " 
<< get<1>(tuple_obj) << " " << get<2>(tuple_obj) << 
" " << get<3>(tuple_obj) << std::endl;

get<0>(tuple_obj) = 'b';
get<1>(tuple_obj) = 456;
get<2>(tuple_obj) = 78.9;
get<3>(tuple_obj) = "New string";

std::cout << "After updating:";
std::cout << get<0>(tuple_obj) << " " 
<< get<1>(tuple_obj) << " " << get<2>(tuple_obj) << 
" " << get<3>(tuple_obj) << std::endl;
```