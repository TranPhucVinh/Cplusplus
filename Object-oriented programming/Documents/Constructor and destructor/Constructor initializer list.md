# Constructor initializer list

Constructor initializer list is used to defined member variables:
```cpp
class class_test{
	public:
		int public_number;
        class_test(int _public_number, int _private_number): public_number(_public_number), private_number(_private_number) {}
/*
        This constructor initializer list works like this:
        class_test(int _public_number, int _private_number){
            public_number = _public_number;
            private_number = _private_number;
        }
*/
		void get_number(){
            cout << "Get public and private numbers: \n";
            cout << "public_number " << public_number << "; ";
            cout << "private_numer " << private_number << endl;
		}

	private:
		int private_number;
};

int main(){
    class_test object(12, 34);
	object.get_number();
}
```
**Result**:
```
Get public and private numbers:
public_number 12; private_numer 34
```

Constructor initializer list with ``return``:

```cpp
#include <iostream>

using namespace std;

class class_test{
	public:
		int public_number;
        class_test(int value){
            public_number = value;
        }

        //Calling this construct to change value of public_number and private_numer
        class_test() : public_number(12), private_numer(13){
            return;
        }

		void get_number(){
            cout << "Get public and private numbers: \n";
            cout << "public_number " << public_number << "; ";
            cout << "private_numer " << private_numer << endl;
		}

	private:
		int private_numer = 2;
};

int main(){
	class_test object_1;
	object_1.get_number();

    class_test object_2(1);
	object_2.get_number();
}
```

**Result**
```
Get public and private numbers:
public_number 12; private_numer 13
Get public and private numbers:
public_number 1; private_numer 2
```
# Delegating constructor
**Delegating constructor** allows using one constructor as the delegator to define other constructors. Delegating constructor is supported since C++11
```c
#include <iostream>

using namespace std;
// delegating constructors only available with -std=c++11
class Base{
    private:
        int _a, _b;
        void print(){ cout << _a << " " << _b << " " << endl; }
	public:
    	Base(): Base(0, 0){}
        Base(int a): Base(a, 0) {}
        Base(int a, int b){ 
            _a = a;
            _b = b;
            print();
        }
};

main(){
	Base object0;// 0 0
    Base object1(123); //123 0
    Base object2(1, 2); //1 2
}
```
