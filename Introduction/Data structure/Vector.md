Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted.

# Create

Create a vector

```cpp
#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    vector<int> vec;
 
    //For first time setup value for vector, push_back() must be used
    vec.push_back(12);
    vec.push_back(34);

    for (int i = 0; i < 2; i++){
        cout << vec[i] << endl;
    }
}
```

**Example**: Class object as member of a vector

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

    for (int i = 0; i < 2; i++){
        cout << vec[i].int_val << endl;
        cout << vec[i].str_val << endl;
    }
    return 0;
}
```

# Update

Update the value of vector:

```cpp
vector<int> vec;

//For first time setup value for vector, push_back() must be used
vec.push_back(12);
vec.push_back(34);

for (int i = 0; i < 2; i++){
    cout << vec[i] << endl;
}

vec[0] = 1;
vec[1] = 1;

for (int i = 0; i < 2; i++){
    cout << vec[i] << endl;
}
```

``vec[index]`` is used for updating value after this index member is created by ``push_back()``. Must not use ``vec[index]``  to setup/create vector value at ``index``. 
