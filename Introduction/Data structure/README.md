# String

String document will include

* [Char array for string](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#char-array-for-string)
* [Char pointer for string](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#char-array-for-string)
* [std::string](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#stdstring)
* [stringstream](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Data%20structure/String#stringstream)

# Queue

Create a queue to store all int variable then read all those value.

```cpp
#include <iostream>
#include <queue>
  
using namespace std;

void readAllObjectFromQueue(queue<int> queueObjectParam){
    while (!queueObjectParam.empty()) {
        cout << '\t' << queueObjectParam.front();
        queueObjectParam.pop();
    }
    cout << '\n';
}

int main()
{
    queue<int> queueIntObject;//Declare a queue that accepts int value
    queueIntObject.push(1);
    queueIntObject.push(2);
    queueIntObject.push(3);

    readAllObjectFromQueue(queueIntObject);
    return 0;
}
```
