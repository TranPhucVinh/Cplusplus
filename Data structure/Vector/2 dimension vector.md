# Count pairs of similar strings

Two strings are similar if they consist of the same characters.

* "abca" and "cba" are similar since both consist of characters 'a', 'b', and 'c'.
* However, "abacba" and "bcfd" are not similar since they do not consist of the same characters.

* Input: words = ["aba","aabb","abcd","bac","aabc"]
* Output: 2. Pair ("aba","aabb") and ("bac","aabc")

* Input: words = ["aabb","ab","ba"]
* Output: 3. Pair: ("aabb","ab"), ("aabb", "ba"), ("ab","ba")

```cpp
int similarPairs(vector<string>& words) {
    vector<vector<char>> words_vector;

    for (int i = 0; i < words.size(); i++){
        vector<char> char_vector;
        for (int j = 0; j < words[i].size(); j++){
            vector<char>::iterator iter = find(char_vector.begin(), char_vector.end(), words[i][j]);
            if (iter == char_vector.end()) {
                char_vector.push_back(words[i][j]);
            }
        }
        if (char_vector.size() > 0) {
            sort(char_vector.begin(), char_vector.end());
            words_vector.push_back(char_vector);
        }
    }

    if (!words_vector.size()) return 0;

    int count = 0;

    for (int i = 0; i < words_vector.size(); i++){
        for (int j = i + 1; j < words_vector.size(); j++){
            if (words_vector[i] == words_vector[j]) count += 1;
        }
    }

    return count;
}
```