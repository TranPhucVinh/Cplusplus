vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    std::map<int, int> Map_1, Map_2;

    for (int i = 0; i < nums1.size(); i++){
        Map_1[nums1[i]] += 1;
    }

    for (int i = 0; i < nums2.size(); i++){
        Map_2[nums2[i]] += 1;
    }

    vector<int> ret_vec;

    if (Map_2.size() >= Map_1.size()){
        std::map<int, int>::iterator el = Map_1.begin();
        while (el != Map_1.end()) {
            if ((el->second >= 1) && (Map_2[el->first] >= 1)) ret_vec.push_back(el->first);
            // count += 1;
            el++;
        }
    } else {
        std::map<int, int>::iterator el = Map_2.begin();
        while (el != Map_2.end()) {
            if ((el->second >= 1) && (Map_1[el->first] >= 1)) ret_vec.push_back(el->first);
            el++;
        }
    }

    return ret_vec;
}
