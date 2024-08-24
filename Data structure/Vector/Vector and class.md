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
# Vector as class method
```cpp
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class classTest{
public:
    vector<uint8_t> cipher_suites;
};

int main(){
	classTest obj;
    obj.cipher_suites.push_back(12);
    obj.cipher_suites.push_back(34);

    for (int i = 0; i < obj.cipher_suites.size(); i++) {
        cout << (int)obj.cipher_suites[i] << " ";
    }
}
```
We must cast to int to display as ``uint8_t`` ist mostly treated as a char type, which can lead to unexpected behavior when printing.

**Must not access vector as class method:**
```cpp
// MUST NOT ACCESS vector as class method like this
int main(){
	classTest obj;
    obj.cipher_suites.push_back(12);
    obj.cipher_suites.push_back(34);

    uint8_t *ptr = reinterpret_cast<uint8_t*>(&obj);  // MUST NOT DO THIS

    for (int i = 0; i < 2; i++) {
        printf("0x%02X ", ptr[i]);
    }
}
```
**reinterpret_cast** provides a way to access raw memory, but **std::vector** manages its own memory dynamically. Directly casting and accessing this memory will not give you meaningful information about the vector's content. The internal representation of a std::vector includes pointers, size, and capacity information. Casting this to a uint8_t* won't correctly reflect the actual data stored in the vector.
