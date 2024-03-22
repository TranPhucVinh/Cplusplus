A pair can be inserted into a map, unordered map as its member
# Create
```cpp
#include <iostream>

int main()
{
    std::pair<int, int> pair_obj(1, 2);
    std::cout <<  pair_obj.first << " " << pair_obj.second;// 1 2

    return 0;
}
```
Use **std::make_pair()**:
```cpp
std::pair<int, int> pair_obj = std::make_pair(3, 4);
```
# Pair as function argument
```cpp
#include <iostream>

void change_pair(std::pair<int, int> &pair_obj){
    pair_obj.first += 1;
    pair_obj.second += 1;
}

int main()
{
    std::pair<int, int> pair_obj(1, 2);
    std::cout <<  pair_obj.first << " " << pair_obj.second << std::endl;// 1 2
    change_pair(pair_obj);
    std::cout <<  pair_obj.first << " " << pair_obj.second << std::endl;// 1 2

    return 0;
}
```