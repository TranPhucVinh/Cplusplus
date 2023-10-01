# Generics

Generics is the idea to allow type (integer, string,... and user-defined types) to be a parameter to methods, classes and interfaces. Generic programming enables the programmer to write a general algorithm which will work with all data types and eliminates the need to create different algorithms if the data type is an integer, string or a character. Beside that, generic programming will also avoid [function overloading](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/Function%20and%20variables/Function.md#function-overloading).

Generics can be implemented in C++ using **template**.

``template`` is used to pass data type as a parameter so that we don’t need to write the same code for different data types. ``template`` are expanded at compiler time. This is like macros. The difference is, the compiler does type checking before ``template`` expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of same function/class. 

# Using template for data type

```cpp
#include <iostream>
#include <typeinfo>

template <typename dummy_type>
dummy_type add_function(dummy_type a, dummy_type b){
    std::cout << "dummy_type is " << typeid(dummy_type).name() << std::endl;
    return a + b;
}

int main () {
    printf("%d\n", add_function<int>(1, 2));//3
    printf("%.2f\n", add_function<float>(1.2, 3.4));//4.6
}
```
**Result**
```
dummy_type is i
3
dummy_type is f
4.60
```

``template`` can be defined in the same line of the function:

```c
template <typename dummy_type> dummy_type add_function(dummy_type a, dummy_type b){}
```

## Note

Function definition must be followed right after ``template <typename>``. If not like this case, there will be error:

```c
template <typename dummy_type>
void dummy_func();
dummy_type add_function(dummy_type a, dummy_type b){
}
```
    
**Error**

```
main.cpp:6:1: error: 'dummy_type' does not name a type
 dummy_type add_function(dummy_type a, dummy_type b){
```

## Multiple template used for functions

Based on the [note](#note), multiple template used for functions must be like this:

```cpp
#include <iostream>
#include <typeinfo>

template <typename dummy_type> dummy_type add_function(dummy_type a, dummy_type b){
    return a + b;
}

template <typename dummy_type> dummy_type display_value(dummy_type a){
    std::cout << "a: " << a << std::endl;
}

int main () {
    printf("%d\n", add_function<int>(1, 2));//3
    printf("%.2f\n", add_function<float>(1.2, 3.4));//4.6
    display_value<int>(1);//a: 1
    display_value<std::string>("Hello, World !");//a: Hello, World !
}
```

# Using template typename along with other type

```cpp
#include <iostream>
#include <typeinfo>

template <typename dummy_type> void add_function(dummy_type a, int b){
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
}

int main () {
    add_function<int>(1, 2);
    add_function<float>(1.2, 3);
    add_function<std::string>("Hello, World !", 4);
}
```

```
a: 1
b: 2
a: 1.2
b: 3
a: Hello, World !
b: 4
```

# Template with class as type

```cpp
#include <iostream>
#include <typeinfo>

using namespace std;
template <typename class_type>
void call_object_method(class_type object){
    object.display_string();
    object.display_number();
}

class classTest{
	public:
		void display_string(){
			cout << "Hello World \n";
		}
        void display_number(){
			cout << 123;
		}
};

int main(){
	classTest object;
    call_object_method<classTest>(object);
}
```
# Template as class method
```cpp
class classTest{
	public:
        template <typename dummy_type>
        dummy_type add_function(dummy_type a, dummy_type b);
};

int main(){
	classTest object;
    printf("%d\n", object.add_function<int>(1, 2));//3
    printf("%.2f\n", object.add_function<float>(1.2, 3.4));//4.6

}

template <typename dummy_type>
dummy_type classTest::add_function(dummy_type a, dummy_type b){
    std::cout << "dummy_type is " << typeid(dummy_type).name() << std::endl;
    return a + b;
}
```
# Template parameter pack

Template parameter pack is a template features for template [variable length argument/variadic function](https://github.com/TranPhucVinh/C/blob/master/Introduction/Function/Variadic%20function.md)

```cpp
#include <iostream>

template <typename...dummy_type>
void parameter_packs_size(dummy_type... dt){
	printf("Size of parameter packs: %ld\n", (sizeof...(dummy_type)));
}

int main(){
	parameter_packs_size();// 0
	parameter_packs_size(1, 2);// 2
	parameter_packs_size(1, 2, 3);// 3
}
```
G++ 5.0 doesn't support template parameter pack properly while G++ 9.0 (test environment: WSL Ubuntu 20.04) supports it properly with C++17

The following implementation are in G++ 9.0, on WSL Ubuntu 20.04, C++17:

## Sum all members of template parameter packs

```cpp
#include <iostream>

template <typename ...dummy_type>
auto parameter_packs(dummy_type... dt) {
	return (dt + ...);
}

int main() {
	printf("%d\n", parameter_packs(1, 2));
	printf("%lf\n", parameter_packs(1.2, 3.4, 5.6));
}
```

## Sum all class object member of template parameter packs

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int int_number;
		float float_number;
};

template <typename ...classTest>
auto parameter_packs(classTest... ct) {
	return (ct + ...);
}

int main(){
	classTest obj1, obj2;
	obj1.int_number = 1;
	obj1.float_number = 1.2;
	obj2.int_number = 2;
	obj2.float_number = 3.4;
	printf("%d\n", parameter_packs(obj1.int_number, obj2.int_number));
	printf("%lf\n", parameter_packs(obj1.float_number, obj2.float_number));
}
```
