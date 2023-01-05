``template`` is used to pass data type as a parameter so that we don’t need to write the same code for different data types. ``template`` are expanded at compiler time. This is like macros. The difference is, the compiler does type checking before ``template`` expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of same function/class. 

**Example**: Using ``template`` for data type

```c
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
