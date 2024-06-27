# Create a vector
```cpp
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    vector<int> vec{10, 20, 30};
   
    //Get vector size by std::vector::size
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
}
```
**Note**: Vector members are stored on heap memory, so it doesn't lose its value [when being returned from a function](Vector%20and%20function.md#function-returns-vector).

**vector.data()** returns a pointer to the underlying array used to store the elements of that vector.

# Set up vector member 
Use **push_back()**
```cpp
vector<int> vec;
 
vec.push_back(12);
vec.push_back(34);
```
Use **emplace_back()**
```cpp
vec.emplace_back(12);
vec.emplace_back(34);
```
Init by index:

```cpp
vector<int> vec(2);// Must have size initialization before setting them by index
   
vec[0] = 12;
vec[1] = 34;
```
Initialize vector and init all value
```cpp
#define VEC_SZ      2
#define INIT_VAL    0

vector<int> vec(VEC_SZ, INIT_VAL);
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
# reserve()

**reserve()** is used to allocate memory for a specified number of elements in advance, but it does not change the actual size of the vector. The size of the vector remains zero until elements are actually added using **push_back()** or other similar methods.

# const char pointer as member of a vector

```cpp
vector<const char*> vec;

//For first time setup value for vector, push_back() must be used
vec.push_back("12");
vec.push_back("34");

for (int i = 0; i < vec.size(); i++){
    cout << vec[i] << endl;
}
```

# Class object as member of a vector

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
# vector mustn't be used inside a union

Vector mustn't be used inside a union due to certain restrictions on union members. The reason is that ``std::vector`` manages dynamic memory internally, and unions in C/C++ have constraints on the types of data they can contain
# Concatenate vectors
## Merged 2D vector into a 1D one
Beside the naive approach to loop through every member of the 2D vector to push_back() them to the 1d vector, **insert()** function can be used. **reserve()** must be used to pre-allocated the size of the 1d vector from the 2D ones:
```cpp
std::vector<int> merged_vector;
merged_vector.reserve(matrix.size() * matrix[0].size());

for (int i = 0; i < matrix.size(); i++) {
    merged_vector.insert(merged_vector.end(), matrix[i].begin(), matrix[i].end());
}
```
## Concatenate 2 vectors
std::vector container doesn't support direct addition with operator+, as the operator overloading, for concatenating two vectors. To concatenate two vectors, you need to manually append the elements of one vector to the other:
```cpp
vector<int> vec_1 {1, 2, 3};
vector<int> vec_2 {4, 5, 6};

vector<int> vec_3;

// Calling reserve() isn't mandatory
vec_3.reserve(vec_1.size() + vec_2.size()); // Reserve space for the combined size to avoid multiple reallocations

vec_3.insert(vec_3.end(), vec_1.begin(), vec_1.end()); // Insert elements from the first vector

vec_3.insert(vec_3.end(), vec_2.begin(), vec_2.end()); // Insert elements from the second vector
```
