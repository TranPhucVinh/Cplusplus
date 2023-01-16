# Base number system

* hex
* dec
* oct

# auto keyword

``auto`` keyword is available since C++11 and allows to automatic deduct of the data type of an expression. ``auto`` in CPP doesn't work like ```auto`` in ``C``.

```
#include <iostream>

using namespace std;

class autoClass{
  public:
    int a;
};

auto a = 10;
auto b = "Hello";
auto c = 1.23;
auto d = new autoClass();//d now is a pointer

int main()
{
  cout << a << endl;//10
  cout << b << endl;//Hello
  cout << c << endl;//1.23
  d->a = 10;
  cout << d->a << endl;//10
}
```

Must not use auto for array like this: ``auto d[3] = {1, 2, 3};//Must not used``
