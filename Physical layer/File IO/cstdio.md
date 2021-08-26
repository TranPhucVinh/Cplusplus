``cstdio`` is corresponded to ``stdio.h``. All functions of ``stdio.h`` existed in ``cstdio``.

**Example 1**: Using ``printf()``

```c
#include <iostream>
#include <cstdio> //For printf

using namespace std;

main(){
	cout << "Hello, World!" << endl;
    printf("Hello, World!\n");
}
```

**Example 2**: Get the entered string with ``fgets()``

```c
#include <iostream>
#include <cstdio>

using namespace std;

char displayString[100];

int main(){
	cout << "Enter string: ";
	fgets(displayString, 20, stdin);
	cout << displayString;
}
```