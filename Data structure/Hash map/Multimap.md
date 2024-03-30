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