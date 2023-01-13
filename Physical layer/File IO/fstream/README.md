# API

* ``fstream`` for two operations ``input`` and ``output`` at the same time.
* ``ifstream`` for input operation, used for **reading**
* ``ofstream`` for output operation, used for **creating** and **writing**

You can't open input and output file stream (with ``ifstream`` and ``ofstream``) at the same time, this will not give compilation error but result in failure when run

```c
//Wrong, must not do it
ifstream fileStreamIn("text.txt");
ofstream fileStreamOut("text.txt");
```

So it means that you can't edit the content of a single line belong to an opening a file to read.

### is_open()

``is_open()`` will check file opened status:

```cpp
#include <iostream>
#include <fstream>

using namespace std;

main() {
	ofstream fileStreamOut("text.txt");
	fileStreamOut << "Hello, World !";
	if (fileStreamOut.is_open()) cout << "The file is open" << endl;
	else cout << "File is close \n";
	fileStreamOut.close();

	//After closing, check open status again
	if (fileStreamOut.is_open()) cout << "The file is open" << endl;
	else cout << "File is close \n";
}
```

**Result**

```
The file is open
File is close !! 
```
