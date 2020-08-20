Library ``fstream``

* ``ofstream``: output file streams
* ``ifstream``: input file streams

### Create new file

Create and write data to a file

```cpp
#include <iostream>
#include <fstream>

using namespace std;

main() {
	ofstream fileStreamOut;
	fileStreamOut.open("text.txt");

	fileStreamOut << "Hello, World !"; //Write data to file
	fileStreamOut.close();
}
```

Or: ``ofstream fileStreamOut("text.txt");``

### Check file open status

Check status: ``is_open()``

```cpp
#include <iostream>
#include <fstream>

using namespace std;

main() {
	ofstream fileStreamOut("text.txt");
	fileStreamOut << "Hello, World";
	if (fileStreamOut.is_open()) cout << "The file is open" << endl;
	else cout <<"File is close !! \n";
	fileStreamOut.close();

	//After closing, check open status again
	if (fileStreamOut.is_open()) cout << "The file is open" << endl;
	else cout <<"File is close !! \n";
}
```

**Result**

```
The file is open
File is close !! 
```

### Write data to file

```cpp
#include <iostream>
#include <fstream>

using namespace std;

int id;
string name;
double money;

main() {
	ofstream fileStreamOut("file.txt");
	cout << "Enter ID, Name, Salary \n";
	cin >> id >> name >> money;
	fileStreamOut << id << " " << name << " " << money << endl;
	fileStreamOut.close();
}
```

### Read data from a file

**Read all data from a file with getline()**

```cpp
string data;
ifstream fileStreamIn("file.txt");
getline(fileStreamIn, data);
cout << data;
```

**Read seperated data from a file**

``file.txt``

```
string_1 string_2 string_3
```

As file ``file.txt`` has 3 word, we create 3 variable ``word1``, ``word2``, ``word3`` correspondingly to these 3 words.

```cpp
#include <iostream>
#include <fstream>

using namespace std;

string word1, word2, word3;

main() {
	ifstream fileStreamIn("file.txt");

	fileStreamIn >> word1 >> word2 >> word3;
	cout << word1 << " " <<  word2 << " " << word3;
	fileStreamIn.close();
}
```

**Read seperated data from a file with multiple lines**

``file.txt``

```
1 user_1 10
2 user_2 20
3 user_3 30
```

```cpp
#include <iostream>
#include <fstream>

using namespace std;

main() {
	ifstream fileStreamIn("file.txt");
	int word1;
	string word2;
	int word3;
	while (fileStreamIn >> word1 >> word2 >> word3)
	{
		cout << word1 << " " <<  word2 << " " << word3 << endl;
	}
	fileStreamIn.close();
}
```

### Unable to handle in/out at the same time

You can't open input and output file stream at the same time, this will not give compilation error but result in failure when run

```c
//Wrong
ifstream fileStreamIn("text.txt");
ofstream fileStreamOut("text.txt");
```

So it means that you can't edit the content of a single line belong to an opening a file to read.

### Cursor in fstream

``fstream::tellg()`` tells the positon of the current cursor in ``get``

e.g

we have a file name ``file.txt``

```
12123123 werwtwergfd
```

**main.c**

```c
ifstream myFile("file.txt");
cout << myFile.tellg() << endl; //Result: 0
```

``0`` as at the beginning of the file

``fstream::seekg(2)``: start the cursor from character 3

```cpp
string data;
ifstream myFile("file.txt");
myFile.seekg(2);
getline(myFile, data);
cout << data;
```

**Result**: The content of ``file.txt``

``fstream::seekg(2)`` only reading in one line.

### Searching information

file.txt

```
121
1231 345425444
12 1
```

We want searching in line 2 and line 3

```cpp
string data;
int findID, id, id0;
ifstream myFile("file.txt");
myFile.seekg(3);
cout << "Enter employee's ID: ";
cin >> findID;
while(myFile >> id >> id0){
	if (findID == id){
		cout << "Name" << ' ' << "Age"  << endl;
		cout << id << " " <<  id0 << endl;
	}
}
```

**Result**

```
Enter employee's ID: 12
Name Age
12 1
```

**One more example**

file.txt

```
ID abs
1   2
2   2
```

```c
string data;
	int findID, id, id0;
	ifstream myFile("file.txt");
	myFile.seekg(7);
	cout << "Enter employee's ID: ";
	cin >> findID;
	while(myFile >> id >> id0)
	{
	if (findID == id){
	cout << id  << " "<< id0 << endl;
```

**Result**

```
Enter employee's ID: 1
1 2
```

if ``myFilfe.seekg(6)`` then 

```
Enter employee's ID: 1
1 2
```

if ``myFilfe.seekg(8)`` then

``Enter employee's ID: 1`` will return nothing as the cursor is in the wrong postion to read.

``myFile.seekg(5)`` then

``Enter employee's ID: 1`` will return nothing as the cursor is in the wrong postion to read.