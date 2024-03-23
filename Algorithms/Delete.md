# std::remove()

Remove all occurence of a member in a sequence, e.g array, vector,...

**std::remove()** returns the pointer to the end member of the new sequence, which is useful for resizing.

**Remove all member with value VALUE in an vector, then resize that vector**
```cpp
#define VALUE  20
std::vector<int> vec{10,20,30,30,20,10,10,20};
for (int i = 0; i < vec.size(); i++){
    std::cout << vec[i] << " ";
}
std::cout <<"\n";

std::vector<int>::iterator new_iter = std::remove(vec.begin(), vec.end(), VALUE);
int new_sz = std::distance(vec.begin(), new_iter);// New size

for (int i = 0; i < new_sz; i++){
    std::cout << vec[i] << " ";
}
```

**Note**: Call **std::remove()** won't change the vector size,  **std::distance()** must be called to get the new size.

**For array**:
```cpp
int array[] = {10,20,30,30,20,10,10,20};

int *ptr_begin = array;
int* ptr_end = array + sizeof(array)/sizeof(int); 

ptr_end = std::remove(ptr_begin, ptr_end, VALUE);

int new_sz = std::distance(array, ptr_end);// New size
```
**Note**: From the array and vector implementations above, we can see that using **std::remove()** don't change the array/vector size.
## std::unique()
``std::unique()`` remove all except the first element from every consecutive group of equivalent elements from the range.

Example of an consecutive group: ``{1, 1, 5, 5, 3, 3, 3}``.

**Remove all consecutive duplicates member inside an array**:
```cpp
#include <iostream>
#include <algorithm>

int remove_all_duplicates(int arr[], int arr_sz) {
    // Use std::unique to move duplicates to the end of the array
    int* end_ptr = std::unique(arr, arr + arr_sz);

    // Calculate the new array size after removing all duplicates members
    int new_sz = std::distance(arr, end_ptr);// New size

    return new_sz;
}

int main() {
    int array[] = {13, 13, 1, 1, 2, 2, 5, 5, 3, 3, 4, 4, 4};
    int arr_sz = sizeof(array) / sizeof(int);

    // Remove duplicates
    int new_sz = remove_all_duplicates(array, arr_sz);

    for (int i = 0; i < new_sz; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
**Remove all consecutive duplicates member inside a vector, then resize it**
```cpp
vector<int> vec = {13, 13, 1, 1, 2, 2, 5, 5, 3, 3, 4, 4, 4};

int remove_all_duplicates(vector<int> &vec) {
    vector<int>::iterator last = std::unique(vec.begin(), vec.end());

    int new_sz = std::distance(vec.begin(), last);// New size

    return new_sz;
}

int main() {
    int new_sz = remove_all_duplicates(vec);

    vec.resize(new_sz);

    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
