string frequencySort(string s) {
        std::map<char, int> Map;
        std::map<int, vector<char>, greater<int>> ordered_map;// Use vector for case multiple keys have the same freq

        for (int i = 0; i < s.size(); i++){
            Map[s[i]] += 1;
        }

        std::map<char, int>::iterator itr;
        std::map<int, vector<char>>::iterator order_map_itr;

        for (itr = Map.begin(); itr != Map.end(); itr++) 
        { 
            char key = itr->first;
            int value = itr->second;

            order_map_itr = ordered_map.find(value);
            if (order_map_itr != ordered_map.end()) {
                order_map_itr->second.push_back(key);// Value already exists in order_map_itr
            } else {
                ordered_map[value] = {key};// Value doesn't exist in order_map_itr
            }
        } 

        vector<char> ret_vec;

        for (order_map_itr = ordered_map.begin(); order_map_itr != ordered_map.end(); order_map_itr++){
            for (int i = 0; i < order_map_itr->second.size(); i++){                
                for (int j = 0; j < order_map_itr->first; j++){
                    ret_vec.push_back(order_map_itr->second[i]);
                }
            }
        }

        string ret_str;
        for (int i = 0; i < ret_vec.size(); i++) ret_str += string(1, ret_vec[i]);

        return ret_str;
}
