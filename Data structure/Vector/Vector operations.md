# [Create](Create.md)
* Create a vector
* Set member with **push_back()**
* const char pointer as member of a vector
* Class object as member of a vector

# Read
## Read all vector's members by raw pointer

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
## Get the last member by back()
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
## Comparison operator overloading

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
# Update

## Update vector at specific by index

```cpp
vector<int> vec;

//For first time setup value for vector, push_back() must be used
vec.push_back(12);
vec.push_back(34);

for (int i = 0; i < vec.size(); i++){
    cout << vec[i] << endl;
}

vec[0] = 1;
vec[1] = 1;

for (int i = 0; i < vec.size(); i++){
    cout << vec[i] << endl;
}
```
## Update vector size by resize()
## Insert new value to a vector at a specific index, use insert()
```cpp
vector<int> numbers{1, 2, 3};
numbers.insert(numbers.begin(), 4);// 4 1 2 3
numbers.insert(numbers.begin() + 2, 5);// 4 1 5 2 3
```
## Convert vector<char> to std::string
```cpp
std::vector<char> vec_char = {'H', 'e', 'l', 'l', 'o'};
    
std::string str_char = std::string(vec_char.begin(), vec_char.end());

std::cout << str_char << std::endl;// Hello
```
# [Delete](Delete.md)
