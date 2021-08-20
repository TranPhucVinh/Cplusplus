Print out a hex value

```c
#include <iostream>

using namespace std;

int a = 11;
int main() {
    cout << hex << 10 << endl;//a
    cout << hex << a << endl;//b
}
```
Or define:

```cpp
cout << std::hex << 10 << endl;
```

If define ``int hex = 100``, then there will be error: ``"hex" is ambiguous C/C++(266)``.