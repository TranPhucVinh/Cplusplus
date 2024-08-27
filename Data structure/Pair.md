A pair can be inserted into a map, unordered map as its member.
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
# Use pair to find the index of the original member of a vector after sorting
Algorithm:
* Create a vector of pair to store the indices of all member of the original vector before sorting, where in each pair, first is the indeces, and second is the member.
* Sort this vector based on the second values of each pair, i.e the vector's member. Use std::sort() with the 3rd argment is a function 
* After sorting, the vector of indices will reflect the order of the sorted data, and you can use it to reference the original positions.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator function for sorting indices
bool compareIndices(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    vector<int> data = {30, 10, 50, 20, 40};

    // Create a vector of pairs, where each pair is (index, value)
    vector<pair<int, int>> indexValuePairs;
    for (int i = 0; i < data.size(); ++i) {
        indexValuePairs.push_back(make_pair(i, data[i]));
    }

    // Sort the vector of pairs based on the values
    sort(indexValuePairs.begin(), indexValuePairs.end(), compareIndices);

    // Output the sorted data and original indices
    cout << "Sorted data with original indices:\n";

    for (int i = 0; i < indexValuePairs.size(); i++) {
        cout << "Data: " << indexValuePairs[i].second << " at original index: " << indexValuePairs[i].first << "\n";
    }

    return 0;
}
```
