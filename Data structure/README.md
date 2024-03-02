# [Array](Array.md)
# [Vector](Vector)
# String

String document will include

* [Char array for string](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#char-array-for-string)
* [Char pointer for string](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#char-array-for-string)
* [std::string](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#stdstring)
* [stringstream](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#stringstream)
# Linked list
Create and read all members of a linked list by:
* [Raw pointer](src/linked_list_raw_ptr.cpp)
* [Shared pointer](src/linked_list_shared_ptr.cpp). Unique pointer can't be used to traverse the linked list created by it.

# JSON

Implement [JSON](JSON) with [nlohmann/json](https://github.com/nlohmann/json) library.

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
# Container
A container, in CPP, is a holder object that stores a collection of other objects (its elements). The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators.

**Sequence containers** implement data structures that can be accessed sequentially. 

There are 5 sequence containers implemented in STL:

* array: Static contiguous array (class template)
* vector: Dynamic contiguous array (class template)
* deque: Double-ended queue (class template)
* forward_list: Singly-linked list (class template)
* list: Doubly-linked list (class template)

**Container adapters** provide a different interface for sequential containers. 

There are 3 container adapter implemented in STL:
* stack: Adapts a container to provide stack (LIFO data structure) (class template).
* queue: Adapts a container to provide queue (FIFO data structure) (class template).
* priority_queue: Adapts a container to provide priority queue (class template). 

**Associative containers** implement sorted data structures that can be quickly searched (O(log n) complexity).

**Unordered associative** containers implement unsorted (hashed) data structures that can be quickly searched
