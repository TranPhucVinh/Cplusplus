#include <iostream>

using namespace std;

string add_int(string a, string b) {
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
        int _tmp_sum = stoi(string(1, max_str[i])) + stoi(string(1, min_str[i]));
		if (!carried){
            if (_tmp_sum < 10){
                ret_str = to_string(_tmp_sum) + ret_str;
                carried = 0;
            } else {
                ret_str = string(1, to_string(_tmp_sum)[1]) + ret_str;
                carried = 1;
            }
        } else {
            int _carried_sum = carried + _tmp_sum;
            if (_carried_sum < 10){
                ret_str = to_string(_carried_sum) + ret_str;
                carried = 0;
            } else {
                ret_str = string(1, to_string(_carried_sum)[1]) + ret_str;
                carried = 1;
            }
        }
    }
	if (carried) {
		ret_str = "1" + ret_str;
	}

    return ret_str;
}

int main(){
    cout << add_int("401716832807512840963", "167141802233061013023557397451289113296441069") << endl;
}
