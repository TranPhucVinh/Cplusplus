#include <iostream>
#include <map>

using namespace std;

class RomanNumberals {
    public:
        RomanNumberals(){
            Roman_Numerals['I'] = 1;
            Roman_Numerals['V'] = 5;
            Roman_Numerals['X'] = 10;
            Roman_Numerals['L'] = 50;
            Roman_Numerals['C'] = 100;
            Roman_Numerals['D'] = 500;
            Roman_Numerals['M'] = 1000;
        }
        int romanToInt(string s) {
            int index = 0;
            int number = 0;
            while (index < s.size()){
                if (Roman_Numerals[s[index]] >= Roman_Numerals[s[index+1]]){
                    number += Roman_Numerals[s[index]];
                    index += 1;
                } else {
                    number += Roman_Numerals[s[index+1]] - Roman_Numerals[s[index]];
                    index += 2;
                }
            }

            std::cout << number << std::endl;
            return 0;
    }
    private:
        std::map<char, int> Roman_Numerals;
};

int main()
{
    RomanNumberals rn;
    rn.romanToInt("MCMXCIV");// 1994
    return 0;
}