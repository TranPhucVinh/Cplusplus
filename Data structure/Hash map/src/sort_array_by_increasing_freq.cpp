vector<int> frequencySort(vector<int>& nums) {
    std::map<int, int> Map;
    std::map<int, vector<int>> ordered_map;// Use vector for case multiple keys have the same freq

    for (int i = 0; i < nums.size(); i++){
        Map[nums[i]] += 1;
    }

    std::map<int, int>::iterator itr;
    std::map<int, vector<int>>::iterator order_map_itr;

    for (itr = Map.begin(); itr != Map.end(); itr++) 
    { 
        int key = itr->first;
        int value = itr->second;

        order_map_itr = ordered_map.find(value);
        if (order_map_itr != ordered_map.end()) {
            order_map_itr->second.push_back(key);// Value already exists in order_map_itr
        } else {
            ordered_map[value] = {key};// Value doesn't exist in order_map_itr
        }
    } 

    vector<int> ret_vec;

    for (order_map_itr = ordered_map.begin(); order_map_itr != ordered_map.end(); order_map_itr++){
        
        sort(order_map_itr->second.begin(), order_map_itr->second.end(), std::greater<int>());

        for (int i = 0; i < order_map_itr->second.size(); i++){                
            for (int j = 0; j < order_map_itr->first; j++){
                ret_vec.push_back(order_map_itr->second[i]);
            }
        }
    }

    return ret_vec;
}
