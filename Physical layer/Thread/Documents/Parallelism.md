# std::promise and std::future

* **std::promise** is a template class that allows you to store a value or an exception that will be made available in the future.
* **std::future** is a template class that represents a value that may not be available yet but will be available at some point in the future.

In this example, t2 will wait for 5 seconds to get the "future" value ``futureObj`` from ``t1``:
```cpp
#include <iostream>
#include <thread>
#include <future>

int main() {
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();

    std::thread t1([&promiseObj]() {
        // Simulating some computation
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        promiseObj.set_value(42);
    });

    std::thread t2([&futureObj]() {
        // This line could potentially block forever
        int result = futureObj.get();
        std::cout << "Result from future: " << result << std::endl;
    });

    t1.join();
    t2.join();

    return 0;
}
```
# std::async()
``std::async`` is a C++11 feature that allows you to asynchronously execute a function and get a ``std::future`` object representing the result of the function. 

It's useful for parallel execution of functions.

```cpp
#include <iostream>
#include <future>
#include <unistd.h>

int add(int a, int b) {
    sleep(5);
    return a + b;
}

int main() {
    std::future<int> future_result = std::async(std::launch::async, add, 5, 3);

    std::cout << "Do some other work while the add function is executing...\n";

    // Program will be blocked at future_result.get() to wait for add() to complete
    std::cout << "Result: " << future_result.get() << std::endl;
    return 0;
}
```
**Result**

```
Do some other work while the add function is executing...
// Wait for 5 seconds in add()
Result: 8
```