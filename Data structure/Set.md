# Define set
std::set is an associative container that contains a sorted set of unique object

CPP set doesn't support accessing elements by index using the [] operator. Sets are implemented as binary search trees or hash tables, which do not have a linear ordering like arrays or vectors.

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
# Use set to check if an array only existed a set of number
E.g check if array ``arr`` only contains 1,2,3:
* arr = {1, 2, 3} -> return true;
* arr= {1, 2, 2,3} -> return true;
* arr= {1, 2, 2,4} -> return false, as 4 is included

```cpp
bool checkSet(const std::vector<int>& arr, const std::set<int>& allowedSet) {
    std::set<int> uniqueNumbers;

    for (int num : arr) {
        uniqueNumbers.insert(num);
    }

    return uniqueNumbers == allowedSet;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3};
    std::set<int> allowedSet1 = {1, 2, 3};
    std::cout << std::boolalpha << checkSet(arr1, allowedSet1) << std::endl; // Output: true

    std::vector<int> arr2 = {1, 2, 2, 3};
    std::set<int> allowedSet2 = {1, 2, 3};
    std::cout << std::boolalpha << checkSet(arr2, allowedSet2) << std::endl; // Output: true

    std::vector<int> arr3 = {1, 2, 2, 4};
    std::set<int> allowedSet3 = {1, 2, 3};
    std::cout << std::boolalpha << checkSet(arr3, allowedSet3) << std::endl; // Output: false

    return 0;
}
```
