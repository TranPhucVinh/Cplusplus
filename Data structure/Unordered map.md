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
