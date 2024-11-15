# Count total duplicate elements inside a vector
```cpp
#include <iostream>
#include <map> 
#include <vector> 

using namespace std;

vector<int> vec{5, 7, 9, 9, 10, 11, 13, 13, 13, 16, 1, 5, -2, -2,-4, 0};

int main()
{ 
	std::map<int, int> Map;

    for (int i = 0; i < vec.size(); i++){
        Map[vec[i]] += 1;
    }

    std::map<int, int>::iterator itr;

    for (itr = Map.begin(); itr != Map.end(); itr++) 
    { 
        std::cout << itr->first << " appears " << itr->second << " times" << std::endl;
    } 

    return 0;
}
```
# List all indices of a number inside a vector
```cpp
std::map<int, vector<int>> Map;

for (int i = 0; i < vec.size(); i++){
    Map[vec[i]].push_back(i);
}

std::map<int, vector<int>>::iterator itr;

for (itr = Map.begin(); itr != Map.end(); itr++){ 
    std::cout << "Map[" << itr->first << "] = {";
    for (int i = 0; i < itr->second.size(); ++i) {
        std::cout << itr->second[i];
        if (i < itr->second.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}
```
# Create a new map with key, value from value, key of an existed map
With this vector:
```cpp
vector<int> nums = {2,3,1,3,2};
```
We have a map to represent total occurences:
```cpp
Map[1] = 1; Map[2] = 2; Map[3] = 2;
```
Then we map value and key of **Map** to key, value of **ordered_map**:
```cpp
ordered_map[1] = {1}; ordered_map[2] = {2, 3}
```
```cpp
vector<int> nums = {2,3,1,3,2};

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

for (order_map_itr = ordered_map.begin(); order_map_itr != ordered_map.end(); order_map_itr++){
    std::cout << "ordered_map[" << order_map_itr->first << "] = {";
    for (size_t i = 0; i < order_map_itr->second.size(); ++i) {
        std::cout << order_map_itr->second[i];
        if (i < order_map_itr->second.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}
```
# Sort an array by increasing frequency
Sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

* Input: nums = [1,1,2,2,2,3]
* Output: [3,1,1,2,2,2]

* Input: nums = [2,3,1,3,2]
* Output: [1,3,3,2,2]

* Input: nums = [-1,1,-6,4,5,-6,1,4,1]
* Output: [5,-1,4,4,-6,-6,1,1,1]

**Program**: [sort_array_by_increasing_freq.cpp](https://github.com/TranPhucVinh/Cplusplus/blob/master/Data%20structure/Hash%20map/src/sort_array_by_increasing_freq.cpp)
# Sort characters by decreasing frequency
* Input s = "tree", Output: "eert"
* Input: s = "cccaaa", Output: "aaaccc"

**Program**: This problem is similar to [Sort an array by increasing frequency](#sort-an-array-by-increasing-frequency): [sort_char_by_decreasing_freq.cpp](https://github.com/TranPhucVinh/Cplusplus/blob/master/Data%20structure/Hash%20map/src/sort_char_by_decreasing_freq.cpp)
# Top k frequent elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

* Input: nums = [1,1,1,2,2,3], k = 2 -> Output: [1,2]
* Input: nums = [1], k = 1 -> Output: [1]

**Algorithm**: Count how many time a number appear in nums by hashmap ``Map``. Then create ``ordered_map``, a new map with key, value from value, key of ``Map``. As this ``ordered_map`` is an ordered map, the last members will store the most frequence elements.

**Program**:  [top_k_freq_elements.cpp](../src/top_k_freq_elements.cpp)
# Intersection of two arrays

* nums1 = [1,2,2,1], nums2 = [2,2]
* Result: [2]

* nums1 = [4,9,5], nums2 = [9,4,9,8,4]
* Result: [9,4]

**Program**: [intersection_of_two_arrays.cpp](https://github.com/TranPhucVinh/Cplusplus/blob/master/Data%20structure/Hash%20map/src/intersection_of_two_arrays.cpp)
# Intersection of multiple arrays
* Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
* Output: [3,4]

* Input: nums = [[1,2,3],[4,5,6]]
* Output: []

* Input: nums = [[1,2],[1,2],[1,2],[1,2],[1,2],[1,2],[1,2],[1,2],[1,2],[1,2],[1]]
* * Output: [1]

**Program**: [intersection_of_multiple_arrays.cpp](https://github.com/TranPhucVinh/Cplusplus/blob/master/Data%20structure/Hash%20map/src/intersection_of_multiple_arrays.cpp)
# Split the array into distinct element (Leetcode 3046)

You have to split the array into two parts nums1 and nums2 such that both nums1 and nums2 contain distinct elements. Return true if it is possible to split the array, and false otherwise.

* Input: nums = [1,1,2,2,3,4]
* Output: true
* Explanation: One of the possible ways to split nums is nums1 = [1,2,3] and nums2 = [1,2,4].

* Input: nums = [1,1,1,1]
* Output: false
* Explanation: The only possible way to split nums is nums1 = [1,1] and nums2 = [1,1]. Both nums1 and nums2 do not contain distinct elements

Algorithm: 
* First, if there is any number appear > 2 times, return false
* Thne find all member that appear 1 time, if that total number % 2 = 0, return true. We don't case about the member that appear 2 times, as they can always be divided

```cpp
bool isPossibleToSplit(vector<int>& nums) {
    std::map<int, int> Map;

    for (int i = 0; i < nums.size(); i++){
        Map[nums[i]] += 1;
    }

    vector<int> one_mem;

    std::map<int, int>::iterator itr;

    for (itr=Map.begin(); itr != Map.end(); itr++) 
    { 
        if (itr->second > 2) return false;
        if (itr->second == 1) one_mem.push_back(itr->first);
        // Don't care for member that appear exactly 2, as they can always be divided
    } 

    if (!(one_mem.size() % 2)) return true;
    else return false;

    return false;
}
```
