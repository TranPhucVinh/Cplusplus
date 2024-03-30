# Fundamental concepts
A multimap allows a key to have multiple value

```cpp
#include <iostream>
#include <map>

using namespace std;
int main()
{
    std::multimap<int, std::string> Multimap;
    Multimap.insert(std::make_pair(1, "key 1: Value 1"));
    Multimap.insert(std::make_pair(1, "key 1: Value 2"));
    Multimap.insert(std::make_pair(123, "key 123"));
    Multimap.insert(std::make_pair(456, "key 456"));

    // multimap doesn't allow accessing by operator[], e.g Multimap[123] is wrong

    std::multimap<int, std::string>::iterator el = Multimap.begin();

    while (el != Multimap.end()) {
        std::cout << "key: " << el->first << "; value: " << el->second << std::endl;
        el++;
    }
    
    std::cout << "\nKey '1' includes: " << std::endl;
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> range = Multimap.equal_range(1);

    for (multimap<int, string>::iterator iter = range.first; iter != range.second; iter++) {
        std::cout << "Key: " << iter->first << ", value: " << iter->second << std::endl;
    }

    return 0;
}
```
# Create a multimap with key, value from value, key of an existed map
With this vector:
```cpp
vector<int> nums = {2,3,1,3,2};
```
We have a map to represent total occurences:
```cpp
Map[1] = 1; Map[2] = 2; Map[3] = 2;
```
Then we map value and key of **Map** to key, value of **multi_map**:
```cpp
multi_map[1] = {1}; multi_map[2] = {2, 3}
```
```cpp
vector<int> nums = {2,3,1,3,2};

std::map<int, int> Map;
for (int i = 0; i < nums.size(); i++){
    Map[nums[i]] += 1;
}

std::multimap<int, int> Multimap;

std::map<int, int>::iterator itr;
std::multimap<int, int>::iterator multimap_itr;

for (itr = Map.begin(); itr != Map.end(); itr++) 
{ 
    int key = itr->first;
    int value = itr->second;

    multimap_itr = Multimap.find(value);
    Multimap.insert(make_pair(value, key));
}

multimap<int, int>::iterator el = Multimap.begin();

while (el != Multimap.end()) {
    std::cout << "key: " << el->first << "; value: " << el->second << std::endl;
    el++;
}
```
# equal_range()
```cpp
std::pair<iterator, iterator> equal_range(const key_type& x);
```