#include <iostream>
using namespace std;

class Complex {
    public:
        int real, img;
        Complex(int r = 0, int i = 0)
        {
            real = r;
            img = i;
        }
        void print() { 
            cout << this->real << " + i" << this->img << '\n';
        }
};

Complex operator+ (Complex complex_1, Complex complex_2)
{
    Complex _complex;
    _complex.real = complex_1.real + complex_2.real;
    _complex.img = complex_1.img + complex_2.img;
    return _complex;
}

int main()
{
	Complex c1(1, 2), c2(3, 4);
    c1.print();
    c2.print();
	Complex c3 = c1 + c2;
	c3.print();
}