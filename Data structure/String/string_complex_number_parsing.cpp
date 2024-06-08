#include <iostream>
using namespace std;

class Complex {
    private:
        int _real, _img;
		Complex parse_complex(string s)
		{
			Complex complex_number;
			bool img_neg = false;// imagine part is negative
			bool real_neg = false;// real part is negative
			int real = 0;
			int i = 0;
			while(s[i] != '+')
			{
				if (s[i] == '-'){
					real_neg = true;
					i += 1;
					continue;
				} 
				real = real*10 + s[i] - '0';
				i++;
			}
			while(s[i] == ' ' || s[i] == '+' || s[i] == '-')
			{
				if (s[i] == '-') img_neg = true;
				i++;
			}
			int img = 0;
			while(i < s.length()-1)
			{
				img = img*10 + s[i] - '0';
				i++;
			}

			if (real_neg) complex_number._real = real*-1;
			else complex_number._real = real;

			if (img_neg) complex_number._img = img*-1;
			else complex_number._img = img;

			return complex_number;
		}
    public:
		Complex(){};

		string complexNumberMultiply(string num1, string num2) {
			Complex num1_com, num2_com, ret_com;
			string ret_com_str;

			num1_com = parse_complex(num1);
			num2_com = parse_complex(num2);

			cout << num1_com._real << " " << num1_com._img << endl;
			cout << num2_com._real << " " << num2_com._img << endl;

			ret_com._real = num1_com._real*num2_com._real - num1_com._img*num2_com._img;
			ret_com._img = num1_com._real*num2_com._img + num2_com._real*num1_com._img;

			ret_com_str = to_string(ret_com._real) + "+" + to_string(ret_com._img) + "i";
			return ret_com_str;
		}	
};

int main()
{
	Complex c1;
	cout << c1.complexNumberMultiply("78+-76i", "-86+72i") << endl;
}
