# throw value

``try catch`` will try execute the block of code inside ``try``. ``catch`` will be executed if there is [throw](throw.md) inside ``try`` and the line of code of ``throw`` is reached.

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
        printf("Program keeps running as throw error is caught\n");
}
```

```c
Invalid number: 1
Program keeps running as throw error is caught
```

As the throw error (``throw value``) is caught (by ``catch``), the program won't stop so the line of code after ``catch(int number_var)`` keeps executing (``printf("Program keeps running as throw error is caught\n")``);

# throw std::runtime_error

If ``throw std::runtime_error``, the program will then stop and block of code in ``catch`` will not be executed:

```cpp
try {
      int value = 1;
      if (value >= 10) {
          cout << "Valid number";
      } else {
          throw std::runtime_error("Invalid number throw runtime_error");
      }
      //Other block of code are like the program above
  }
//Other block of code are like the program above
```
**Result**

```
terminate called after throwing an instance of 'std::runtime_error'
  what():  Invalid number throw runtime_error
```
