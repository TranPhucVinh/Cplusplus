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

        // This is automatically called when '+' is used between two Complex objects
        Complex operator+ (Complex obj)
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