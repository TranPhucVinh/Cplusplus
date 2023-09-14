# Array as function parameter

Beside the traditonal way to pass array as function parameter (which includes the array size), CPP allows passing the array by reference ([lvalue](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/lvalue.md#lvalue-function-with-pass-by-reference)) which also includes/is hard-coded the array size:

```cpp
/*
    Completely like this traditional way:
    void func(int a[2]) {}
*/
void func(int (&a)[2]) {
    for (int i = 0; i < 2; i++) std::cout << a[i] << std::endl;
}

int main(){
    int arr[2] = {123, 456};
    func(arr);//123 456
}
```

Using [template](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/Function/Template.md) is the only solution to allow **passing array as function parameter without using its size**
```cpp
template <typename T, int arr_size>
void func(T (&a)[arr_size]) {
    for (int i = 0; i < arr_size; i++) std::cout << a[i] << std::endl;
}

int main(){
    int arr[2] = {123, 456};
    func(arr);//123 456
}
```
# std::array
std::array is a part of the STL
```cpp
#include <iostream>
#include <array>

using namespace std;
int main()
{
    std::array<int, 3> int_arr = {1, 2, 3};
    cout << int_arr[2] << endl;//3
}
```
**As function parameter**
```cpp
void arr_func(std::array<int, 3> int_arr){
    cout << int_arr[2] << endl;
}

int main()
{
    std::array<int, 3> int_arr = {1, 2, 3};
    arr_func(int_arr);
}
```
Using template is to pass array as function parameter without using its size
```cpp
template <typename T, size_t arr_size>
void func(std::array<T, arr_size> arr) {
    for (int i = 0; i < arr_size; i++) std::cout << arr[i] << std::endl;
}

int main(){
    std::array<int, 2> int_arr = {123, 456};
    func(int_arr);//123 456
    std::array<float, 2> float_arr = {12.34, 45.67};
    func(float_arr);//12.34 45.67
}
```
