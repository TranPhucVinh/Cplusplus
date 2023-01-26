# [Thread](Thread.md)

* [Create a simple thread]()
* [Thread function with argument]()

# Memory

# System time

Use library ``ctime``

## Get current time with time()

```cpp
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    time_t currentTime;
    time(&currentTime);//Get current time and save to currentTime
	cout << ctime(&currentTime);//Thu Aug 26 23:42:02 2021
    return(0);
}
```

## Get day, month and year with localtime()

```cpp
time_t currentTime;
time(&currentTime); //Get current time and save to currentTime
struct tm *time_value = localtime(&currentTime);
cout << "Day " << time_value->tm_mday << " month: " << time_value->tm_mon << "year: " << time_value->tm_year;
```


# File IO
