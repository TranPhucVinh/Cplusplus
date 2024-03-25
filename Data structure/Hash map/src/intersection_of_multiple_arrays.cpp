vector<int> intersection(vector<vector<int>>& nums) {
    if (nums.size() == 1) {
        sort(nums[0].begin(), nums[0].end());
        return nums[0];
    }

    vector<map<int, int>> Map_Vector;

    for (int i = 0; i < nums.size(); i++){
        map<int, int> _Map;
        for (int j = 0; j < nums[i].size(); j++){
            _Map[nums[i][j]] += 1;
        }
        Map_Vector.push_back(_Map);
    }

    vector<int> ret_vec;
    std::map<int, int> map_0 = Map_Vector[0];
    std::map<int, int>::iterator map_0_el = Map_Vector[0].begin();

   while (map_0_el != Map_Vector[0].end()) {
        bool no_push = false; // Case a number existed in a vector but not in another
        for (int i = 1; i < Map_Vector.size(); i++){
            if ((Map_Vector[i][map_0_el->first] >= 1) && !no_push) {
                ret_vec.push_back(map_0_el->first);
            } else {
                vector<int>::iterator non_existed_el = find(ret_vec.begin(), ret_vec.end(), map_0_el->first);
                if (non_existed_el != ret_vec.end()) {
                    vector<int>::iterator new_iter = remove(ret_vec.begin(), ret_vec.end(), map_0_el->first);
                    int new_sz = std::distance(ret_vec.begin(), new_iter);
                    ret_vec.resize(new_sz);
                }
                else no_push = true;
            }
        }
        
        map_0_el++;
    }

    sort(ret_vec.begin(), ret_vec.end());
    vector<int>::iterator last = unique(ret_vec.begin(), ret_vec.end());
    int new_sz = std::distance(ret_vec.begin(), last);// New size
    ret_vec.resize(new_sz);

    return ret_vec;
}
