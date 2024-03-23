# Count total duplicate numbers inside an array
```cpp
#include <iostream>
#include <map> 

int array[] = {5, 7, 9, 9, 10, 11, 13, 13, 13, 16, 1, 5, -2, -2,-4, 0};

int main()
{
	std::map<int, int> Map;

    for (int i = 0; i < sizeof(array)/sizeof(int); i++){
        Map[array[i]] += 1;
    }

    std::map<int, int>::iterator itr;

    for (itr=Map.begin(); itr != Map.end(); itr++) 
    { 
        std::cout << itr->first << " appears " << itr->second << " times" << std::endl;
    } 

    return 0;
}
```
# Create a map from value, key of an existed map
With his vector:
```cpp
vector<int> nums = {2,3,1,3,2};
```
We have a map to represent total occurences:
```cpp
Map[1] = 1;
Map[2] = 2;
Map[3] = 2;
```
Then we map value and key of **Map** to key, value of **ordered_map**:
```cpp
ordered_map[1] = {1}
ordered_map[2] = {2, 3}
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
# Find common characters in words
# Convert a valid Roman numerals to integer
[roman_numerals_and_integer_conversion.cpp](roman_numerals_and_integer_conversion.cpp)
