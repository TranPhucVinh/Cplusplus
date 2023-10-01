**const reference** is the reference (lvalue, rvalue) which doesn't allow changing its value.
```cpp
// THIS EXAMPLE IS WRONG AND GIVES COMPILATION ERROR
int a = 123;
const int &b = a;
cout << b << endl;// 123
b = 456;//Compilation error: assignment of read-only reference ‘b’   
```
# const reference value can be changed when assigned it to a variable
```cpp
int a = 123;
const int &b = a;
cout << b << endl;// 123
a = 456;
cout << b << endl;// 456
```
# const reference for lvalue as function argument doesn't allow changing
```cpp
// THIS EXAMPLE IS WRONG AND GIVES COMPILATION ERROR
int number = 8;

void add_value(const int& a){
    // This is wrong as trying to change the const reference as lvalue
  	a += 1;
    return;
}

int main(){
    printf("number: %d\n", number);//8
    add_value(number);//Wrong and gives compilation error
    printf("number: %d\n", number);//Wrong; program won't reach here
}
```
# const reference for rvalue as function argument doesn't allow changing
```cpp
// THIS EXAMPLE IS WRONG AND GIVES COMPILATION ERROR
void add_value(const int&& a)
{
	a += 1;// This is wrong as trying to change the const reference as rvalue
    return;
}

int main(){
    printf("number: %d\n", number);//8
    add_value(std::move(number));
    printf("number: %d\n", number);//9
}
```
# When to use const reference
const reference is useful when we want to pass the reference to the function for read-only purpose. An example for this is the [copy constructor in deep copy](https://github.com/TranPhucVinh/Cplusplus/blob/master/Object-oriented%20programming/Constructor%20and%20destructor/Shallow%20copy,%20deep%20copy%20and%20copy%20constructor.md#deep-copy):
```cpp
classTest(const classTest &obj){
    ptr = new int(0);
    *ptr = *obj.ptr;
    return;
}
```
