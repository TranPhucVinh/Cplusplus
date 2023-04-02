For a variable of a class, ``this`` pointer will help working with that variable (i.e: Setting/modifying this variable) inside a method if there is a local variable with the same name.

For a method of a class, ``this`` pointer will help calling this method.

Implementation of ``this`` pointer:

* Set class variable value by a method
* Calling class methods inside another method

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int publicNumber;
		void get_var(){
            cout << publicNumber << "\n";

            //  Same result when using this->publicNumber
            //  cout << this->publicNumber << "\n";
		}
        void set_var(int publicNumber);
        void change_var();
        void display_string();
};

void classTest::set_var(int publicNumber){
    // This will set local variable publicNumber of function
    // set_var to class variable publicNumber
    this->publicNumber = publicNumber;
    this->display_string();// This is like calling display_string()
}

void classTest::change_var(){
    this->publicNumber += 10;
}

void classTest::display_string(){
    cout << "Hello, World !\n";
}

int main(){
	classTest object;
    object.set_var(100);
    object.get_var();//100
    object.change_var();
    object.get_var();//110
}
```
