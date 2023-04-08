#include <iostream>
using namespace std;

class classTest {
	public:
		int intVal1;
		int intVal2;
		char charVal;
		bool boolVal;
};

int main()
{
	classTest object;

	object.intVal1 = 5;
	object.intVal2 = 10;
	object.charVal = 'a';
	object.boolVal = true;

	// Cast object to int pointer for later step to access to intVal1 and intVal2
	int* ptr = reinterpret_cast<int*>(&object);

	cout << sizeof(object) << endl;// 12, size of class classTest

	cout << *ptr << endl;// 5; ptr now point to object.intVal1

	ptr++;// Incrementing the *ptr by 1, it will now point to object.intVal2

	cout << *ptr << endl;// 10; *ptr now point to object.intVal2

	ptr++;// Incrementing the *ptr by 1, it will now point to object.charVal

	// Cast int pointer *ptr to char pointer *ch
	/*
		As *ptr now point to object.charVal, it needs to have the same type to
		access to object.charVal so we need a casting here
	*/
	char* ch = reinterpret_cast<char*>(ptr);

	cout << *ch << endl;// *ch now point to object.charVal

	ch++;// Incrementing the *ch by 1, it will now point to object.boolVal

	// Cast char pointer *ch to bool pointer *b
	/*
		As *ch now point to object.boolVal, it needs to have the same type to
		access to object.boolVal so we need a casting here
	*/
	bool* b = reinterpret_cast<bool*>(ch);
	cout << *b << endl;

	// We can also use this line of code to print the value pointed by (*ch)
	// cout << *(reinterpret_cast<bool*>(ch));

	return 0;
}