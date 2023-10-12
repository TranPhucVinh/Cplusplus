# Function returns a unique pointer
```cpp
#include <iostream>
#include <memory>

using namespace std;

std::unique_ptr<int> return_unique_ptr(){
	std::unique_ptr<int> _uniquePtr = std::make_unique<int>(123);
	return _uniquePtr;
}

int main(){
	std::unique_ptr<int> uniquePtr = return_unique_ptr();
	std::cout << *uniquePtr << std::endl;//123
}
```
# Unique pointer as function argument

As a unique pointer only points to an object at a time, passing it as the argument to a function must use [std::move()](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/Smart%20pointer/Unique%20pointer.md#using-stdmove-to-completely-move-value-from-2-unique-pointers) or [lvalue](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/lvalue.md):

Using [std::move()](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/Smart%20pointer/Unique%20pointer.md#using-stdmove-to-completely-move-value-from-2-unique-pointers)

```c
#include <iostream>
#include <memory>

using namespace std;

void unique_ptr_func(std::unique_ptr<int> uniquePtr){
    std::cout << *uniquePtr << std::endl;//123
}

int main(){
	std::unique_ptr<int> uniquePtr = std::make_unique<int>(123);
	std::cout << *uniquePtr << std::endl;//123
	unique_ptr_func(std::move(uniquePtr));
}
```
Using [lvalue](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/lvalue.md):
```cpp
#include <iostream>
#include <memory>

using namespace std;

void unique_ptr_func(std::unique_ptr<int> &uniquePtr){
    std::cout << *uniquePtr << std::endl;//123
}

int main(){
	std::unique_ptr<int> uniquePtr = std::make_unique<int>(123);
	std::cout << *uniquePtr << std::endl;//123
	unique_ptr_func(uniquePtr);
}
```