# [iostream](iostream)

* [std::cout](iostream.md#stdcout)
* [std::cin](iostream.md#stdcin): [Get entered int value from std::cin](), [Get multiple entered int value from std::cin then print out](iostream.md#get-multiple-entered-int-value-from-stdcin-then-print-out), [Get multiple entered int value from std::cin then print out](iostream.md#get-multiple-entered-int-value-from-stdcin-then-print-out), [Get an entered string from std::cin](), [std::cin in foor loop](iostream.md#stdcin-in-foor-loop)
* getline()
* setw()

# fstream

Library [fstream](fstream)

* ``ofstream``: output file streams
* ``ifstream``: input file streams
* ``fstream``: file stream with two operation input and output

# cstdio

``cstdio`` is corresponded to ``stdio.h``. All functions of ``stdio.h`` existed in ``cstdio``.

**Example 1**: Using ``printf()``

```c
#include <iostream>
#include <cstdio> //For printf

using namespace std;

main(){
	cout << "Hello, World!" << endl;
    printf("Hello, World!\n");
}
```

**Example 2**: Get the entered string with ``fgets()``

```c
#include <iostream>
#include <cstdio>

using namespace std;

char displayString[100];

int main(){
	cout << "Enter string: ";
	fgets(displayString, 20, stdin);
	cout << displayString;
}
```

# filesystem

``filesystem`` is supported since C++17

``std::filesystem::path``: represents a path

``std::filesystem::directory_iterator``: an iterator to the contents of the directory

**Example**: List out all files inside directory ``dir_name``

```cpp
#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    std::string path = "dir_name";
    for (const auto &entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}
```
