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

Sorting for array:
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
**Sorting for vector**:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

#define SIZE 6

int main(){
    std::vector<int> vec{34, 12, 135, 45, 1, 9};
    std::cout << "Vector before: \n";
    for (int i=0; i < SIZE; i++){
		std::cout << vec[i] << " ";
	}
    std::cout << "\n";

	std::sort(vec.begin(), vec.end());

    std::cout << "Array after: \n";
    for (int i=0; i < SIZE; i++){
		std::cout << vec[i] << " ";
	}
    std::cout << "\n";
}
```
# std::reverse()
Reverse a sequence, e.g a string
```cpp
std::string str = "123";
std::reverse(str.begin(), str.end());
std::cout << str; // 321
```
