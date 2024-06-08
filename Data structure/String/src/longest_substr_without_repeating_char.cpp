bool isDuplicate(string sub_char, string sub_str, int &dup_idx) {
    std::size_t index = sub_str.find(sub_char);
    if (index == string::npos) return false;
    else {
        dup_idx = index;
        return true;  
    }
}

int lengthOfLongestSubstring(string s) {
    vector<int> sub_str_sz; // Store the size of all available sub string

    if (s.size() == 0) return 0;
    if (s.size() == 1) return 1;

    string sub_str;// Store all size of all available sub string

    sub_str = string(1, s[0]);

    for (int i = 1; i < s.size(); i++) {
        int dup_idx = -1;// Index inside "string s" whenever the new char is duplicated
        if (!isDuplicate(string(1, s[i]), sub_str, dup_idx)) sub_str.push_back(s[i]);
        else {
            sub_str_sz.push_back(sub_str.size());
            string tmp_sub_str = sub_str;// Store the old sub_str
            sub_str = "";

            for (int j = dup_idx + 1; j < tmp_sub_str.size(); j++) {
                sub_str.push_back(tmp_sub_str[j]);
            }
            sub_str.push_back(s[i]);
        }
    }
    
    sub_str_sz.push_back(sub_str.size());// Push the last sub_str formed at index i = s.size() - 1
    vector<int>::iterator max_iter = max_element(sub_str_sz.begin(), sub_str_sz.end());

    return *max_iter;
}