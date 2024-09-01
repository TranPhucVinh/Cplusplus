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

As a unique pointer only points to an object at a time, passing it as the argument to a function must use [std::move()](Fundamental%20concepts.md#using-stdmove-to-completely-move-value-from-2-unique-pointers) or [lvalue](../Reference/lvalue.md).

## Use std::move()

```c
#include <iostream>
#include <memory>

using namespace std;

void unique_ptr_func(std::unique_ptr<int> uniquePtr) {
    std::cout << *uniquePtr << std::endl;//123
}

int main() {
	std::unique_ptr<int> uniquePtr = std::make_unique<int>(123);
	std::cout << *uniquePtr << std::endl;//123
	unique_ptr_func(std::move(uniquePtr));
}
```
## Use lvalue
```cpp
#include <iostream>
#include <memory>

using namespace std;

void unique_ptr_func(std::unique_ptr<int> &uniquePtr){
    std::cout << *uniquePtr << std::endl;//123
}

int main() {
	std::unique_ptr<int> uniquePtr = std::make_unique<int>(123);
	std::cout << *uniquePtr << std::endl;//123
	unique_ptr_func(uniquePtr);
}
```
# Unique pointer array as function argument
```cpp
void unique_ptr_func(std::unique_ptr<int[]> uniquePtr){
	// Have to hardcode the size if not using template
	for (int i = 0; i < 2; i++) std::cout << uniquePtr[i] << std::endl;
}

int main() {
	std::unique_ptr<int[]> uniquePtr(new int[2]);

	uniquePtr[0] = 123;
	uniquePtr[1] = 456;

	unique_ptr_func(std::move(uniquePtr));
}
```
Using [template](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/Function/Template.md) so that array size is not hardcoded:
```cpp
#include <iostream>
#include <memory>

#define ARR_SIZE 2

using namespace std;

template <typename T, int arr_size>
void func(std::unique_ptr<T[]> array) {
    for (int i = 0; i < arr_size; i++) std::cout << array[i] << std::endl;
}

int main() {
	std::unique_ptr<int[]> uniquePtr(new int[ARR_SIZE]);

	uniquePtr[0] = 123;
	uniquePtr[1] = 456;

	func<int, ARR_SIZE>(std::move(uniquePtr));
}
```
# Update unique pointer array as function argument
We must use lvalue for the unique pointer array as function argument in order to changes its member's value
```cpp
void unique_ptr_func(std::unique_ptr<int[]> &uniquePtr){
	for (int i = 0; i < 2; i++) uniquePtr[i] = i;
}

int main(){
	std::unique_ptr<int[]> uniquePtr(new int[2]);

	unique_ptr_func(uniquePtr);

	for (int i = 0; i < 2; i++) cout << uniquePtr[i] << endl;
}
```
# Unique pointer as function argument of template function
```cpp
#include <iostream>
#include <typeinfo>
#include <memory>

template <typename dummy_type> void add_function(std::unique_ptr<dummy_type> a, std::unique_ptr<dummy_type> b){
    std::cout << "Add 2 unique ptr number: *a + *b = " << *a + *b << std::endl;
}

int main () {
	std::unique_ptr<int> a = std::make_unique<int>(123);
	std::unique_ptr<int> b = std::make_unique<int>(456);

    add_function<int>(std::move(a), std::move(b));//579

	std::unique_ptr<float> c = std::make_unique<float>(12.3);
	std::unique_ptr<float> d = std::make_unique<float>(45.6);

	add_function<float>(std::move(c), std::move(d));//57.9
}
```
