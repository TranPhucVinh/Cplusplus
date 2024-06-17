Map is a data structure that supports creating an object includes a key and its value

```cpp
std::map<key, value> Map;
```
Map is supported since [C++11](https://github.com/TranPhucVinh/Cplusplus#c11).

A similar data structure to map is a [vector]() including a struct/class object which has key and the value. However, finding a specific member inside that vector require looping over all member inside that vector while **in map, that finding process just simply access the value**.

# [Create and read operations](Create%20and%20Read.md)
# insert() to insert std::pair into map

```cpp
std::map<int, int> Map;

std::pair<int, int> pair_obj(1, 2);
Map.insert(pair_obj);
```
# Check if a key existed in map
* Use std::find()
* Use ``std::map::count``. It will count elements with a specific key. Return: 1 if the container contains an element whose key is equivalent to k, or zero otherwise.

```cpp
std::map<int, std::string> Map;
Map[1] = "Map, key 1";

if (Map.count(1) > 0) {
  std::cout << 1 << " is an element of Map\n";
}
else {
  std::cout << 1 << " is not an element of Map\n";
}
```
# Delete map member

```cpp
std::map::erase(<key>);
```
```cpp
std::map<int, std::string> Map;
Map[1] = "Map, key 1";

Map.erase(1); // Member with key 1 is erased
```
