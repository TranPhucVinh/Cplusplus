# Array
**Array as function parameter**

Beside the traditonal way to pass array as function parameter (which includes the array size), CPP allows passing the array by reference ([lvalue](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/lvalue.md#lvalue-function-with-pass-by-reference)) which also includes/is hard-coded the array size:

```cpp
/*
    Completely like this traditional way:
    void func(int a[2]) {}
*/
void func(int (&a)[2]) {
    for (int i = 0; i < 2; i++) std::cout << a[i] << std::endl;
}

int main(){
    int arr[2] = {123, 456};
    func(arr);//123 456
}
```

Using [template](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/Function/Template.md) is the only solution to allow **passing array as function parameter without using its size**
```cpp
template <typename T, int arr_size>
void func(T (&a)[arr_size]) {
    for (int i = 0; i < arr_size; i++) std::cout << a[i] << std::endl;
}

int main(){
    int arr[2] = {123, 456};
    func(arr);//123 456
}
```
# String

String document will include

* [Char array for string](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#char-array-for-string)
* [Char pointer for string](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#char-array-for-string)
* [std::string](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#stdstring)
* [stringstream](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#stringstream)

# JSON

Implement [JSON](JSON) with [nlohmann/json](https://github.com/nlohmann/json) library.

# [Vector](Vector)

# struct

``struct`` in CPP can be treated as a class as it supports all class feature: public, private, constructor, destructor, inheritance, polymorphism, virtual function and abstract class.

* [A struct works like a class](struct.md#a-struct-works-like-a-class)
* [Inheritance with struct](struct.md#inheritance-with-struct)
* [Pure virtual function and abstract class in struct](struct.md#pure-virtual-function-and-abstract-class-in-struct)
# [Stack](Stack)
* Build stack with array: [stack_with_array.cpp](Stack/stack_with_array.cpp)
* Build stack with array which support multiple data type by using [template](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/Function/Template.md): [stack_genertic.cpp](Stack/stack_genertic.cpp)
# Queue

Create a queue to store all int variable then read all those value.

```cpp
#include <iostream>
#include <queue>
  
using namespace std;

void readAllObjectFromQueue(queue<int> queueObjectParam){
    while (!queueObjectParam.empty()) {
        cout << '\t' << queueObjectParam.front();
        queueObjectParam.pop();
    }
    cout << '\n';
}

int main()
{
    queue<int> queueIntObject;//Declare a queue that accepts int value
    queueIntObject.push(1);
    queueIntObject.push(2);
    queueIntObject.push(3);

    readAllObjectFromQueue(queueIntObject);
    return 0;
}
```
# enum

Since C++11, ``enum`` allows accessing its member with ``::``:

```c
enum enum_object {value0 = 10, value1, value2, value3, value4 = 10, value5 = 16, value6};
printf("%d\n", enum_object::value0);
```
## enum class

```c
#include <iostream>
using namespace std;
enum class enum_class : int
{
    int_1 = 0,
    int_2 = 1,
    int_3 = 1,
};

int main(){
    enum_class a;
    a = enum_class::int_1; 
    cout << int(a) << std::endl;

    /*  
        Must have conversion for std::cout
        Without int(), there will be error
    */
    cout << int(enum_class::int_1) << std::endl;//0
}
```
