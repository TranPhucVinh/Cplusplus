vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> ret_vec;

    std::map<int, int> Map;
    std::map<int, vector<int>> ordered_map;// Use vector for case multiple keys have the same freq

    for (int i = 0; i < nums.size(); i++){
        Map[nums[i]] += 1;
    }

    // Create a new map with (key, value) from (value, key) of an existed map
    std::map<int, int>::iterator itr;
    std::map<int, vector<int>>::iterator order_map_itr;

    for (itr = Map.begin(); itr != Map.end(); itr++) { 
        int key = itr->first;
        int value = itr->second;

        order_map_itr = ordered_map.find(value);
        if (order_map_itr != ordered_map.end()) {
            order_map_itr->second.push_back(key);// Value already exists in order_map_itr
        } else {
            ordered_map[value] = {key};// Value doesn't exist in order_map_itr
        }
    } 

    order_map_itr = ordered_map.begin();
    int map_index = ordered_map.size() - 1;

    while (ret_vec.size() < k  && map_index >= 0) {
        advance(order_map_itr, map_index);
        for (int i = 0; i < order_map_itr->second.size(); i++) {
            ret_vec.push_back(order_map_itr->second[i]);
        }

        map_index -= 1;

        if (map_index >= 0) {
            order_map_itr = ordered_map.begin();  // Reset the iterator to the beginning
        }
    }

    return ret_vec;
}
