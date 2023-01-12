## Create new file

Open a file (created if not existed) and write data to that file

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

## Write data to file

Write with ``fstream()``

```cpp
#include <iostream>
#include <fstream>
using namespace std;

#define FILE_NAME   "text.txt"
int main()
{
	fstream fileStream(FILE_NAME);
    if (fileStream.fail()) {//Use .fail() to check if FILE_NAME existed
        cout << "File " << FILE_NAME << " not existed\n";
        return 0;
    }
    fileStream << "Hello, World !";
    fileStream.close();
    return 0;
}
```

``fileStream.fail()`` return ``1`` if file not existed and ``0`` if file existed.

Or: 

```c
fstream fileStream("text.txt", ios::in | ios::out);
```

Write with ``ofstream()``

```c
#include <iostream>
#include <fstream>

using namespace std;

int number = 10;
string displayedString = "Hello, World !";

main() {
	ofstream fileStreamOut("file.txt");
	fileStreamOut << number << " " << displayedString << endl;
	fileStreamOut.close();
}
```

## Read data from file

``text.txt``
```
1 user_1 10
2 user_2 20
3 user_3 30
```

Using ``fstream()``

```cpp
string readString;

fstream fileStream("text.txt");
fileStream >> readString;
cout << readString;
fileStream.close();
```
**Output**: ``1``

The same issue happens with ``ifstream()``. That’s because the >> operator reads a string only until it encounters a white space character (such as a space or line break). 

An inefficient way to solve the problem:

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


**Problem solved**

```cpp
string data;
ifstream fileStreamIn("README.md");

while (!fileStreamIn.eof()){
	getline(fileStreamIn, data);
	cout << data << endl;
}
```
