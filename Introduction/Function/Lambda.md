Lambda, full name Lambda expression, is a way of defining an anonymous function object (a closure) right at the location where it's invoked or passed as an argument to a function

Lamba is supported since C++11.

Use lamba to define a function when it is invoked:
```cpp
#include <iostream>

using namespace std;

void display_string(void str()){
	str();
}

int main()
{
	display_string([](){
		printf("Hello, World !");
	});// Hello, World !
    return 0;
}
```

Define function by Lambda:

```cpp
int main()
{
	// As this is anonymous function so use auto
	auto return_int = [](int a){
		return a;
	};
	std::cout << return_int(123) << std::endl;
    return 0;
}
```