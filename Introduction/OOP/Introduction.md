### Introduction

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int publicNumber = 10;
		void hello(){
			cout << "Hello World \n";
		}
	private:
		int privateNumer = 20; //Unable to read that value outside
};

main(){
	classTest object;
	object.hello(); //Hello World
	cout << object.publicNumber << endl; //10
}
```

You are unable to read private properties outside the class:

```cpp
private:
    int privateNumer = 20; //Unable to read 
```

So this will give error: ``cout << object.privateNumber << endl;``

### Types of variables in class

* Instance variables
* Static variables

**Instance variables**

* Instance variables are created ``when an object of the class is created`` and ``destroyed when the object is destroyed``.
* Instance variables can be accessed ``only by creating objects``.

**Static variables**

* Static variables can be defined with: ``className::staticVariable = value``

Example:

``header.h``

```cpp
#include <iostream>
#ifndef header_h
#define header_h

using namespace std;

class Header
{
  public:
    static int a;
};
#endif

int Header::a = 100;
```

``main.cpp``

```cpp
#include "header.h"

int main(){
    Header header;
    cout << Header::a << endl;//100
    cout << header.a << endl; //100
    Header::a++;
    cout << Header::a << endl;//101
    header.a++;
    cout << Header::a << endl;//102

    Header header2;
    cout << Header::a << endl;//102
    cout << header2.a << endl;//102
}
```

You can't initiliaze non-const static member

```cpp
class Header
{
  public:
    static int a = 12;
};
```

This will give error: ``ISO C++ forbids in-class initialization of non-const static member``

Static variable can be defined normally in another source file:

``header.cpp`` (``header.h`` and ``main.cpp`` are kept the same)

```cpp
#include <iostream>
#include "header.h"
using namespace std;

int Header::a = 10;
```