### tellg()

``fstream::tellg()`` tells the positon of the current cursor in ``get``

``file.txt``

```
12123123 werwtwergfd
```

``main.c``

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