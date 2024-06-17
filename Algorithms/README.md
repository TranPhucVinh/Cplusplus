# Read
* for_each()
* std::find()
* [std::min()](Read.md#stdmin); [std::min_element() and std::max_element()](Read.md#stdmin_element-and-stdmax_element)
* std::lower_bound() and std::upper_bound()
# Update
## std::sort()
**std::sort()** for sorting an array with **Time Complexity** of **O(N*logN)**. By default, std::sort() **sorts the sequence in ascending/non-decreasing order**.

### Sort an array
```cpp
#include <iostream>
#include <algorithm>    // std::sort

#define SIZE 6

int array[SIZE] = {34, 12, 135, 45, 1, 9};

int main(){
    std::cout << "Array before: \n";
    for (int i=0; i < SIZE; i++){
		std::cout << array[i] << " ";
	}
    std::cout << "\n";

	std::sort(array, array + SIZE);

    std::cout << "Array after: \n";
    for (int i=0; i < SIZE; i++){
		std::cout << array[i] << " ";
	}
    std::cout << "\n";
}
```
### Sort a vector
```cpp
std::vector<int> vec{34, 12, 135, 45, 1, 9};

std::sort(vec.begin(), vec.end());

for (int i=0; i < vec.size(); i++){
	std::cout << vec[i] << " ";
}
```
### Sort a string array
```cpp
string str[] = {"b", "a", "abd", "ab","abc"};
std::sort(str, str + 5);
std::cout << endl;
for (int i=0; i < 5; i++){
	std::cout << str[i] << " ";
}// a ab abc abd b
```
### Sort in descending order
```cpp
std::sort(vec.begin(), vec.end(), std::greater<int>());
```
### Third argument of std::sort()
**std::sort()** takes the third argument as a comparator function with 2 arguments. This example will arrange the vector in descending order:
```cpp
// Everytime calling this function, 2 adjacent members a, b in vec will be arranged so that a > b
bool customComparator(int a, int b) {
    return a > b;
}

int main() {
    std::vector<int> vec = {5, 2, 9, 3, 7};

    std::sort(vec.begin(), vec.end(), customComparator);

    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
## std::reverse()
Reverse a sequence, e.g string, vector
```cpp
std::string str = "123";
std::reverse(str.begin(), str.end());
std::cout << str; // 321
```
Reverse a string from its beginning to a specific index, e.g ``4``:
```cpp
std::string str = "123456789";
std::string::iterator index = str.begin() + 4;
std::reverse(str.begin(), index);
std::cout << str; // 432156789
```
Reverse the whole vector:
```cpp
vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};

vector<int>::iterator iter = vec.begin();
std::reverse(vec.begin(), vec.end()); // 9 8 7 6 5 4 3 2 1
```
Reverse from ``START`` to ``END`` index of a vector:
```cpp
#define START 3
#define END   6

vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};

vector<int>::iterator iter, start_iter, end_iter;
iter = vec.begin();
start_iter  = iter + START;
end_iter    = iter + END;

std::reverse(start_iter, end_iter);
```

**std::reverse()** returns void, so don't assign it to any variable.
## std::rotate()
``std::rotate()`` rotates a sequence. For **left rotation**, move the first element of a sequence to its end. For **right rotation**, move the last element of a sequence to its first.

```cpp
std::rotate(first, middle, last);
```
* **first**: the beginning of the sequence
* **middle**: the element that should appear at the beginning of the rotated sequence
* **last**:	the end of the original sequence
```cpp
#include <algorithm>

int arr[] = {5, 1, 4, 3, 7, 6};

std::rotate(arr, arr + 1, arr + 6);
for (int i = 0; i < 6; i++) cout << arr[i] << " ";// 1 4 3 7 6 5
```
Left rotate a string:
```cpp
std::rotate(str.begin(), str.begin() + 1, str.end());// Middle must not be str[1]
```
Left rotate a vector:
```cpp
std::rotate(vect.begin(), vect.begin() + 1, vect.end());
```
Right rotate a vector:
```cpp
std::rotate(vect.begin(), vect.end() - 1, vect.end());
```
