#include <iostream>
#include <algorithm>

using namespace std;

string add_numbers(string a, string b);

int main() {
    cout << add_numbers("45678910", "1011121314") << endl;
    return 0;
}

string add_numbers(string a, string b) {
	string max_str, min_str;
	string ret_str; // Returned string

	if (a.size() >= b.size()){
		max_str = a;
		min_str = b;
	} else {
		max_str = b;
		min_str = a;
	}

	if (max_str.size() != min_str.size()){
		while (max_str.size() > min_str.size()){
			min_str.insert(0, "0");
		}
	}

	int carried = 0;
	for (int i = max_str.size()-1; i >= 0; i--){
        // Carried occurs at "10", e.g by "1" + "9" = 49 + 57
		if (!carried){
			if ((max_str[i] + min_str[i]) < 106) {
                // When there is no carried after 2 characters added, e.g "2" + "3" = "5" = 53 
                // "2" is 50 and "3" is 51, and we just want the character to be "5", 
                // so there must be an offest value
                // the off_set is 50 + 51 - 53 = 48
                ret_str += max_str[i] + min_str[i] - 48;
                carried = 0;
            } else {
                // When there is carried after 2 characters added, e.g "9" + "2" = "11" and we
                // take "1" for the last character.
                // "1" is 49, while "9" is 57 and "2" is 50.
                // So the offset is 57 + 50 - 49 = 58
                ret_str += max_str[i] + min_str[i] - 58;
                carried = 1;
            }
		} else {
            /*
                When 2 characters are added with a carried:
                As adding carried is adding character "1", which is 49, so we have those 2 conditions
            */
            if ((max_str[i] + min_str[i] + 49) < 154) {
                // Example: "2" + "3" + "1" = "6"
                // 50 + 51 + 49 + offset = 54 -> offset = 96
                ret_str += (max_str[i] + min_str[i] + 49) - 96;
                carried = 0;
            } else {
                // Example: "9" + "3" + "1" = "13", take "3"
                // 57 + 51 + 49 + offset = 51 -> offset = -106
                ret_str += (max_str[i] + min_str[i] + 49) - 106;
                carried = 1;
            }
		}
	}
	if (carried) {
		ret_str += "1";
	}

    reverse(ret_str.begin(), ret_str.end());
    return ret_str;
}
