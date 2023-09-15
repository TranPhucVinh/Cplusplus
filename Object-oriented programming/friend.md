# friend class
A friend class can access private and protected members of other classes in which it is declared as a friend.
```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		friend class friendClass;
		int publicNumber = 123;
		void display_str(){
			cout << "friendClass is a friend class of classTest\n";
		}
	private:
		int privateNumer = 456; //Unable to read that value outside
};

class friendClass {
	public:
		void read_all_var(classTest classTestObj){
			cout << classTestObj.publicNumber << "\n";
			cout << classTestObj.privateNumer << "\n";
			classTestObj.display_str();
		}
};

int main(){
	friendClass obj;
	classTest object;
	obj.read_all_var(object);
}
```
# friend function

A **friend function** can be granted special access to private and protected members of a class. They can be global function or method of another class

# Use a global function as a friend method to change public and private member of an object
```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int publicNumber = 123;

		// Display all public and private variables
		void disp_var(){
			cout << publicNumber << "\n";
			cout << privateNumer << "\n";
		}
		friend void change_obj_var(classTest &obj, int public_var, int private_var);
	private:
		int privateNumer = 456;
};

void change_obj_var(classTest &obj, int public_var, int private_var){
	obj.publicNumber = public_var;
	obj.privateNumer = private_var;
}

int main(){
	classTest object;
	object.disp_var();// 123 456
	change_obj_var(object, 789, 321);
	object.disp_var();// 789 321
}
```

# Use a class method as a friend method to change public and private member of an object
```cpp
// In order to use a class method as a friend member of another class, the following
// declaring sequences must be followed 
#include <iostream>

using namespace std;

class classTest;// Must declare classTest at first

class otherClass{
	public:
		// As change_obj_var is the friend member of another class and tries to access
		// the private member of this class, it musn't be declared here
	    void change_obj_var(classTest &obj, int public_var, int private_var);
};

class classTest{
	public:
		int publicNumber = 123;

		void disp_var(){
			cout << publicNumber << "\n";
			cout << privateNumer << "\n";
		}
		friend void otherClass::change_obj_var(classTest &obj, int public_var, int private_var);
	private:
		int privateNumer = 456;
};

// As change_obj_var is the friend member of another class and tries to access
// the private member of this class, it must be declared outside its class
void otherClass::change_obj_var(classTest &obj, int public_var, int private_var){
	obj.publicNumber = public_var;
	obj.privateNumer = private_var;
}

int main(){
	classTest object_1;
	otherClass object_2;
	object_1.disp_var();// 123 456
	object_2.change_obj_var(object_1, 789, 321);
	object_1.disp_var();// 789 321
}
```
