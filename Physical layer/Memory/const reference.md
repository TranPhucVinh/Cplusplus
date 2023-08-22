**const reference** is the reference (lvalue, rvalue) which doesn't allow changing its value.

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
