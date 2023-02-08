# Function overloading

```cpp
#include <iostream>

using namespace std;

void addNumbers(int a, int b){
    cout << a+b << endl;
}

void addNumbers(float a, float b){
    cout << a+b << endl;
}

void addNumbers(int a, int b, int c){
	cout << a+b+c << endl;
}

void addNumbers(void){
	cout << 3 << endl;
}

int main () {
    addNumbers(3, 4); //7
    addNumbers(3.0f, 4.0f); //7
	addNumbers(3, 4, 5); //12
	addNumbers(); //3
}
```

**Notice**  ``addTwoNumbers(3.0f, 4.0f)`` for float number, without ``f`` there will be error ``call of overloaded ‘addTwoNumbers(double, double)’ is ambiguous``, as ``addTwoNumbers(3.1, 4.1)`` is interpreted as double number.

# Default arguments

```c
void intNumber(int a, int b = 12);

int main(){
    intNumber(150, 13);
    intNumber(15);
}

void intNumber(int a, int b){
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}
```

If define:

```c
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
