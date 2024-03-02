Multiple shared pointer can point to one object at a time, and those pointer will share/maintain a **reference counter** to count how many share pointers have been accessed to this object. **Reference counter** can be accessed by using the ``use_count()`` method.

Shared pointer is properly supported since C++14.

```cpp
#include <iostream>
#include <memory>

using namespace std;

int main(){
    std::shared_ptr<int> sharedPtr_1 = std::make_shared<int>(123);
	std::shared_ptr<int> sharedPtr_2;
	sharedPtr_2 = sharedPtr_1; 

	std::cout << &sharedPtr_1 << std::endl;//0x72fdf0
	std::cout << *sharedPtr_1 << std::endl;//123

	std::cout << &sharedPtr_2 << std::endl;//0x72fde0, different address from sharedPtr_1
	std::cout << *sharedPtr_2 << std::endl;//123

    std::cout << sharedPtr_1.use_count() << std::endl;//2
    std::cout << sharedPtr_2.use_count() << std::endl;//2, same as sharedPtr_1
}
```
# Implementations
* [Create and read all members of a linked list by shared pointer]()