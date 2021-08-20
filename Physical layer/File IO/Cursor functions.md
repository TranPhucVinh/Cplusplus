### tellg()

``tellg()`` tells the positon of the current cursor

``file.txt``

```
123 Hello, World !
```

``main.c``

```c
ifstream fileStreamIn("text.txt");
cout << fileStreamIn.tellg() << endl; //0
```

``0`` as at the beginning of the file

### seekg()

``fstream::seekg(n)``: start the cursor from character ``n+1`` of the current reading line

```cpp
string data;
ifstream fileStreamIn("text.txt");
fileStreamIn.seekg(2);
getline(fileStreamIn, data);
cout << data; //3 Hello, World !
```

``fstream::seekg(2)`` only reading in one line.

### Searching information with seekg()

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