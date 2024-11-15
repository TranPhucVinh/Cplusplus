**new** and **delete** keywords are **only available in G++** and is not available in ``GCC``.

# new

```c
#include <stdio.h>

int main() {  
	int *int_number = new int;
	int *int_array = new int[2];
	*int_number = 12;
	int_array[0] = 1;
	int_array[1] = 2;
	printf("int_number: %d\n", *int_number); //12
	printf("int_array[1]: %d\n", int_array[1]); //2
}
```
Or can define:

```c
int *int_number;
int_number = new int;
*int_number = 23;
```

# delete

```c
int *int_number = new int;
*int_number = 12;
printf("int_number: %d\n", *int_number); //12
delete int_number;
printf("int_number: %d\n", *int_number); //0
```
Or can use:
```c
delete[] int_number;
```
# memset()

Calling ``memset()`` of ``cstring``

```cpp 
#include <cstring>

char str[] = "C programming with GNU-GCC";
memset(str,'$',7); //$$$$$$$amming with GNU-GCC
```

Or

```cpp
char str[] = "C programming with GNU-GCC";
::memset(str,'$',7); //$$$$$$$amming with GNU-GCC
```
# std::move

Available since C+11: ``g++ main.cpp -std=c++11``

Allow the efficient transfer of resources. **std::move()** is used for [the function argument as a rvalue](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/lvalue%20and%20rvalue.md#rvalue-as-function-argument).

## A simple variable

```c
int a = 10;
int b = std::move(a);
std::cout << b << std::endl;//10
std::cout << a << std::endl;//10; after calling std::move(), variable a still keeps its value
```

## A class object

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int publicNumber;
		void hello(int val){
			cout << "Value: " << privateNumer + val << endl;
		}
	private:
		int privateNumer = 2;
};

int main(){
	classTest object_1, object_2;
	object_1.publicNumber = 1;
	cout << object_1.publicNumber << endl; //1
	object_1.hello(1);//Value: 3

	object_2 = std::move(object_1);

	cout << object_2.publicNumber << endl; //1
	object_2.hello(1);//Value: 3
	
	// After calling std::move(), object object_1 still keeps its value
	cout << object_1.publicNumber << endl; //1
	object_1.hello(1);//Value: 3
}
```
# std::copy()
Copy an array to another one by ``std::copy()``
```cpp
int array[3];
int _array[] = {1, 2, 3};
std::copy(std::begin(_array), std::end(_array), std::begin(array));
```
``std::copy()`` for array as function argument
```cpp
void copy_array(int *_array, int size) {
    int *array = new int[size];

    std::copy(_array, _array + size, array);

    for (int i = 0; i < size; i++) std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main(){
    int _array[] = {1, 2, 3};
    copy_array(_array, sizeof(_array)/sizeof(int));
    
    return 0;
}
```
``std::copy()`` for vector as function argument
```cpp
void copy_vector(vector<int> _vec) {
    vector<int> vec(_vec.size()); // Must reserve size for the copied vector

    copy(_vec.begin(), _vec.end(), vec.begin());

    for (int i = 0; i < vec.size(); i++) std::cout << vec[i] << " ";
    std::cout << std::endl;
}

int main(){
    vector<int> _vec = {1, 2, 3};
    copy_vector(_vec);
    
    return 0;
}
```
