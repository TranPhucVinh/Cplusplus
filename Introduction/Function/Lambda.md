**Lambda**, full name Lambda expression, is a way of **defining an anonymous function object (a closure) right at the location where it's invoked** or passed as an argument to a function.

Lambda allows inline functions to be used for short snippets of code that are not going to be reused and therefore do not require a name.
 
Lambda is supported since C++11.

Use lambda to define a function when it is invoked:
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

Define function by Lambda, **auto** must be used:

```cpp
int main() {
	// As this is anonymous function, auto must be used
	auto return_int = [](int a){
		return a;
	};
	std::cout << return_int(123) << std::endl;
    return 0;
}
```
Lambda function in [for_each()](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Function#for_each):
```cpp
vector<int> vect = {1, 2, 3, 4};

std::for_each(vect.begin(), vect.end(), [](int a){ // Lambda function to print out all members of the vector
	std::cout << a << " ";
});
```
