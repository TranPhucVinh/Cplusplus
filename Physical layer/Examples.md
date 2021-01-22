**Example 1**: Enter multiple string with ``getline()``

```c
#include <iostream>

using namespace std;

int number;
string sentence1, sentence2, sentence3;

int main(){
	cout << "Enter sentence1: ";
	getline(cin, sentence1);
	
	cout << "Enter sentence2: ";
	getline(cin, sentence2);

	cout << "Enter sentence3: ";
	getline(cin, sentence3);

	cout << "The whole sentence is: " << sentence1 << endl;
	cout << "The whole sentence is: " << sentence2 << endl;
	cout << "The whole sentence is: " << sentence3 << endl;
}
```
**Example 2**: Problem with ``getline()``

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

**Example 3**: ``cin`` in foor loop

```c
#include <iostream>
#include <fstream>

using namespace std;

int number;

main() {
	for(;cin >> number;){
		cout << "Hello";
	}
}
```

Result: Infinite loop if entering valid number, break if entering invalid value
