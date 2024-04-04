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
