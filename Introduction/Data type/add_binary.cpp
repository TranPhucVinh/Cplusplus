string addBinary(string a, string b) {
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
		if (!carried){
			if ( ((max_str[i] == '0') && (min_str[i] == '1'))||
			((max_str[i] == '1') && (min_str[i] == '0'))){
				ret_str = "1" + ret_str;
				carried = 0;
				continue;
			}

			if ((max_str[i] == '1') && (min_str[i] == '1')) {
				ret_str = "0" + ret_str;
				carried = 1;
				continue;
			}

			if ((max_str[i] == '0') && (min_str[i] == '0')) {
				ret_str = "0" + ret_str;
				carried = 0;
				continue;
			}
		} else {
			if ( ((max_str[i] == '0') && (min_str[i] == '1'))||
			((max_str[i] == '1') && (min_str[i] == '0'))){
				ret_str = "0" + ret_str;
				carried = 1;
				continue;
			}		
			if ((max_str[i] == '1') && (min_str[i] == '1')) {
				ret_str = "1" + ret_str;
				carried = 1;
				continue;
			}

			if ((max_str[i] == '0') && (min_str[i] == '0')) {
				ret_str = "1" + ret_str;
				carried = 0;
				continue;
			}
		}
	}
	if (carried) {
		ret_str = "1" + ret_str;
	}

    return ret_str;
}
