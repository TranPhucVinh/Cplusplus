# [for_each()](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Function#for_each)

# std::find()
**std::find()** returns the **first occurrence** of a given element in a container. We can use this function with vectors and keep searching for the given element repeatedly till the end to find all the occurrences.
# std::min()
**std::min()** returns the min between 2 arguments
```cpp
int a = std::min(12, 34);
```
# std::lower_bound() and std::upper_bound()

In a sorted array with duplicated number, std::lower_bound() and std::upper_bound() will return the index of a duplicated number in range [first,last) 

```cpp
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound
#include <vector>       // std::vector

#define TARGET 2 // first index is 2, last index is 4

int main () {
    std::vector<int> vec_num = {1, 1, 1, 2, 2, 3, 3};

    std::vector<int>::iterator low, up;
    low = std::lower_bound(vec_num.begin(), vec_num.end(), TARGET);
    up = std::upper_bound(vec_num.begin(), vec_num.end(), TARGET);

    std::cout << "lower_bound at position " << (low - vec_num.begin()) << '\n'; // 3
    std::cout << "upper_bound at position " << (up - vec_num.begin()) << '\n';  // 5

    return 0;
}
```
**std::lower_bound()** and **std::upper_bound()** has the complexity of O(log2(N)+1) which is faster than binary search of the complexity of O(log(n))
