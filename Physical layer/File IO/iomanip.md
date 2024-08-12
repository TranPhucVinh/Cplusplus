# setw()

```cpp
#include <iostream>
#include <iomanip> // io manipulation
using namespace std;

main() {
	cout << "Day  		Money \n"
	<< 	"---------------------------------\n";
	cout << 1 << setw(18) << 1 << "\n";
	cout << 1 << setw(18) << 1 << "\n";
	cout << 1987 << setw(18) << 1977 << "\n";
}
```

**Result**

```
Day  		Money 
---------------------------------
1                 1
1                 1
1987          1977
```
# std::setfill
``std::setfill`` is used to set the character that will be used to fill spaces when outputting formatted data. ``std::setfill`` is usually used with ``std::setw`` to specify the width of the field to be printed.
```cpp
#include <iostream>
#include <iomanip>

int main() {
    int number = 42;

    std::cout << std::setw(5) << number << std::endl;// Output the number with a width of 5, using spaces as the default fill character

    std::cout << std::setfill('0') << std::setw(5) << number << std::endl;// Output the number with a width of 5, using '0' as the fill character

    std::cout << std::setfill('*') << std::setw(5) << number << std::endl;// Output the number with a width of 5, using '*' as the fill character

    return 0;
}
```
**Result**
```
   42
00042
***42
```
