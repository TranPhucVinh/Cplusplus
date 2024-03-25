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
