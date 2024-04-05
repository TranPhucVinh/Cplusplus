# Create a vector
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
