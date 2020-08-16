### Function defined in Header files

``header.h``

```cpp
#include <iostream>
using namespace std; // this line is optional

void displayString();
```

``header.cpp``

```cpp
#include <iostream>
#include "header.h"
using namespace std; // this line is optional

void displayString(){
	cout << "Hello, World!" << endl;
}
```

``main.cpp``

```cpp
#include <iostream>
#include "header.h" //"header.h", not <header.h>

using namespace std;

int main(){
	displayString(); //Hello, World!
}
```