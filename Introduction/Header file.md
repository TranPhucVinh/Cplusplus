## Header file with class

``header.h``

```cpp
#include <iostream>
#ifndef header_h
#define header_h

using namespace std;

class Header
{
	public:
		void display();
		void displayNumber(int number);
		void displayRespective(int lastNumber);
	private:
		int _number;
		int _lastNumber;
};
#endif

void helloworld();
```

**Notice**

```
#ifndef header_h
#define header_h
```
Without this line, there will be error when calling class Header in header.cpp

``header.cpp``

```cpp
#include <iostream>
#include "header.h"
using namespace std;

void Header::display(){
	cout << "Hello, World!" << endl;
}

void Header::displayNumber(int number){
	_number = number;
	cout << "This number is " << _number << endl;
}

void Header::displayRespective(int lastNumber){
	_lastNumber = lastNumber;
	int i;
	for (i = 0; i < _lastNumber; i++){
		cout << i << endl;
	}
}

void helloworld(){
	cout << "Hello, World!" << endl;
}
```

``test.cpp``

```cpp
#include <iostream>
#include "header.h" //"header.h", not <header.h>

using namespace std;

int main(){
	Header header;
	header.display();
	header.displayNumber(6);
	header.displayRespective(6);
	helloworld();
}
```
**Result**
```
Hello, World!
This number is 6
0
1
2
3
4
5
Hello, World!
```

## Define value in header file, without class

**header.h**
```cpp
#include <iostream>
#ifndef header_h
#define header_h
#define integerValue 190

using namespace std;

class Header
{
	public:
		void hello();
	private:
		int _number;
};
#endif

void helloworld();
int value = 18;
```
**main.cpp**
```cpp
#include <iostream>
#include "header.h"

using namespace std;

int main() {
    cout << value << endl; //18
    cout << integerValue << endl; //190
    return 0;
}
```