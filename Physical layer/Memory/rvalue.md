rvalue reference is unofficially called as double address operator. rvalue reference can be defined with ``int &&`` and ``int &&a``.

``&&`` is new in C++11. ``int&& a`` means "a" is an r-value reference.

Compile: ``g++ main.c -std=c++11``

# Define rvalue

```c
#include <stdio.h>

int main()
{
    int&& a = 1;//Define with int&&   
    int &&b = 2;//Define with int &&
    printf("a: %d, &a: %d\n", a, &a);//a: 1, &a: 6487560
    printf("b: %d, &b: %d\n", b, &b);//b: 2, &b: 6487564
}
```

Calling ``&&a`` will result in error:

```cpp
printf("&&a: %d", &&a);//This will result in error
printf("&&b: %d", &&b);//This will result in error
```
**Error**

```
main.c:13:25: error: label 'a' used but not defined
main.c:14:25: error: label 'b' used but not defined
```

# rvalue as class object

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int publicNumber = 10;
		void hello(){
			cout << "Hello, World !\n";
		}
};

int main(){
    classTest &&rval_object = classTest();
    rval_object.hello();//Hello, World !
    cout << rval_object.publicNumber << endl; //10
}
```
	
# rvalue as function argument

For rvalue as function argument, the value passing to it must be rvalue

```c
#include <stdio.h>

int func(int&& a)
{
    return a+1;
}

int main()
{   
    int a = 4;
    printf("%d\n", func(3));//4
    printf("%d\n", func(a-0));//5
    printf("%d\n", func(a+1));//6
}
```
Use ``std::move()`` to be more efficient, instead of using ``func(a-0)``:

```cpp
printf("%d\n", func(std::move(a)));
```

# rvalue as pass reference

rvalue as pass reference to change value of a variable

```c
void func(int&& a)
{
    a += 1;
    return;
}

int main()
{   
    int a = 4;
    printf("%d\n", a);//4
    func(std::move(a));
    printf("%d\n", a);//5
}
```
