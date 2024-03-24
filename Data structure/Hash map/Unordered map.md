# Define an unordered map
```cpp
std::unordered_map<int, std::string> Map;
Map[456] = "Map, key 456";
Map[1] = "Map, key 1";
Map[123] = "Map, key 123";
// Map will then arrange them to {Map[1], Map[123], Map[456]}

std::unordered_map<int, std::string>::iterator el = Map.begin();// key: 1; value: Map, key 1
std::cout << "key: " << el->first << "; value: " << el->second << std::endl;

int map_index = 0;
while (el != Map.end()) {
    std::cout << map_index << ", key: " << el->first << "; value: " << el->second << std::endl;
    map_index += 1;
    el++;
}
```
**Result**
```
key: 123; value: Map, key 123
0, key: 123; value: Map, key 123
1, key: 1; value: Map, key 1
2, key: 456; value: Map, key 456
```
```
# Use unordered map to count total duplicate numbers inside an array

```cpp
#include <iostream>
#include <unordered_map> 

int array[] = {5, 7, 9, 9, 10, 11, 13, 13, 13, 16};

int main()
{
	std::unordered_map<int, int> umap;

    for (int i = 0; i < sizeof(array)/sizeof(int); i++){
        umap[array[i]] += 1;
    }

    std::unordered_map<int, int>::iterator itr;

    for (itr=umap.begin(); itr!=umap.end(); itr++) 
    { 
        std::cout << itr->first << " appears " << itr->second << " times" << std::endl;
    } 

    return 0;
}
```
# Count total duplicate chars inside a string
```cpp
std::string str = "1210";
std::unordered_map<char, int> umap;

for (int i = 0; i < str.size(); i++){
    umap[str[i]] += 1;
}

std::unordered_map<char, int>::iterator itr;

for (itr = umap.begin(); itr != umap.end(); itr++) 
{ 
    std::cout << itr->first << " appears " << itr->second << " times" << std::endl;
}
```
