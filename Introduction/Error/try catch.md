
``try catch`` will try execute the block of code inside ``try`` until it reaches

```c
#include <iostream>

using namespace std;

int main(){
    try {
        int value = 1;
        if (value >= 10) {
            cout << "Valid number";
        } else {
            throw value;//Throw value as the exeception number
        }

        //Those block of code can't be reached as throw is reached above
        if (value == 2) cout << "value = 2";
        else cout << "value != 2";
    }
    catch (int number_var) {
        cout << "Invalid number: " << number_var << "\n";
    }
}
```

```c
Invalid number: 1
```

If ``throw runtime_error``, the program will then stop and block of code in ``catch`` will not be executed:

```c
try {
      int value = 1;
      if (value >= 10) {
          cout << "Valid number";
      } else {
          throw runtime_error("Invalid number");
      }
      //Other block of code are like the program above
  }
```
**Result**

```
terminate called after throwing an instance of 'std::runtime_error'
  what():  Invalid number
```