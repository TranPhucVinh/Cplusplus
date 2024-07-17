# API
**queue** is a built-in STL CPP library:
```cpp
value_type std::queue::front(); // View the first value of the queue
```

```cpp
value_type std::queue::back(); // View the last value of the queue
```

```cpp
void std::queue::push();
void std::queue::pop();
```
# Create and read the queue

```cpp
#include <iostream>
#include <queue>

using namespace std;

/*
    The only way to view all value of a queue is to pop out all of its value
*/
void display_queue(queue<int> _queue) {
	while (!_queue.empty()) {
		cout << _queue.front() << " ";
		_queue.pop();
	}
	cout << '\n';
}

int main() {
	queue<int> _queue;
	_queue.push(1);
	_queue.push(2);
	_queue.push(3);

    cout << "Queue size: " << _queue.size() << endl;
    cout << "The last value of queue: " << _queue.back() << endl;
	display_queue(_queue);

	cout << "Size: " << _queue.size() << endl;// Size: 3
	return 0;
}
```
