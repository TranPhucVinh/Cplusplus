### Write data to file

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream fileStream("text.txt"); //Can also be: fstream fileStream("text.txt", ios::in | ios::out);
    fileStream << "Hello, World !";
    fileStream.close();
    return 0;
}
```

### Read data from file

``text.txt``
```
Hello, World !
```

```cpp
string readString;

fstream fileStream("text.txt");
fileStream >> readString;
cout << readString;
fileStream.close();
```
**Output**: ``Hello,``

### Input and output operation at the same time

With ``fstream``, you can perform two operations ``input`` and ``output`` at the same time.