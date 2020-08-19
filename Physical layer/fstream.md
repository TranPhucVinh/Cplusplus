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
	ofstream myFile;
	myFile.open("text.txt");

	myFile << "Hello, World"; //Write data to file
	myFile.close();
}
```

Or: ``ofstream myFile("text.txt");``

### Check file open status

Check status: ``is_open()``

```cpp
#include <iostream>
#include <fstream>

using namespace std;

main() {
	ofstream myFile("text.txt");
	myFile << "Hello, World";
	if (myFile.is_open()) cout << "The file is open" << endl;
	else cout <<"File is close !! \n";
	myFile.close();

	//After closing, check open status again
	if (myFile.is_open()) cout << "The file is open" << endl;
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
	ofstream myFile("file.txt");
	cout << "Enter ID, Name, Salary \n";
	cin >> id >> name >> money;
	myFile << id << " " << name << " " << money << endl;
	myFile.close();
}
```

### Read data from a file

**Read all data from a file with getline()**

```cpp
string data;
ifstream myFile("file.txt");
getline(myFile, data);
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
	ifstream myFile("file.txt");

	myFile >> word1 >> word2 >> word3;
	cout << word1 << " " <<  word2 << " " << word3;
	myFile.close();
}
```

**Read seperated data from a file with multiple lines**

``file.txt``

```
124 ertyewew 5666
1243 errtyewew 56666
12 edrtyewew 5666
```

```cpp
#include <iostream>
#include <fstream>

using namespace std;

main() {
	ifstream myFile("file.txt");
	int word1;
	string word2;
	int word3;
	while (myFile >> word1 >> word2 >> word3)
	{
		cout << word1 << " " <<  word2 << " " << word3 << endl;
	}
	myFile.close();
}
```

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