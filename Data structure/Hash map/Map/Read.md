# Access map member at the specific index by using std::advance()
**Map doesn't have any API to directly access its element by the specified index/position**, use **std::advance()** instead:
```cpp
int map_index = 1;
std::map<int, std::string>::iterator el = Map.begin();

std::advance(el, map_index);
std::cout << map_index << ", key: " << el->first << "; value: " << el->second << std::endl;
```
# std::map::find()
``std::map::find()`` is used to check if a key existed in a map. Return:
* The iteration at that key if existed
* An iterator to the end of the map (``Map.end()``), which is one past the last element.

```cpp
int main() {
    map<int, string> Map;
    Map[1] = "Map, key 1";
    Map[123] = "Map, key 123";
    Map[456] = "Map, key 456";

    map<int, string>::iterator el = Map.find(123);

    if (el != Map.end()) {
        cout << "key: " << el->first << "; value: " << el->second << endl;
    } else cout << "Key doesn't existed\n";

    return 0;
}
```
# std::map::count()
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
