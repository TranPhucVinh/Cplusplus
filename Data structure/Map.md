Map is a data structure that supports creating an object includes a key and its value

```cpp
std::map<key, value> Map;
```
Map is supported since [C++11](https://github.com/TranPhucVinh/Cplusplus#c11).

A similar data structure to map is a [vector]() including a struct/class object which has key and the value. However, finding a specific member inside that vector require looping all over all member inside that vector while in map, that finding process just simple access the value.

# Create a map and read all of its objects

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

    for (auto &el: Map){
        std::cout << "First element: " << el.first << std::endl;
        std::cout << "Second element: " << el.second << std::endl;
    }
    return 0;
}
```
```
Map, key 123
First element: 1
Second element: Map, key 1
First element: 123
Second element: Map, key 123
First element: 456
Second element: Map, key 456
```
# Insert a new member to the map

```cpp
std::map<int, std::string> Map;
Map[1] = "Map, key 1";
Map[123] = "Map, key 123";
Map[456] = "Map, key 456";

std::cout << "Map before inserting\n";
for (auto &el: Map){
    std::cout << el.first << " " << el.second << std::endl;
}

Map.insert(std::make_pair(789, "Newly insert value"));

std::cout << "Map after inserting\n";
for (auto &el: Map){
    std::cout << el.first << " " << el.second << std::endl;
}
```
# Arrange the map

Arrange the map from the greatest key value (int) to the lowest one

```cpp
std::map<int, std::string, std::greater<>> Map;
Map[1] = "A";
Map[2] = "A";
Map[3] = "A";

for (auto &el: Map){
    std::cout << el.first << " " << el.second << std::endl;
}
```
```
3 A
2 A
1 A
```
Arrange the map from the lowest key value (int) to the greatest one
```cpp
std::map<int, std::string, std::less<>> Map;
Map[1] = "A";
Map[2] = "A";
Map[3] = "A";

for (auto &el: Map){
		std::cout << el.first << " " << el.second << std::endl;
}
```
```
1 A
2 A
3 A
```