# std::cout

```cpp
#include <iostream>

using namespace std;

main(){
	cout << "Hello, World!" << endl;
}
```

``\n`` and ``endl`` is the same. ``endl`` stands for endline.

By default ``iostream`` doesn't support printing out with formating like ``printf()``.

# std::cin

## Get entered int value from std::cin

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

## Get multiple entered int value from std::cin then print out

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

## Get an entered string from std::cin

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

## Infinite for loop for std::cin

```c
int number;
for(;cin >> number;){
	cout << "Entered: " << number << endl;
}
```
**Result**
```
1
Entered: 1
2
Entered: 2
...
```
This infinite loop will break if entering invalid value.
## Infinite while loop for std::cin to print out the entered int number
If entering the invalid value, like string, error message is poped out: ``Invalid input. Please enter a valid integer``
```cpp
#include <iostream>
#include <limits> // std::numeric_limits

using namespace std;

int main(){
	int number;
	while(1){
		cout << "Enter number: ";
		if (!(cin >> number)) {
			cout << "Invalid input. Please enter a valid integer." << endl;
			cin.clear();// Clear the error state of cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');// Clear the input buffer up to the newline character "\n" (removing the invalid input)
			continue; // Exit with error
		}

		cout << "Number: " << number << endl;
	}
}
```
In this example, the ``cin.clear()`` and ``cin.ignore()`` are mandatorily required to clean up the invalid buffer. Without them, after entering the invalid number, while(1) will keep popping out error message **Invalid input. Please enter a valid integer**.

# getline()

## API

``getline()`` is used to get the whole entered string (include space).

```c
istream& getline (istream& is, string& str, char delim);
istream& getline (istream& is, string& str);
```

## Read entered string

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

With ``cin.getline()``: ``getline(char_type* __s, streamsize __n)`` (from ``istream``)

```cpp
char data[11];
cin.getline(data, 100);
cout << data;
```

Enter multiple string with ``getline()``

```c
#include <iostream>

using namespace std;

int number;
string sentence1, sentence2, sentence3;

int main(){
	cout << "Enter sentence 1: ";
	getline(cin, sentence1);
	
	cout << "Enter sentence 2: ";
	getline(cin, sentence2);

	cout << "Enter sentence 3: ";
	getline(cin, sentence3);

	cout << "The whole sentence is: " << sentence1 << endl;
	cout << "The whole sentence is: " << sentence2 << endl;
	cout << "The whole sentence is: " << sentence3 << endl;
}
```

## Read the entered int and string
```cpp
#include <iostream>
#include <limits> // std::numeric_limits

using namespace std;

int number;
string sentence;

int main(){
	cout << "Enter int number: ";
	cin >> number;

	cin.clear();// Clear the error state of cin
	cin.ignore(numeric_limits<streamsize>::max(), '\n');// Clear the input buffer up to the newline character (removing the invalid input)

	cout << "Enter your sentence: ";
	getline(cin, sentence);

	cout << "Entered numer: " << number << endl;
	cout << "The whole sentence is: " << sentence << endl;
}
```
In this case, ``cin.ignore(numeric_limits<streamsize>::max(), '\n')`` will clear the input buffer up to the newline character (\n). This ensures that any leftover characters (including the newline character) from the input stream are discarded before we proceed to read the sentence using getline.

**This is an error program. Must not implement it in project**
```cpp
// THIS IMPLEMENTATION IS WRONG AS IT'S INTENTIONALLY USED FOR THE DEMONSTRATION TO THE NEED OF cin.clear() and cin.ignore()
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

After entering the int ``number`` and press enter, ``age`` value will appear then the programm stop as after entering ``ENTER`` (``\n``). This happens because ``getline()`` stops executing as knowing that ``ENTER``  (``\n``) has been pressed.

# setw()

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
