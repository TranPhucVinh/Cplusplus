# Define set
**std::set** is an associative container that contains a **sorted sequence of unique objects**

**std::set** doesn't support accessing elements by index using the [] operator. Sets are implemented as binary search trees or hash tables, which do not have a linear ordering like arrays or vectors.

To print all elements of a set, you need to iterate over the set using iterators or range-based for loops:
    
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> Set = {3, 1, 4, 1, 5, 9, 2, 6}; // Define a set with some initial values

    std::cout << "Set size: " << Set.size() << std::endl;// Set size: 7
    for (std::set<int>::iterator it = Set.begin(); it != Set.end(); ++it) {
        std::cout << *it << " ";
    }
    // Result: 1 2 3 4 5 6 9
    return 0;
}
```
# Add member to a set
**insert()**:
```cpp
std::set<int> Set;
Set.insert(1);
Set.insert(1);// This is duplicated so it won't be inserted to Set
Set.insert(2);

std::cout << "Set size: " << Set.size() << std::endl;// Set size: 7
for (std::set<int>::iterator it = Set.begin(); it != Set.end(); ++it) {
    std::cout << *it << " ";
}
// Result: 1 2
```
# Read set value at the specific index
```cpp
int main() {
    std::set<int> Set = {3, 1, 4, 1, 5, 9, 2, 6}; // Define a set with some initial values
    // Set: 1 2 3 4 5 6 9

    std::cout << read_by_index(Set, 6) << std::endl;// 9
    
    return 0;
}

int read_by_index(std::set<int> Set, int index){
    int _index = 0;
    for (std::set<int>::iterator it = Set.begin(); it != Set.end(); ++it) {
        if (_index == index) return *it;
        else _index += 1;
    }
    return -1;
}
```
# Find index of a number in set
```cpp
std::set<int> Set = {1, 2, 3, 4, 5, 6, 9}; // Then define that Set
int value = 5; // Then define that value
std::set<int>::iterator it = Set.find(value);
if (it == Set.end()) {
    std::cout << "Not found " << value;
} else std::cout << "Found " << value << " at " << *it;
```
# Remove value from set

```cpp
int numberToRemove = 1;
Set.erase(numberToRemove);
```
# Use set to check if an array only existed a set of number
E.g check if array ``arr`` only contains 1,2,3:
* arr = {1, 2, 3} -> return true;
* arr = {1, 2, 2, 3} -> return true;
* arr = {1, 2, 2, 4} -> return false, as 4 is included
* arr = {1, 2} -> return true
* arr = {3} -> return true

Program: [set_check_if_array_existed_a_set_of_numbers.cpp]()
# Find all missing numbers in a strictly increasing order array

* arr = [2,3,4,7,11], the missing numbers are {1, 5, 6, 8, 9, 10}
* arr = [5,6,7,8,9], the missing numbers are {1, 2, 3, 4}
* arr = [1,2,3,4]: No missing

Program: [set_find_missing_numbers_in_increasing_order_array.cpp]()
