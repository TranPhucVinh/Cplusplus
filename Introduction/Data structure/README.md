# String

String document will include

* [Char array for string](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#char-array-for-string)
* [Char pointer for string](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#char-array-for-string)
* [std::string](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#stdstring)
* [stringstream](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#stringstream)

# JSON

Implement [JSON](JSON) with [nlohmann/json](https://github.com/nlohmann/json) library.

# [Vector](Vector)

# struct

``struct`` in CPP support variables, functions, constructor and destructor functions

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

# Queue

Create a queue to store all int variable then read all those value.

```cpp
#include <iostream>
#include <queue>
  
using namespace std;

void readAllObjectFromQueue(queue<int> queueObjectParam){
    while (!queueObjectParam.empty()) {
        cout << '\t' << queueObjectParam.front();
        queueObjectParam.pop();
    }
    cout << '\n';
}

int main()
{
    queue<int> queueIntObject;//Declare a queue that accepts int value
    queueIntObject.push(1);
    queueIntObject.push(2);
    queueIntObject.push(3);

    readAllObjectFromQueue(queueIntObject);
    return 0;
}
```
# enum

Since C++11, ``enum`` allows accessing its member with ``::``:

```c
enum enum_object {value0 = 10, value1, value2, value3, value4 = 10, value5 = 16, value6};
printf("%d\n", enum_object::value0);
```
