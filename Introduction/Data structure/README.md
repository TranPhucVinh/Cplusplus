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
