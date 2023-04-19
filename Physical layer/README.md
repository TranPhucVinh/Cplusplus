# [Memory](Memory)

* Dynamic memory allocation
* Pointer
* Smart pointer: Unique pointer, shared pointer
* rvalue and lvalue

# Time with ctime

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
# Time with chrono
chrono value is only available in [thread](). 

Can't use chrono time value like seconds for ``sleep()`` function:

```cpp
//Must not do this. This gives compilation error
sleep(std::chrono::seconds(1));
```

# Communicating with the environment

## getenv()

Get the environment variable value (setup by [export](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Bash%20script/Variable/Environment%20variable.md#export-command) command:

``getenv()`` is available since C++11.

```c
std::cout << std::getenv("env_var");
```
Setup environment variable ``env_var``: ``export env_var="Hello, World !"``

# File IO
