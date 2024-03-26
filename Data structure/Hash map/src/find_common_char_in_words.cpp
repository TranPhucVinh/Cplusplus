vector<string> commonChars(vector<string>& words) {
        vector<map<char, int>> Map_Vector;

        for (int i = 0; i < words.size(); i++){
            map<char, int> word_map;
            for (int j = 0; j < words[i].size(); j++){
                word_map[words[i][j]] += 1;
            }
            Map_Vector.push_back(word_map);
        }

        vector<string> ret_vec;
        map<char, int> Map_Vector_0 = Map_Vector[0];
        map<char, int>::iterator map_0_el = Map_Vector[0].begin();
                
        while (map_0_el != Map_Vector[0].end()) {
            int min_char = map_0_el->second;

            for (int i = 1; i < Map_Vector.size(); i++){
                if ((Map_Vector[i][map_0_el->first] >= 1) && (Map_Vector[i][map_0_el->first] <= min_char)) {
                    min_char = Map_Vector[i][map_0_el->first];
                } else if(!Map_Vector[i][map_0_el->first]) min_char = 0;
            }

            if (min_char) {
                for (int j = 0; j < min_char; j++) ret_vec.push_back(string(1, map_0_el->first));
            }
            
            map_0_el++;
        }

        return ret_vec;
    }
