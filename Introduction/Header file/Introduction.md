### In CPP

``header.h``

```cpp
#include <iostream>
using namespace std; // this line is optional

void helloworld();
```

``header.cpp``

```cpp
#include <iostream>
#include "header.h"
using namespace std; // this line is optional

void helloworld(){
	cout << "Hello, World!" << endl;
}
```

``main.cpp``

```cpp
#include <iostream>
#include "header.h" //"header.h", not <header.h>

using namespace std;

int main(){
	helloworld(); //Hello, World!
}
```