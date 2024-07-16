# [for_each()](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Function#for_each)

# std::find()
**std::find()** returns the **first occurrence** of a given element in a container. We can use this function with vectors and keep searching for the given element repeatedly till the end to find all the occurrences.
# std::min()
**std::min()** returns the min between 2 arguments
```cpp
int a = std::min(12, 34);
```
# std::min_element() and std::max_element()
Return min and max member of a sequence, along with their index in a vector
```cpp
#include <iostream>
#include <algorithm>    // std::min_element, std::max_element
#include <vector>

using namespace std;

int main () {
    vector<int> vect = {3, 7, 2, 5, 6, 4, 9};

    vector<int>::iterator min_iter = std::min_element(vect.begin(), vect.end());
    vector<int>::iterator max_iter = std::max_element(vect.begin(), vect.end());

    int min_index = std::distance(vect.begin(), min_iter);
    int max_index = std::distance(vect.begin(), max_iter);

    std::cout << "max number: " << *max_iter << " at index " << max_index << '\n';
    std::cout << "min number: " << *min_iter << " at index " << min_index << '\n';

    return 0;
}
```
For array
```cpp
int arr[] = {3, 7, 2, 5, 6, 4, 9};
int *max_element = std::max_element(arr, arr + sizeof(arr)/sizeof(int));

cout << *max_element << endl;// 9
```
# std::lower_bound() and std::upper_bound()

In a sorted array with duplicated number, std::lower_bound() and std::upper_bound() will return the index of a duplicated number in range [first,last) 

```cpp
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound
#include <vector>       // std::vector

int main () {
    std::vector<int> vec_num = {1, 1, 1, 2, 2, 4, 4};

    std::vector<int>::iterator low, up;

    int target = 2;// first index is 2, last index is 4
    low = std::lower_bound(vec_num.begin(), vec_num.end(), target);
    up = std::upper_bound(vec_num.begin(), vec_num.end(), target);

    std::cout << "lower_bound at position " << (low - vec_num.begin()) << '\n';// 3
    std::cout << "upper_bound at position " << (up - vec_num.begin()) << '\n'; // 5

    target = 3;// Inside the number range of vec_num but doesn't exist
    low = std::lower_bound(vec_num.begin(), vec_num.end(), target);// 5
    up = std::upper_bound(vec_num.begin(), vec_num.end(), target);// 5
    if (*low != target) std::cout << target << " doesn't existed in vec_num\n";

    target = 5;// out of range of vec_num
    low = std::lower_bound(vec_num.begin(), vec_num.end(), target);// 7
    up = std::upper_bound(vec_num.begin(), vec_num.end(), target);// 7
    if (*low != target) std::cout << target << " doesn't existed in vec_num\n";

    return 0;
}
```
**std::lower_bound()** and **std::upper_bound()** has the complexity of O(log2(N)+1) which is faster than binary search of the complexity of O(log(n))
# all_of()
Check member of a sequence in a range for a specific condition
```cpp
std::all_of(start_index, end_index, bool_function_for_conditional_check);
```

```cpp
vector<int> vec1 = {2, 4, 6}, vec2 = {1, 3, 5, 7};

cout << std::all_of(vec1.begin(), vec1.end(), [](int i){return i%2;}) << endl; // 0 (false) as all vec1 members are even numbers
cout << std::all_of(vec2.begin(), vec2.end(), [](int i){return i%2;}) << endl; // 1 (true) as all vec2 members are odd numbers
```
