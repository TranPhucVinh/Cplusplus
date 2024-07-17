# Create
## Create and read all member of a deque

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq = {1, 2, 3, 4, 5};

    // Iterate with index
    for (int i = 0; i < dq.size(); i++) {
        std::cout << dq[i] << " ";
    }
    std::cout << std::endl;

    // Iterate with iterator
    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
## push_back()
Insert element at the back
```cpp
std::deque<int> dq = {1}; // 1
dq.push_back(2);// 1 2
```
## push_front()	
Insert element at the front
```cpp
std::deque<int> dq = {1, 2}; // 1 2
dq.push_front(3);// 3 1 2
```
## Insert member at a specific index
```cpp
std::deque<int> dq = {1, 2, 3, 4, 5};
int index = 2;
dq.insert(dq.begin() + index, 123);// 1 2 123 3 4 5
```
# Read

* ``[]`` and **at()**: Read element at specified index
* **front()**: Read element at the front
* **back()**: Read element at the back
```cpp
std::deque<int> dq = {1, 2, 3};

std::cout << dq[2] << std::endl;// 3
std::cout << dq.at(2) << std::endl;// 3
std::cout << dq.back() << std::endl;// 3
std::cout << dq.front() << std::endl;// 1
```
# Update
Update at specific index
```cpp
std::deque<int> dq = {1, 2, 3};
dq[2] = 5;// 1 2 5
```
# Delete
* ``pop_back()``: remove the element from the back
* ``pop_front()``: removes the element from the front
```cpp
std::deque<int> dq = {1, 2, 3};
dq.pop_back();// 1 2
dq.pop_front();// 2
```
