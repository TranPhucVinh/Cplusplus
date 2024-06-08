/*
There are rules for 3 characters:
	* I can only be placed before V or X, represents subtract one, so IV (5-1) = 4 and 9 is IX (10-1)=9.
	* X can only be placed before L or C represents subtract ten, so XL (50-10) = 40 and XC (100-10)=90.
	* C can only be placed before D or M represents subtract hundred, so CD (500-100)=400 and CM (1000-100)= 900.
By those 3 rules, will take 4, 9, 40, 90, 400 and 900 as special characters, which are defined inside the Roman_Numerals vector tuple
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <tuple>

using namespace std;

class RomanNumberals {
    public:
        RomanNumberals(){
            Roman_Numerals[0] = std::make_tuple("I", 1);
            Roman_Numerals[1] = std::make_tuple("IV", 4);
			Roman_Numerals[2] = std::make_tuple("V", 5);
            Roman_Numerals[3] = std::make_tuple("IX", 9);
			Roman_Numerals[4] = std::make_tuple("X", 10);
            Roman_Numerals[5] = std::make_tuple("XL", 40);
			Roman_Numerals[6] = std::make_tuple("L", 50);
            Roman_Numerals[7] = std::make_tuple("XC", 90);
			Roman_Numerals[8] = std::make_tuple("C", 100);
            Roman_Numerals[9] = std::make_tuple("CD", 400);
			Roman_Numerals[10] = std::make_tuple("D", 500);
            Roman_Numerals[11] = std::make_tuple("CM", 900);
			Roman_Numerals[12] = std::make_tuple("M", 1000);

            sgl_roman_char = new char[3];// sgl_roman_char takes 2 character so assign by 3 to avoid heap-buffer-overflow
        }
        ~RomanNumberals(){
            delete[] sgl_roman_char;
        }
        string intToRoman(int num) {
            strcpy(sgl_roman_char, find_roman_char(num));
            if (sgl_roman_char[0] != 'W'){
                return string(sgl_roman_char);
            } else {
                string roman_numerals_str;
                while (num > 0){
                    decrease_number_to_find_roman_char(roman_numerals_str, &num);
                }
                return roman_numerals_str;
            }
        }
    private:
        std::vector<std::tuple<const char*,int>> Roman_Numerals = std::vector<std::tuple<const char*,int>>(13);
        char *sgl_roman_char;
		int roman_numerals[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

		const char *find_roman_char(int number){
			for (int i = 0; i < Roman_Numerals.size(); i++){
				if (get<1>(Roman_Numerals[i]) == number) return get<0>(Roman_Numerals[i]);
		    }
			return "W";
        }
        void decrease_number_to_find_roman_char(string &roman_numerals_str, int *number){
            if (*number > roman_numerals[12]){
                *number -= roman_numerals[12];
                roman_numerals_str += get<0>(Roman_Numerals[12]);
            }
            for (int i = 0; i < 13; i++){
                if ((*number > roman_numerals[i]) && (*number < roman_numerals[i+1])){
                    *number -= roman_numerals[i];
                    roman_numerals_str += get<0>(Roman_Numerals[i]);
                } else if (*number == roman_numerals[i]){
                    roman_numerals_str += find_roman_char(*number);
                    *number -= roman_numerals[i];
                }                
            }
        }
};

int main()
{
    RomanNumberals rn;
    return 0;
}
