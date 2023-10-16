# Fundamental concepts

* [for-each](#for-each) and [for_each](#for_each)
* [Function overloading](#function-overloading)
* [Name mangling]()
* [Function default arguments](#default-arguments)
* [Namespace](Namespace.md)
* [Template](#template)
* [Lambda](Lambda.md)

# for-each

C++ support the for-each loop which is introduced in C++ version 11 (2011):

```cpp
for (type variableName : arrayName) {
  // code block to be executed
}
```

```cpp
#include <iostream>

int main()
{
    int array[5] = {10, 20, 30, 40, 50};
    for (int i : array) {
        std::cout << i << "\n";
    }
}
```
for-each loop doesn't support getting the index value, i.e: ``array[5]`` in the example above won't support this:

```
0: 10
1: 20
2: 30
...
```
``index`` of array must be got by traditional for loop.

Be not to confused for-each with for_each, which is part of the STL and included in ``<algorithm>``.
# for_each
```cpp
for_each (InputIterator start_iter, InputIterator last_iter, Function fnc);
```
``fnc/obj_fnc``: a function or an object function which operation would be applied to each element. This function must have only 1 argument which is the current element in the current iteration.

```cpp
#include <iostream>
#include <array>
#include <algorithm> // for_each()

// The for_each function handler must have only 1 argument which is the current element in the current iteration
void display(int a){
	std::cout << "for_each()\n";
}
void display_arg(int a){
	std::cout << a << "\n";
}
int main ()
{
	int arr[] = {1, 2, 3};
	std::array<int, 4> int_arr = {1, 2, 3, 4};

	std::for_each(arr, arr + 3, display_arg);
	std::for_each(int_arr.begin(), int_arr.end(), display);
	std::for_each(int_arr.begin(), int_arr.end(), display_arg);

	return 0;
}
```
# [Function overloading](Function%20overloading.md)
* [Overview]()
* [Different between overload and override/overloading and overriding](Function%20overloading.md#different-between-overload-and-overrideoverloading-and-overriding)
* [Name mangling](Function%20overloading.md#name-mangling)
# Default arguments

```cpp
void intNumber(int a = 1, int b = 2, int c = 3, int d = 4);

int main(){
    //set a; keep a, b, c default
    intNumber(12);// 12 2 3 4

    // set b, keep a, c, d default
    intNumber(1, 12);// 1 12 3 4

    // set c, keep a, b, d default
    intNumber(1, 2, 34);// 1 2 34 4

    // set d, keep a, b, c default
    intNumber(1, 2, 3, 56);// 1 2 3 56
}

void intNumber(int a, int b, int c, int d){
    cout << a << " " << b << " " << c << " " << d << endl;
}
```
**Note**: When you pass a value for a particular parameter that has a default argument, you have to pass values for all the default parameters before it. Otherwise, the value you have passed will be taken as the value for the first default parameter.

If define:

```cpp
void intNumber(int a, int b = 12);

int main(){
	//operations go here
}

void intNumber(int a, int b=12){
	//operations go here
}
```

There will be error:

```
test.cpp:12:31: error: default argument given for parameter 2 of ‘void intNumber(int, int)’ [-fpermissive]
 void intNumber(int a, int b=12){
```
# Template
Template for functions:
* [Generics or Generics programming](Template.md#generics)
* [Using template for data type](Template.md#using-template-for-data-type)
* [Template for unique pointer as function argument]()
* [Using template is the only solution to allow passing array as function parameter without using its size]()
* [Multiple template used for functions](Template.md#multiple-template-used-for-functions)
* [Using template typename along with other type](Template.md#using-template-typename-along-with-other-type)
* [Template parameter pack]()
Template for class method:
* [Template with class as type](Template%20with%20class.md#template-with-class-as-type)
* [Template as class method]()
* [Define template method of class in separated source files]()
