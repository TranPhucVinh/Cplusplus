# Fundamental concepts

[A unique pointer is a pointer which can only point to an object at a time](Unique%20pointer.md#using-stdmove-to-completely-move-value-from-2-unique-pointers). We can assign a different object by removing the current one from the unique pointer. With that feature, we will use unique pointer when we want to have single ownership (exclusive) of a resource.

Unique pointer is supported since **C++11**. Include ``<memory>`` to use it. ``std::make_unique()`` is supported since **C++14**.

# Unique pointer allows setting value to its deferencing

Unlike normal pointer which doesn't allow setting value to its dereferencing, unique pointer allows this operation:
## Use std::make_unique<>()

```cpp
#include <iostream>
#include <memory>

using namespace std;

int main(){
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(123);
    /*
    	Must not call this, it gives compilation error
    	std::cout << uniquePtr << std::endl;
    */
    std::cout << &uniquePtr << std::endl;//0x7fff13475d50
    std::cout << *uniquePtr << std::endl;//123
}
```
You cannot use **std::make_unique** with a [custom deleter](). Only the [unique pointer direct method declaration](#use-stdunique_ptrnew-directly) allow [custom deleter]().

## Use std::unique_ptr<>(new) directly
```cpp
std::unique_ptr<int> uniquePtr;
uniquePtr = std::unique_ptr<int>(new int(123));

std::cout << &uniquePtr << std::endl;//0x7fff13475d50
std::cout << *uniquePtr << std::endl;//123
```
Or declaring directly:
```cpp
std::unique_ptr<int> uniquePtr(new int(987));
```
For ``auto`` keyword:
```cpp
auto uniquePtr = std::unique_ptr<int>(new int(123));
```
The direct ``std::unique_ptr<>(new)`` declaration allow using [custom deleter]().
# Unique pointer for array
## Initialize directly
```cpp
std::unique_ptr<int[]> uniquePtr(new int[2]);

uniquePtr[0] = 123;
uniquePtr[1] = 456;

std::cout << &uniquePtr << std::endl;//0x7fff13475d50
std::cout << uniquePtr[0] << std::endl;//123
std::cout << uniquePtr[1] << std::endl;//456
```
## Initialize by std::make_unique
```cpp
std::unique_ptr<int[]> uniquePtr;
uniquePtr = std::make_unique<int[]>(2);

uniquePtr[0] = 123;
uniquePtr[1] = 456;
```
## [Unique pointer array as function argument](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/Smart%20pointer/Unique%20pointer%20and%20function.md#unique-pointer-array-as-function-argument), using [template](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/Function/Template.md) so that array size is not hardcoded.
## Unique pointer for char array as string

```cpp
std::unique_ptr<char[]> strPtr{new char[40]};

strcpy(strPtr.get(), "Hello, World !");
std::cout << strPtr.get() << std::endl;//Hello, World !
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

In this example, we can see the object with address ``0x7fff13475d50`` can only be point at one time respectively by ``uniquePtr1`` and ``uniquePtr2``.
	
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
# Using .get() to copy unique pointer value to normal pointer
```cpp
int *p;
std::unique_ptr<int> uniquePtr = std::make_unique<int>(123);

p = uniquePtr.get();

std::cout << p << std::endl;//  0x7e4c20
std::cout << *p << std::endl;// 123

// By using get(), uniquePtr doesn't lose its value and can still be access normally
std::cout << &uniquePtr << std::endl;// 0x7ffffcebc750
std::cout << *uniquePtr << std::endl;// 123
```
# Unique pointer as class object

```cpp
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
	std::cout << "Program finished\n";
}
```
```
Constructor of classTest
Hello, World !
Program finished
Destructor of classTest
```
From the result, we can see that the unique pointer as class object is destroyed when the program ended
