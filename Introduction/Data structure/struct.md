# Fundamental concepts

CPP struct support variables, functions, constructor and destructor functions

```cpp
#include <iostream>
#include <string.h>

using namespace std;

struct struct_data {
	int id;
	char displayed_string[30];
	void no_param_func(){
		cout << "Hello, World !" << endl;
	}

	void params_func(int a, int b){
		cout << a+b << endl;
	}

	struct_data() {
		cout << "Constructor function is called" << endl;
	}

	~struct_data() {
		cout << "Destructor function is called" << endl;
	}
};

int main() {
	struct_data object;

	object.id = 1;
	cout << object.id << endl;
	strcpy(object.displayed_string, "Displayed string");
	object.no_param_func();
	object.params_func(1, 3);
} 
```

**Result**: 

```
Constructor function is called
1
Hello, World !
4
Destructor function is called
```
