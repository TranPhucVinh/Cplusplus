# Access map member at the specific index by using std::advance()
**Map doesn't have any API to directly access its element by the specified index/position**, use **std::advance()** instead:
```cpp
int map_index = 1;
std::map<int, std::string>::iterator el = Map.begin();

std::advance(el, map_index);
std::cout << map_index << ", key: " << el->first << "; value: " << el->second << std::endl;
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
