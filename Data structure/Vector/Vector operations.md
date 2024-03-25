# Create
* Create a vector
* Set member with push_back()
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
  
   // Check if the element was found 
   cout << "Element 30 occurred at indices: "; 
   while (iter != vec.end()) { 
       cout << iter - vec.begin() << " "; 
       iter = std::find(iter + 1, vec.end(), 30); 
   } 
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

# Delete

## Delete vector member by erase()

**std::erase()** removes the first encountered value of a sequence, based on the iterator. **std::erase() will automatically resize the array after erasing the member**:

```cpp
#define VALUE 20
std::vector<int> vec{10,20,30,30,20,10,10,20};

std::vector<int>::iterator vec_iter = std::find(vec.begin(), vec.end(), VALUE);

if (vec_iter != vec.end()) vec.erase(vec_iter);// 10 30 30 20 10 10 20 (the first vector member has value 20 is removed)
```
