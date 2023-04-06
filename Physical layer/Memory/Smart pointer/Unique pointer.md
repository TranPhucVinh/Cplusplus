Unique pointer is supported since C++11. Include ``<memory>`` to use it.

``std::make_unique`` is supported since C++14.

# Unique pointer allows setting value to its deferencing

Unlike normal pointer which doesn't allow setting value to its dereferencing, unique pointer allows this operation:

```c
#include <iostream>
#include <memory>

using namespace std;

int main(){
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(123);
    std::cout << &uniquePtr << std::endl;//0x7fff13475d50
    std::cout << *uniquePtr << std::endl;//123
}
```

# Unique pointer doesn't allow sharing

**Unique** in unique pointer means it doesn't allow sharing that pointer. Unlike normal pointer which can be assigned to many variables address, unique pointer doesn't allow that.

<table>
<tr>
<td> Unique pointer </td> <td> Normal pointer </td>
</tr>
<tr>
  <td> 

  ```cpp
  int a = 19;
  std::unique_ptr<int> uniquePtr = std::make_unique<int>(123);
  uniquePtr = &a;// Compilation error, must not do that
  ```

  </td>
  <td>

  ```c
  int a = 1, b = 2;
  int *p = &a;
  printf("variable value %d \n", *p); //1
  p = &b;
  printf("variable value %d \n", *p); //2
  ```
  </td>
</tr>
</table>

# Using std::move to completely move value from 2 unique pointers

```cpp
std::unique_ptr<int> uniquePtr1 = std::make_unique<int>(123);

std::cout << &uniquePtr1 << std::endl;//0x7fff13475d50
std::cout << *uniquePtr1 << std::endl;//123

std::unique_ptr<int> uniquePtr2;
// Must not do this
// uniquePtr2 = uniquePtr1; -> This will give compilation error
uniquePtr2 = std::move(uniquePtr1);

std::cout << &uniquePtr2 << std::endl;//0x7fff13475d50, same address of uniquePtr1
std::cout << *uniquePtr2 << std::endl;//123

/*
	After std::move() uniquePtr1 to uniquePtr2, uniquePtr1 will lost all of its 
	value. Accessing it from now result in segmentation fault
*/
// std::cout << &uniquePtr1 << std::endl;//Segmentation fault
// std::cout << *uniquePtr1 << std::endl;//Segmentation fault
```
# Unique pointer for class object

```c
class classTest{
	public:
        classTest(){
			cout << "Constructor of classTest\n";
		}
        ~classTest(){
			cout << "Destructor of classTest\n";
		}
        void displayString() {
            std::cout << "Hello, World !\n";
        }
};

int main(){
    std::unique_ptr<classTest> object = std::make_unique<classTest>();

    // As object is an unique pointer so it access the class member by ->
    object->displayString();
}
```
