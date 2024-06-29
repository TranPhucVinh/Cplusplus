string multiply(string num1, string num2) {
    string ret_str;

    // Case num1 = "99", num2 = "9"
    while (num1.size() < num2.size()) {
        num1.insert(0, "0");
    }

    while (num2.size() < num1.size()) {
        num2.insert(0, "0");
    }

    // Expected num1.size() = num2.size() for the later steps implementations
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int multiply_num_sz = num1.size() + num2.size();

    vector<string> all_multiply;
    for (int i = 0; i < num2.size(); i++){
        string tmp_str;
        int carried = 0;
        for (int j = 0; j < num1.size(); j++) {
            int tmp = (num2[j] - 48) * (num1[i] - 48) + carried;
            if (tmp >= 10) {
                carried = tmp/10;
                tmp_str.push_back((tmp % 10) + 48);// +48 for character conversion to their ASCII code
            } else {
                tmp_str.push_back(tmp + 48);// +48 for character conversion to their ASCII code
                carried = 0;
            }
        }
        if (carried) tmp_str.push_back(carried + 48);

        reverse(tmp_str.begin(), tmp_str.end());

        int k = 0;
        while (k < i) {
            tmp_str.append("0");
            k += 1;
        }

        while (tmp_str.size() < multiply_num_sz){
            tmp_str.insert(0, "0");
        }

        reverse(tmp_str.begin(), tmp_str.end());
        all_multiply.push_back(tmp_str);
    }

    int carried = 0;
    for (int i = 0; i < multiply_num_sz; i++) {
        int tmp = 0;
        for (int j = 0; j < all_multiply.size(); j++) {
            tmp += all_multiply[j][i] - 48;
        }
        tmp += carried;

        if (tmp >= 10) {
            carried = tmp/10;
            ret_str.push_back((tmp%10) + 48);// +48 for character conversion to their ASCII code
        } else {
            ret_str.push_back(tmp + 48);// +48 for character conversion to their ASCII code
            carried = 0;
        }
    }

    reverse(ret_str.begin(), ret_str.end());
    // cout << ret_str << endl;

    while (ret_str[0] == '0' && ret_str.size() > 1){
        ret_str.erase(0, 1);// Delete 1 character '0' from index 1
    }
    
    return ret_str;
}
