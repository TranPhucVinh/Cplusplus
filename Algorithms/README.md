# [for_each()](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Function#for_each)

# std::find()
**std::find()** returns the first occurrence of a given element in a container. We can use this function with vectors and keep searching for the given element repeatedly till the end to find all the occurrences.
# std::min()
```cpp
#include <iostream>
#include <algorithm>//For min_element

using namespace std;

int main() {
	int a = std::min(12, 34);
	cout << a << endl;
}
```
# std::sort()
**std::sort()** for sorting an array with **Time Complexity** of **O(N*logN)**

## Sort an array
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
## Sort a vector
```cpp
#define SIZE 6

std::vector<int> vec{34, 12, 135, 45, 1, 9};

std::sort(vec.begin(), vec.end());

for (int i=0; i < SIZE; i++){
	std::cout << vec[i] << " ";
}
```
## Sort a string array
```cpp
string str[] = {"b", "a", "abd", "ab","abc"};
std::sort(str, str + 5);
std::cout << endl;
for (int i=0; i < 5; i++){
	std::cout << str[i] << " ";
}// a ab abc abd b
```
# std::reverse()
Reverse a sequence, e.g a string
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
**std::reverse()** returns void, so don't assign it to any variable.
# std::remove()

Remove all occurence of a member in a sequence, e.g array, vector,..

**Remove all member, which has value VALUE in an array**
```cpp
#define VALUE  20

int array[] = {10,20,30,30,20,10,10,20};

for (int i = 0; i < 8; i++){
	std::cout << array[i] << " ";
}
std::cout <<"\n";

int *ptr_begin = array;
int* ptr_end = array + sizeof(array)/sizeof(int); 

std::remove(ptr_begin, ptr_end, VALUE);

// After removing 3 20 members, there are 5 member left in array
for (int i = 0; i < 5; i++){
	std::cout << array[i] << " ";
}
std::cout <<"\n";
```
For vector:
```cpp
std::vector<int> vec{10,20,30,30,20,10,10,20};
for (int i = 0; i < vec.size(); i++){
	std::cout << vec[i] << " ";
}
std::cout <<"\n";

std::remove(vec.begin(), vec.end(), VALUE);

for (int i = 0; i < vec.size(); i++){
	std::cout << vec[i] << " ";
}// Result: 10 30 30 10 10 ? ? ? i.e size of vector vec is unchanged after calling std::remove()
```
**Note**: From the array and vector implementations above, we can see that using **std::remove()** don't change the array/vector size.
