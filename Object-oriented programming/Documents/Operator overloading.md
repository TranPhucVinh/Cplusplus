# Fundamental concept
**Operator overloading** is a compile-time polymorphism which gives a special meaning to an existing operator in C++ without changing its original meaning.

In this complex number as object created from class ``Complex``, we want the ``+`` operator to have the ability to add its real and imagine part.
```cpp
// THIS IMPLEMENTATION IS WRONG AND GIVES COMPILATION ERROR AS IT'S INTENTIONALLY USED FOR
// THE DEMONSTRATION TO THE NEED OF operator overloading USAGE
#include <iostream>
using namespace std;

class Complex {
    private:
        int real, img;

    public:
        Complex(int r = 0, int i = 0)
        {
            real = r;
            img = i;
        }
        void print() { 
            cout << this->real << " + i" << this->img << '\n';
            // Same as:
            // cout << real << " + i" << img << '\n'; 
        }
};

int main()
{
	Complex c1(1, 2), c2(3, 4);
    c1.print();
    c2.print();
	Complex c3 = c1 + c2;
}
```
**Error**:
```
no match for ‘operator+’ (operand types are ‘Complex’ and ‘Complex’)
Complex c3 = c1 + c2;
```
To have ``+`` operator as the overloading operator for those complex number in class Complex, we need to define the ``+`` overloading operator function inside class ``Complex``:

The syntax for the overloading operator function is:
```cpp
<class_name> operator<operator_symbol>(<class_name> const& <class_object>)
{
    //Definition goes here
}
```
Please note that the [const reference](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/const%20reference.md) is required here.

So for the complex number of class Complex, the ``+`` overloading operator function now is ``operator+``:
```cpp
Complex operator+(Complex const& obj)
{
    Complex result;
    result.real = real + obj.real;
    result.img = img + obj.img;
    return result;
}
```
So the full program is:
```cpp
#include <iostream>
using namespace std;

class Complex {
    private:
        int real, img;

    public:
        Complex(int r = 0, int i = 0)
        {
            real = r;
            img = i;
        }
        void print() { 
            cout << this->real << " + i" << this->img << '\n';
        }

        // This is automatically called when '+' is used with
        // between two Complex objects
        Complex operator+(Complex const& obj)
        {
            Complex result;
            result.real = real + obj.real;
            result.img = img + obj.img;
            return result;
        }
};

int main()
{
	Complex c1(1, 2), c2(3, 4);
    c1.print();
    c2.print();
	Complex c3 = c1 + c2;
	c3.print();
}
```
# Using [friend](https://github.com/TranPhucVinh/Cplusplus/blob/master/Object-oriented%20programming/friend.md) method when the objects of the overloading operator function try to access to the private member
```cpp
class Complex {
//Other definitions are unchanged

	// This gives compilation error as c1 and c2 trying to access to private member
        // Complex operator+(Complex const& c1, Complex const& c2)
        // {
        //     Complex result;
        //     result.real = c1.real + c2.real;
        //     result.img = c1.img + c2.img;
        //     return result;
        // }
	// Use friend as c1, c2 access to private member
	friend Complex operator+(Complex const& c1, Complex const& c2)
        {
            Complex result;
            result.real = c1.real + c2.real;
            result.img = c1.img + c2.img;
            return result;
        }
};

int main()
{
	Complex c1(1, 2), c2(3, 4);
    c1.print();
    c2.print();
	Complex c3 = c1 + c2;
	c3.print();
}
```
# What operators can be overloaded ?
Almost all operators can be overloaded like:
* [Unary operators](https://github.com/TranPhucVinh/C/blob/master/Introduction/Variable/README.md#unary-operators)
* [Binary operators]()
* Special operators like ``[]``, ``()``,...
# What operators can't be overloaded ?
* sizeof
* typeid
* Scope resolution (::)
* Class member access operators (.(dot), .* (pointer to member operator))
* Ternary or conditional (?:)
# Applications of operator overloading
* Operator overloading in vector for comparison: ==, >, <, <= and >=