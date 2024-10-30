# Read all vector's members by raw pointer

```cpp
vector<int> numbers{2,7,11,15};
int *ptr;
for (int i = 0; i < numbers.size(); i++){
    ptr = &numbers[i];
    cout << *ptr << endl;
}
```
## Read all vector's members by iterator
```cpp
vector<int> vec{1, 2, 3, 4, 5};

vector<int>::iterator iter = vec.begin();

while (iter != vec.end()){
    cout << vec[iter - vec.begin()] << " ";
    iter += 1;
}
```
**Start reading at the specified index**:
```cpp
int index = 2;
vector<int>::iterator iter = vec.begin() + index;
```
# Get the last member by back()
```cpp
vector<int> vec{10, 20, 30};   
cout << vec.back() << endl;
```
## vector.data()
**vector.data()** returns a pointer to the underlying array used to store the elements of that vector.
```cpp
vector<uint8_t> vec1{48, 49};
vector<uint8_t> vec2{'h', 'a'};

write(STDOUT_FILENO, vec1.data(), vec1.size());
write(STDOUT_FILENO, vec2.data(), vec2.size());

cout << vec1.data() << " " << vec2.data() << endl;
```
## Find a member by std::find() (from algorithm library)
```cpp
vector<int> vec{10, 20, 30};

vector<int>::iterator element;

element = std::find(vec.begin(), vec.end(), 30);

if (element != vec.end()) {
    std::cout << "Element 30 found at " << element - vec.begin() << " position \n";// Element 30 found at 2 position
}  else std::cout << "Element not found.\n";
```
Find all occurrence of a member:
```cpp
vector<int> vec{10, 20, 30, 1, 2, 4, 30, 4, 5, 30, 12, 30, 30, 4, 30};

vector<int>::iterator iter;
iter = find(vec.begin(), vec.end(), 30); 

cout << "Element 30 occurred at indices: "; 
while (iter != vec.end()) { // Check if the element was found 
    cout << iter - vec.begin() << " "; 
    iter = std::find(iter + 1, vec.end(), 30); 
} 
```
# Comparison operator overloading

Overloading ``==``, ``>``, ``<``, ``>=`` and ``<=`` are defined for all CPP containers: vector, set,... where:

* ``==``: Checks if the contents of lhs and rhs are equal, that is, whether lhs.size() == rhs.size() and each element in lhs has equivalent element in rhs at the same position.
* ``>``, ``<``, ``>=`` and ``<=``: Both start checking at the first element then move to the next one if the first passed the condition.

```cpp
vector<int> vec1{1, 2, 3}, vec2{1, 2, 4}; // vec1 < vec2
```
```cpp
vector<int> vec1{3}, vec2{1, 2, 4};   // vec1 > vec2 as vec1[0] > vec2[0]
```
```cpp
vector<int> vec1{3, 0, 0}, vec2{1, 2, 4}; // vec1 > vec2
```
# Find the max number of a 2D array, along with its index
<details>

```cpp
vector<int> max_vec;
vector<vector<int>> max_vec_index;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    // Find the max element inside each array mat[i] then put them into max_vec
    // Find the corresponding index of that max element then put them into max_vec_index
    for (int i = 0; i < mat.size(); i++){
        vector<int>::iterator max_iter = std::max_element(mat[i].begin(), mat[i].end());
        int max_index = std::distance(mat[i].begin(), max_iter);

        vector<int> vec_index = {i, max_index};

        max_vec.push_back(*max_iter);
        max_vec_index.push_back(vec_index);
    }

    // Find the max element of max_vec and return its index
    vector<int>::iterator max_iter = std::max_element(max_vec.begin(), max_vec.end());
    int max_index = std::distance(max_vec.begin(), max_iter);

    return max_vec_index[max_index];
}
```
</details>

# Find the difference of two arrays

* nums1 = [1,2,3], nums2 = [2,4,6]
* Result: [[1,3],[4,6]]

* nums1 = [1,2,3,3], nums2 = [1,1,2,2]
* Result: [[3],[]]

* nums1 = [-68,-80,-19,-94,82,21,-43], nums2 = [-63]
* Result: [[-19,82,-68,21,-43,-94,-80],[-63]]

* nums1 = [26,48,-78,-25,42,-8,94,-68,26], nums2 = [61,-17]
* Result: [[-78,-68,-25,-8,26,42,48,94],[-17,61]]

* nums1 = [-1000], nums2 = [-1000]; nums1 = [2, 2], nums2 = [2]
* Result: [[], []]

<details>

```cpp
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    // Assign to nums1 to its clone to avoid wrong removing inside the for() loop
    vector<int> nums1_clone = nums1;

    int nums1_sz = nums1.size();
    int nums2_sz = nums2.size();

    std::vector<int>::iterator nums1_new_end, nums2_new_end;
    int nums1_new_sz = 0, nums2_new_sz = 0;

    bool first_find = false;

    for (int i = 0; i < nums1_clone.size(); i++){
        // Must assign nums1_clone[i] to a temp variable
        // Mustn't pass it directly to std::remove() as this will effect nums1_clone
        int number = nums1_clone[i];

        vector<int>::iterator nums2_iter = find(nums2.begin(), nums2.end(), number);
        if (nums2_iter != nums2.end()){
            if (!first_find) {
                nums1_new_end = nums1.end();
                nums2_new_end = nums2.end();
                first_find = true;
            }
            nums1_new_end = std::remove(nums1.begin(), nums1_new_end, number);
            nums2_new_end = std::remove(nums2.begin(), nums2_new_end, number);

            nums1_new_sz = std::distance(nums1.begin(), nums1_new_end);
            nums2_new_sz = std::distance(nums2.begin(), nums2_new_end);
        }                
    }

    vector<int> nums1_new, nums2_new;

    // Check !nums1_new_sz && !nums2_new_sz && !first_find for cases:
    // nums1 = [-1000]; nums2 = [-1000]
    // nums1 = [2, 2]; nums2 = [2] => Return {{}, {}}

    if (!nums1_new_sz && !nums2_new_sz && !first_find){
        nums1_new_sz = nums1.size();
        nums2_new_sz = nums2.size();
    }

    for (int i = 0; i < nums1_new_sz; i++){
        nums1_new.push_back(nums1[i]);
    }

    for (int i = 0; i < nums2_new_sz; i++){
        nums2_new.push_back(nums2[i]);
    }

    // Sort to use unique
    sort(nums1_new.begin(), nums1_new.end());
    sort(nums2_new.begin(), nums2_new.end());

    nums1_new_end = unique(nums1_new.begin(), nums1_new.end());
    int new_sz = std::distance(nums1_new.begin(), nums1_new_end);
    nums1_new.resize(new_sz);

    nums2_new_end = unique(nums2_new.begin(), nums2_new.end());
    new_sz = std::distance(nums2_new.begin(), nums2_new_end);
    nums2_new.resize(new_sz);

    return {nums1_new, nums2_new};
}
```
</details>