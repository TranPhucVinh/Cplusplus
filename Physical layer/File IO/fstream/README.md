# File operations

* **fstream** for two operations **input** and **output** at the same time.
* **ifstream** for input operation, used for **reading**
* **ofstream** for output operation, used for **creating** and **writing**

You can't open input and output file stream (with **ifstream** and **ofstream**) at the same time, this will not give compilation error but result in failure when run

```c
//THIS IS WRONG, MUST NOT DO IT. YOU CAN'T OPEN INPUT AND OUTPUT FILESTREAM AT THE SAME TIME
ifstream fileStreamIn("text.txt");
ofstream fileStreamOut("text.txt");
```

So it means that you can't edit the content of a single line belong to an opening a file to read.

File operations with ``fstream`` includes:
* [Create new file](File%20operations.md#create-new-file)
* [Read data from file](File%20operations.md#read-data-from-file): [Issue with <<](File%20operations.md#-caused-reading-separated-by-spaces), [Read the whole file](File%20operations.md#read-the-whole-file): Read into char array on stack memory, read into a buffer on heap memory initialized with unique pointer 
* [Write data to file](File%20operations.md#write-data-to-file)

# API

## is_open()

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
## tellg()

``tellg()`` tells the position of the current cursor

``main.c``

```c
ifstream fileStreamIn("text.txt");
cout << fileStreamIn.tellg() << endl; //0
```

``0`` as at the beginning of the file
## seekg()

``fstream::seekg(n)``: start the cursor from character ``n+1`` of the current reading line

```cpp
string data;
ifstream fileStreamIn("text.txt");
fileStreamIn.seekg(2);
getline(fileStreamIn, data);
cout << data; //3 Hello, World !
```

``fstream::seekg(2)`` only reading in one line.

**Searching information with seekg()**

``text.txt``

```
123 Hello1, World !
456 Hello2, World !
126 Hello3, World !
```

```cpp
ifstream fileStreamIn("text.txt");
fileStreamIn.seekg(2);

while (!fileStreamIn.eof())
{
	string data;	
	getline(fileStreamIn, data);
	cout << data << endl;
}
```
**Output**

```
3 Hello1, World !
456 Hello2, World !
126 Hello3, World !
```

If the cursor is set wrong in ``seekg()``, it will return nothing when searching.
