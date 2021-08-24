### Stream out

```cpp
#include <iostream>

using namespace std;

main(){
	cout << "Hello, World!" << endl;
}
```

``\n`` and ``endl`` is the same. ``endl: endline``

Or define:

```cpp
#include <iostream>

main(){
	std::cout << "Hello, World!" << std::endl;
}
```

Stream out with ``printf()``

```cpp
#include <iostream>
#include <stdio.h> //For printf

using namespace std;

main(){
	cout << "Hello, World!" << endl;
    printf("Hello, World!\n");
}
```

### Get entered int value from Stream in

Get entered int value from ``Stream in`` with ``cin`` then print out:

```cpp
#include <iostream>

using namespace std;

int main(){
	int number;
	cout << "Enter an int number: ";
	cin >> number;
	cout << "You have entered: " << number << endl;
}
```

**Input**: ``11`` **Output**: ``11``

**Input**: ``11abc`` **Output**: ``11``

**Input**: ``Hello, World !`` **Output**: ``0``

Get multiple data from ``cin`` then print out:

```cpp
#include <iostream>

using namespace std;

int main(){
	int number1, number2, number3;
	cout << "Enter three int numbers: \n";
	cin >> number1 >> number2 >> number3;
	cout << "You have entered: " << number1 << " " << number2 << " " << number3 << endl;
}
```

### Get an entered string from Stream in

Get an entered string with ``cin``

```cpp
#include <iostream>

using namespace std;

string sentence;

int main(){
	cout << "Enter string: ";
	cin >> sentence;
	cout << "The entered string is: " << sentence;
}
```

**Input**: ``Hello, World !`` **Output**: ``Hello,``

### Get the whole entered string (include space)

With ``fgets()``

```c
#include <iostream>

using namespace std;

char displayString[100];

int main(){
	cout << "Enter string: ";
	fgets(displayString, 20, stdin);
	cout << displayString;
}
```

With ``getline()``: Get line from ``stream`` into ``string``

```c
istream& getline (istream& is, string& str, char delim);
istream& getline (istream& is, string& str);
```

```cpp
#include <iostream>

using namespace std;

main(){
	string sentence;
	cout << "what is your sentence ? \n";
	getline(cin, sentence);
	cout << "The whole sentence is: " << sentence;
}
```

For other examples with ``getline()``, check: ``Example.md``.

With ``cin.getline()``: ``getline(char_type* __s, streamsize __n)`` (from ``istream``)

```cpp
char data[11];
cin.getline(data, 100);
cout << data;
```

### setw()

```cpp
#include <iostream>
#include <iomanip> // io manipulation
using namespace std;

main() {
	cout << "Day  		Money \n"
	<< 	"---------------------------------\n";
	cout << 1 << setw(18) << 1 << "\n";
	cout << 1 << setw(18) << 1 << "\n";
	cout << 1987 << setw(18) << 1977 << "\n";
}
```

**Result**

```
Day  		Money 
---------------------------------
1                 1
1                 1
1987          1977
```