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

However, this can just read only one line of data in a file. To read all lines of data in the file:

```cpp
string data;
ifstream fileStreamIn("text.txt");

while (!fileStreamIn.eof()){
	getline(fileStreamIn, data);
	cout << data << endl;
}
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

### Unable to handle in/out at the same time with ``ifstream`` and ``ofstream``

You can't open input and output file stream at the same time, this will not give compilation error but result in failure when run

```c
//Wrong
ifstream fileStreamIn("text.txt");
ofstream fileStreamOut("text.txt");
```

So it means that you can't edit the content of a single line belong to an opening a file to read.