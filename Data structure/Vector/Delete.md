# Remove the whole vector by clear()
Remove the whole vector then assign new values to that newly deleted vector:

```cpp
vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
cout << endl;

vec1.clear();
vec1 = vec2;

for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
```
# Remove the last member of the vector by pop_back()
```cpp
void std::vector<int>::pop_back()
```
Removes last element of the vector then shrinks the vector's size by one.
# Delete vector member by erase()

```cpp
vector_name.erase(position);  // delete at specific position
vector_name.erase(starting_position, ending_position);    // delete in range
```

**std::erase()** removes the first encountered value of a sequence, based on the iterator. **std::erase() will automatically resize the array after erasing the member**:

```cpp
#define VALUE 20
std::vector<int> vec{10,20,30,30,20,10,10,20};

std::vector<int>::iterator vec_iter = std::find(vec.begin(), vec.end(), VALUE);

if (vec_iter != vec.end()) vec.erase(vec_iter);// 10 30 30 20 10 10 20 (the first vector member has value 20 is removed)
```
To remove at a specific index:
```cpp
int index = 1;
std::vector<int> vec{10,20,30,30,20,10,10,20};
vec.erase(vec.begin() + index);
```
**Delete in range**: Removes the elements in the range from ``index_start`` to ``index_end`` as inclusive of the ``index_start`` and exclusive of the ``index_end``.
```cpp
vec.erase(vec.begin() + index_start, vec.begin() + index_end);
```
```cpp
std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7};

int index_start = 2, index_end = 4;
vec.erase(vec.begin() + index_start, vec.begin() + index_end);// 0 1 4 5 6 7
```
# Remove all occurrences of a specific number
```cpp
std::vector<int> vec = {1, 2, 3, 4, 3, 5, 3, 6};
int numberToRemove = 3;

// Remove all occurrences of the specified number
vec.erase(std::remove(vec.begin(), vec.end(), numberToRemove), vec.end());
```
``std::remove`` rearranges the vector to move all elements that are equal to ``numberToRemove`` to the end and returns an iterator to the new end of the vector.
