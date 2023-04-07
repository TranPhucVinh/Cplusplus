For a variable of a class, ``this`` pointer will help working with that variable (i.e: Setting/modifying this variable) inside a method if there is a local variable with the same name.

For a method of a class, ``this`` pointer will help calling this method.

# this pointer for class function

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
# this pointer for class variable

Must not call this pointer outside class definition

```cpp
//Must not do this, this give compilation error
class Header
{
  public:
    int a;
    int b;
};

int main(){
    Header header;
    header.a = 19;
    header.b = this->a + 1;//Must not do this; invalid use of this pointer
}
```
# this pointer can only be used inside a nonstatic member function
As this pointer is intended for separated class object while static member (function, variable) are intended to be shared for all class objects, this pointer can only be used inside a nonstatic member function

Must not call this pointer inside class static function like this:

```cpp
//Must not do this,  this give compilation error
class Header
{
    public:
        int a = 19;
        static void change_value(int b){
            cout << this->a << endl;//error: 'this' is unavailable for static member functions
        }
};
```
