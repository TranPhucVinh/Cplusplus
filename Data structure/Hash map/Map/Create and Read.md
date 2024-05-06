# Create a map and read all of its objects

Use [for_each loop](../Introduction/Function/README.md#for-each-loop) to access each element of the map, with **el.first** gets the key and **el.second** gets the value; then get map size by **map::size()**: 
```cpp
#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> Map;
    Map[1] = "Map, key 1";
    Map[123] = "Map, key 123";
    Map[456] = "Map, key 456";

    std::cout << Map[123] << std::endl;// Map, key 123

    int map_index = 0;
    std::map<int, std::string>::iterator el = Map.begin();

    while (el != Map.end()) {
        std::cout << map_index << ", key: " << el->first << "; value: " << el->second << std::endl;
        map_index += 1;
        el++;
    }
    
	std::cout << "Map size: " << Map.size() << std::endl;// Map size: 3
    return 0;
}
```
```
Map, key 123
0, key: 1; value: Map, key 1
1, key: 123; value: Map, key 123
2, key: 456; value: Map, key 456
```
**Note**: Map key must be unique. If using the same key, it will be overwritten by the latest one
```cpp
Map[1] = "Map, key 1";
Map[1] = "Map, key 1234";
Map[123] = "Map, key 123";
Map[456] = "Map, key 456";
```
**Result**
```
0, key: 1; value: Map, key 1234
1, key: 123; value: Map, key 123
2, key: 456; value: Map, key 456
Map size: 3
```
# Define map like a dictionary
```cpp
std::map<int, std::string> Map = {
	{1, "Map, key 1"},
	{123, "Map, key 123"},
	{456, "Map, key 456"}
};
```
## Traverse by auto keyword
```cpp
for (auto &el: Map){
	std::cout << map_index << ", key: " << el.first << "; value: " << el.second << std::endl;
}
```
**Map doesn't have any any API to directly access its element by the specified index/position**, use **std::advance()** instead:
```cpp
int map_index = 1;
std::map<int, std::string>::iterator el = Map.begin();

std::advance(el, map_index);
std::cout << map_index << ", key: " << el->first << "; value: " << el->second << std::endl;
```
## std::map is an ordered list of member arranged by the ascending order of their keys
```cpp
std::map<int, std::string> Map;
Map[456] = "Map, key 456";
Map[1] = "Map, key 1";
Map[123] = "Map, key 123";
// Map will then arrange them to {Map[1], Map[123], Map[456]}

std::map<int, std::string>::iterator el = Map.begin();// key: 1; value: Map, key 1
std::cout << "key: " << el->first << "; value: " << el->second << std::endl;

int map_index = 0;
while (el != Map.end()) {
	std::cout << map_index << ", key: " << el->first << "; value: " << el->second << std::endl;
	map_index += 1;
	el++;
}
/*
	Result of thw while() loop:
	0, key: 1; value: Map, key 1
	1, key: 123; value: Map, key 123
	2, key: 456; value: Map, key 456
*/
```
The above implementation is similar to **std::map<int, std::string, std::less<>>** (**std::less<>** for arranging the map from the lowest key value (``int``) to the greatest one):
```cpp
std::map<int, std::string, std::less<>> Map;
```
To arrange the map from the greatest key value (int) to the lowest one, as **descending order**, use **std::greater<>**
```cpp
std::map<int, std::string, std::greater<>> Map;
Map[456] = "Map, key 456";
Map[1] = "Map, key 1";
Map[123] = "Map, key 123";

std::map<int, std::string>::iterator el = Map.begin();

int map_index = 0;
while (el != Map.end()) {
	std::cout << map_index << ", key: " << el->first << "; value: " << el->second << std::endl;
	map_index += 1;
	el++;
}
```
**Result**
```
0, key: 456; value: Map, key 456
1, key: 123; value: Map, key 123
2, key: 1; value: Map, key 1
```
# Function pointer as map value
**A single function**
```cpp
void display_1(){
    cout << "display 1\n";
}
int main()
{
    std::map<int, void (*)()> Function_Pointer_Map;
    Function_Pointer_Map[1] = display_1;

    // Use () to call the function 
    Function_Pointer_Map[1]();// display_1() is called
    return 0;
}
```
**Function as a class method**
```cpp
class Map_Func_Ptr{
    private:
        std::map<int, void (Map_Func_Ptr::*)()> EXECUTE_FUNC;
        void display_1(){
            cout << "display 1\n";
        }
    public:
        Map_Func_Ptr(){
            EXECUTE_FUNC[1] = &Map_Func_Ptr::display_1;
            (this->*EXECUTE_FUNC[1])();
        }
};

int main()
{
    Map_Func_Ptr map_func_ptr;
    return 0;
}
```
# Vector of map

Create a vector to store maps to count total duplicate numbers inside a 2D vector:
```cpp
vector<vector<int>> nums = {{3, 3, 1, 1, 2, 4, 2},{1, 2, 2, 3, 3},{3, 4, 4, 5, 6}};
vector<map<int, int>> Map_Vector;

for (int i = 0; i < nums.size(); i++){
map<int, int> _Map;
for (int j = 0; j < nums[i].size(); j++){
    _Map[nums[i][j]] += 1;
}
Map_Vector.push_back(_Map);
}

int map_index = 0;
for (int i = 0; i < Map_Vector.size(); i++){
std::map<int, int>::iterator el = Map_Vector[i].begin();
cout << "map: " << map_index << endl;

while (el != Map_Vector[i].end()) {
    std::cout << "key: " << el->first << "; value: " << el->second << std::endl;
    el++;
}
map_index += 1;
}
```
