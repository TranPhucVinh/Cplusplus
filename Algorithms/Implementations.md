# Find the max number of a 2D array, along with its index
```cpp
vector<int> max_vec;
vector<vector<int>> max_vec_index;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    // Find the max element inside each array mat[i] then put them into max_vec
    // Find the corresponding index of that max element then put them into max_vec_index
    for (int i = 0; i < mat.size(); i++){
        vector<int>::iterator max_iter = std::max_element(mat[i].begin(), mat[i].end());
        int max_index = std::distance(mat[i].begin(), max_iter);

        vector<int> vec_index = {i, max_index};

        max_vec.push_back(*max_iter);
        max_vec_index.push_back(vec_index);
    }

    // Find the max element of max_vec and return its index
    vector<int>::iterator max_iter = std::max_element(max_vec.begin(), max_vec.end());
    int max_index = std::distance(max_vec.begin(), max_iter);

    return max_vec_index[max_index];
}
```
# Find the difference of two arrays

* nums1 = [1,2,3], nums2 = [2,4,6]
* Result: [[1,3],[4,6]]

* nums1 = [1,2,3,3], nums2 = [1,1,2,2]
* Result: [[3],[]]

* nums1 = [-68,-80,-19,-94,82,21,-43], nums2 = [-63]
* Result: [[-19,82,-68,21,-43,-94,-80],[-63]]

* nums1 = [26,48,-78,-25,42,-8,94,-68,26], nums2 = [61,-17]
* Result: [[-78,-68,-25,-8,26,42,48,94],[-17,61]]

* nums1 = [-1000], nums2 = [-1000]; nums1 = [2, 2], nums2 = [2]
* Result: [[], []]

```cpp
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    // Assign to nums1 to its clone to avoid wrong removing inside the for() loop
    vector<int> nums1_clone = nums1;

    int nums1_sz = nums1.size();
    int nums2_sz = nums2.size();

    std::vector<int>::iterator nums1_new_end, nums2_new_end;
    int nums1_new_sz = 0, nums2_new_sz = 0;

    bool first_find = false;

    for (int i = 0; i < nums1_clone.size(); i++){
        // Must assign nums1_clone[i] to a temp variable
        // Mustn't pass it directly to std::remove() as this will effect nums1_clone
        int number = nums1_clone[i];

        vector<int>::iterator nums2_iter = find(nums2.begin(), nums2.end(), number);
        if (nums2_iter != nums2.end()){
            if (!first_find) {
                nums1_new_end = nums1.end();
                nums2_new_end = nums2.end();
                first_find = true;
            }
            nums1_new_end = std::remove(nums1.begin(), nums1_new_end, number);
            nums2_new_end = std::remove(nums2.begin(), nums2_new_end, number);

            nums1_new_sz = std::distance(nums1.begin(), nums1_new_end);
            nums2_new_sz = std::distance(nums2.begin(), nums2_new_end);
        }                
    }

    vector<int> nums1_new, nums2_new;

    // Check !nums1_new_sz && !nums2_new_sz && !first_find for cases:
    // nums1 = [-1000]; nums2 = [-1000]
    // nums1 = [2, 2]; nums2 = [2] => Return {{}, {}}

    if (!nums1_new_sz && !nums2_new_sz && !first_find){
        nums1_new_sz = nums1.size();
        nums2_new_sz = nums2.size();
    }

    for (int i = 0; i < nums1_new_sz; i++){
        nums1_new.push_back(nums1[i]);
    }

    for (int i = 0; i < nums2_new_sz; i++){
        nums2_new.push_back(nums2[i]);
    }

    // Sort to use unique
    sort(nums1_new.begin(), nums1_new.end());
    sort(nums2_new.begin(), nums2_new.end());

    nums1_new_end = unique(nums1_new.begin(), nums1_new.end());
    int new_sz = std::distance(nums1_new.begin(), nums1_new_end);
    nums1_new.resize(new_sz);

    nums2_new_end = unique(nums2_new.begin(), nums2_new.end());
    new_sz = std::distance(nums2_new.begin(), nums2_new_end);
    nums2_new.resize(new_sz);

    return {nums1_new, nums2_new};
}
```
