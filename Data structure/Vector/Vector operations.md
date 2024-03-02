# Create

Create a vector
```cpp
#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    vector<int> vec{10, 20, 30};
   
    //Get vector size by std::vector::size
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
}
```
**Note**: Vector members are stored on heap memory, so it doesn't lose its value [when being returned from a function](Vector%20and%20function.md#function-returns-vector).

Member can be set with **push_back()**:
```cpp
vector<int> vec;
 
vec.push_back(12);
vec.push_back(34);
```
Init by index:

```cpp
vector<int> vec(2);// Must have size initialization before setting them by index
   
vec[0] = 12;
vec[1] = 34;
```
For vector defined inside a class, with known size:
```cpp
class ClassTest{
    public:
        ClassTest(){
            vec[0] = 12;
            vec[1] = 34;
        }
    private:
        vector<int> vec = vector<int>(2);
};
```
## const char pointer as member of a vector

```cpp
vector<const char*> vec;

//For first time setup value for vector, push_back() must be used
vec.push_back("12");
vec.push_back("34");

for (int i = 0; i < vec.size(); i++){
    cout << vec[i] << endl;
}
```

## Class object as member of a vector

```cpp
#include <iostream>
#include <vector>
 
using namespace std;

class VecMem{
    public:
        int int_val;
        string str_val;
};

int main()
{
    vector<VecMem> vec;
    VecMem vec_mem_1, vec_mem_2;
    
    vec_mem_1.int_val = 12;
    vec_mem_1.str_val = "Vector member 1";

    vec_mem_2.int_val = 34;
    vec_mem_2.str_val = "Vector member 2";

    //For first time setup value for vector, push_back() must be used
    vec.push_back(vec_mem_1);
    vec.push_back(vec_mem_2);

    for (int i = 0; i < vec.size(); i++){
        cout << vec[i].int_val << endl;
        cout << vec[i].str_val << endl;
    }
    return 0;
}
```
# Read
## Read all vector's members by raw pointer

```cpp
vector<int> numbers{2,7,11,15};
int *ptr;// = &numbers[0];
for (int i = 0; i < numbers.size(); i++){
    ptr = &numbers[i];
    cout << *ptr << endl;
}
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

Update vector at specific by index

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
