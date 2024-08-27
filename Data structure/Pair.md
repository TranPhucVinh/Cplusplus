A pair can be inserted into a map, unordered map as its member.
# Create
```cpp
#include <iostream>

int main()
{
    std::pair<int, int> pair_obj(1, 2);
    std::cout <<  pair_obj.first << " " << pair_obj.second;// 1 2

    return 0;
}
```
Use **std::make_pair()**:
```cpp
std::pair<int, int> pair_obj = std::make_pair(3, 4);
```
# Pair as function argument
```cpp
#include <iostream>

void change_pair(std::pair<int, int> &pair_obj){
    pair_obj.first += 1;
    pair_obj.second += 1;
}

int main()
{
    std::pair<int, int> pair_obj(1, 2);
    std::cout <<  pair_obj.first << " " << pair_obj.second << std::endl;// 1 2
    change_pair(pair_obj);
    std::cout <<  pair_obj.first << " " << pair_obj.second << std::endl;// 1 2

    return 0;
}
```
# Use pair to find the index of the original member of a vector after sorting
Algorithm:
* Create a vector of pair to store the indices of all member of the original vector before sorting, where in each pair, first is the indeces, and second is the member.
* Sort this vector based on the second values of each pair, i.e the vector's member. Use std::sort() with the 3rd argment is a function 
* After sorting, the vector of indices will reflect the order of the sorted data, and you can use it to reference the original positions.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator function for sorting indices
bool compareIndices(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    vector<int> data = {30, 10, 50, 20, 40};

    // Create a vector of pairs, where each pair is (index, value)
    vector<pair<int, int>> indexValuePairs;
    for (int i = 0; i < data.size(); ++i) {
        indexValuePairs.push_back(make_pair(i, data[i]));
    }

    // Sort the vector of pairs based on the values
    sort(indexValuePairs.begin(), indexValuePairs.end(), compareIndices);

    // Output the sorted data and original indices
    cout << "Sorted data with original indices:\n";

    for (int i = 0; i < indexValuePairs.size(); i++) {
        cout << "Data: " << indexValuePairs[i].second << " at original index: " << indexValuePairs[i].first << "\n";
    }

    return 0;
}
```
# Find subsequence of length k with the largest sum
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum. 
* nums = [5, -7, -20, -21, -23, -45, -8], K = 3. The answer must be [5, -7, -8]. If you answer [-8, -7, 5], you're wrong.

**Algorithm**:
* **Step 1**: Create ``indexValuePairs``, a vector of pairs, where each pair is (indice, value) (as stated in Intuition)
* **Step 2**: Sort ``indexValuePairs`` by the second value of each pair into non-decreasing order. This is similar to sorting ``nums``, except ``indexValuePairs`` also stores the indice value.
* **Step 3**: Get the last k members of ``indexValuePairs``, then store into ``vector<pair<int, int>> ret_vec_pair``, a vector of pair.
* **Step 4**: Sort ``ret_vec_pair`` by the first value so that they will follow the sequence order in the original vector ``nums``.
* **Step 5**: Append all the second of each pair of ``ret_vec_pair`` into vector ``ret_vec``. That's the answer.

```cpp
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> data = nums;
        vector<pair<int, int>> ret_vec_pair;
        vector<int> ret_vec;

        // Create a vector of pairs, where each pair is (index, value)
        vector<pair<int, int>> indexValuePairs;
        for (int i = 0; i < data.size(); ++i) {
            indexValuePairs.push_back(make_pair(i, data[i]));
        }

        // Sort the vector of pairs based on the values
        sort(indexValuePairs.begin(), indexValuePairs.end(), compareValues);

        int index = nums.size() - k;

        while (index < nums.size()) {
            ret_vec_pair.push_back(indexValuePairs[index]);
            index += 1;
        }

        // Sort ret_vec_pair based on their first value, as the original indices from nums
        sort(ret_vec_pair.begin(), ret_vec_pair.end(), compareIndices);

        for (int i = 0; i < ret_vec_pair.size(); i++) {
            ret_vec.push_back(ret_vec_pair[i].second);
        }

        return ret_vec;
    }

    // Comparator function for sorting values
    static bool compareValues(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }

    // Comparator function for sorting indices
    static bool compareIndices(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
};
```
```
