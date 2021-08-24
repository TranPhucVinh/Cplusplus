### stdio.h

Stream out with ``printf()``

```cpp
#include <iostream>
#include <stdio.h> //For printf

using namespace std;

main(){
	cout << "Hello, World!" << endl;
    printf("Hello, World!\n");
}
```

Get the entered string with ``fgets()``

```c
#include <iostream>
#include <stdio.h>

using namespace std;

char displayString[100];

int main(){
	cout << "Enter string: ";
	fgets(displayString, 20, stdin);
	cout << displayString;
}
```

### cstdio

All functions of ``stdio.h`` existed in ``cstdio``.

```c
#include <iostream>
#include <cstdio> //For printf

using namespace std;

main(){
	cout << "Hello, World!" << endl;
    printf("Hello, World!\n");
}
```