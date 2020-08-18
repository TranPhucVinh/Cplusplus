### Stream out

```cpp
#include <iostream>

using namespace std;

main(){
	cout << "Hello, World!" << endl;
}
```

``\n`` and ``endl`` is the same. ``endl: endline``

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

A proper word entering can be solved with ``fgets()``:

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

### getline()

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

Problem with ``getline()``

```cpp
#include <iostream>

using namespace std;

main(){
	int age;
	cout << "enter age: ";
	cin >> age;
	cout << age;
	string sentence;
	cout<< "what is your sentence ? \n";
	getline(cin, sentence);
	cout << "The whole sentence is: " << sentence;
}
```

After entering the value of ``age`` and press enter, ``age`` value will appear then the programm stop as after entering "ENTER", this will be in buffer then getline will stop as knowing that ENTER has been pressed.

```cpp
#include <iostream>

using namespace std;

main(){
	int age;
	cout << "enter age: ";
	cin >> age;
	cout << age;
	string sentence;
	cout << "what is your sentence ? \n";
	cin.ignore(1); //ignore the last entering character, in this case is "ENTER"
	getline(cin, sentence);
	cout << "The whole sentence is: " << sentence;
}
```

### cin.getline()

``cin.getline()`` allows you to enter a string which has white spaces too. 

Its syntax is as follows: ``cin.getline(name of string , size of the string);``

**Enter a string to a file**

```cpp
ofstream myFile("file.txt");
char data[111];
cin.getline(data, 100);
myFile << data;
myFile.close();
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