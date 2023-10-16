
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
# Define template method of class in separated source files

Defining template method of class in seperated source files like this cause compilation error:

``header.h``
```cpp
#include <iostream>
#ifndef header_h
#define header_h

class classTest{
	public:
        template <typename dummy_type>
        dummy_type add_function(dummy_type a, dummy_type b);
};

#endif
```

``header.cpp``
```cpp
#include "header.h"

template <typename dummy_type>
dummy_type classTest::add_function(dummy_type a, dummy_type b){
    std::cout << "dummy_type is " << typeid(dummy_type).name() << std::endl;
    return a + b;
}
```
``main.cpp``
```cpp
#include <iostream>
#include "header.h"

int main(){
	classTest object;
    printf("%d\n", object.add_function<int>(1, 2));//3
    printf("%.2f\n", object.add_function<float>(1.2, 3.4));//4.6
}
```
This will cause compilation error:
```
main.cpp:(.text+0x2d): undefined reference to `int classTest::add_function<int>(int, int)'
main.cpp:(.text+0x5c): undefined reference to `float classTest::add_function<float>(float, float)'
```
That happens as template, like macros, are expanded at compiler time. The difference is, the compiler does type checking before template expansion.

There are only 2 ways to avoid that

## 1st solution: Put template .cpp source file inside main.cpp
```cpp
#include <iostream>
#include "header.h"
#include "header.cpp"
// Other parts of main.cpp kept unchanged
```
## 2nd solution: Put the template method definition inside .h file

``header.h``
```cpp
#include <iostream>
#ifndef header_h
#define header_h

class classTest{
	public:
        template <typename dummy_type>
        dummy_type add_function(dummy_type a, dummy_type b);
};

template <typename dummy_type>
dummy_type classTest::add_function(dummy_type a, dummy_type b){
    std::cout << "dummy_type is " << typeid(dummy_type).name() << std::endl;
    return a + b;
}

#endif
```
Then we don't need any ``header.cpp`` in this case. ``main.cpp`` are kept unchanged as the original.
