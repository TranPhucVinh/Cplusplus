int countCharacters(vector<string>& words, string chars) {
    map<char, int> chars_map;
    for (int i = 0; i < chars.size(); i++){
        chars_map[chars[i]] += 1;
    }

    vector<string> ret_vec;
    for (int i = 0; i < words.size(); i++){
        int valid_mem = true;

        map<char, int> word_i_map;

        for (int j = 0; j < words[i].size(); j++){
            word_i_map[words[i][j]] += 1;
        }

        map<char, int>::iterator el = word_i_map.begin();

        while (el != word_i_map.end()) {
            if (chars_map[el->first] < el->second){
                valid_mem = false;
                break;
            }
            el++;
        }

        if (valid_mem) ret_vec.push_back(words[i]);
    }

    int ret = 0;
    for (int i = 0; i < ret_vec.size(); i++){
        ret += ret_vec[i].size();
    }

    return ret;
}
