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

With ``getline()``

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

With ``cin.getline()``: ``getline(char_type* __s, streamsize __n)``

```cpp
char data[11];
cin.getline(data, 100);
cout << data;
```

### Problem with ``getline()``

```cpp
#include <iostream>

using namespace std;

int number;
string sentence;

int main(){
	cout << "Enter int number: ";
	cin >> number;
	cout << "Enter your sentence: ";
	getline(cin, sentence);

	cout << "Entered numer: " << number << endl;
	cout << "The whole sentence is: " << sentence << endl;
}
```

After entering the int ``number`` and press enter, ``age`` value will appear then the programm stop as after entering ``ENTER``. This happens because ``getline()`` stops executing as knowing that ``ENTER`` has been pressed.

**Problem solved**

Using ``cin.ignore(1)``: Ignore the last entering character, in this case is ``ENTER``

```cpp
cout << "Enter age: ";
cin >> age;
cout << "Enter your sentence: ";
cin.ignore(1); 
getline(cin, sentence);

cout << "Entered numer: " << age << endl;
cout << "The whole sentence is: " << sentence << endl;
```

Using ``cin >> ws``: ``cin >> ws`` after ``cin`` statement tells the compiler to ignore buffer and also to discard all the whitespaces before the actual content of string or character array.

```cpp
cout << "Enter age: ";
cin >> age;
cout << "Enter your sentence: ";
cin >> ws;
getline(cin, sentence);

cout << "Entered numer: " << age << endl;
cout << "The whole sentence is: " << sentence << endl;
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