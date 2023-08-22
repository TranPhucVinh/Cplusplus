**const reference** is the reference (lvalue, rvalue) which doesn't allow changing its value.
# const reference for lvalue
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
# const reference for rvalue
```c
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
