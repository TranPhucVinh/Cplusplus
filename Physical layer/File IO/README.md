# [iostream](iostream)

* [std::cout](iostream.md#stdcout)
* [std::cin](iostream.md#stdcin): [Get entered int value from std::cin](), [Get multiple entered int value from std::cin then print out](iostream.md#get-multiple-entered-int-value-from-stdcin-then-print-out), [Get multiple entered int value from std::cin then print out](iostream.md#get-multiple-entered-int-value-from-stdcin-then-print-out), [Get an entered string from std::cin](), [std::cin in foor loop](iostream.md#stdcin-in-foor-loop)
* getline()
* setw()

# [fstream](fstream)

Library [fstream](fstream) includes:

* **ofstream**: output file streams
* **ifstream**: input file streams
* **fstream**: file stream with two operation input and output

# filesystem

``filesystem`` is supported since C++17

``std::filesystem::path``: represents a path

``std::filesystem::directory_iterator``: an iterator to the contents of the directory

## List out all files inside a directory

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
# cstdio

**cstdio** is corresponded to **stdio.h** in GCC. All functions of ``stdio.h`` existed in ``cstdio``.

## Using printf()

```cpp
#include <iostream>
#include <cstdio> //For printf

using namespace std;

int main(){
	cout << "Hello, World!" << endl;
    printf("Hello, World!\n");
}
```

## Get the entered string with fgets()

```cpp
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
# File I/O with unistd

As [read()](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/File%20IO/System%20call/README.md#fundamental-concepts) of unistd.h requires ``char *buffer`` buffer, to read a file's content into ``std::string``:
```cpp
#include <iostream>
#include <unistd.h> // read()
#include <fcntl.h>  // open()

#define FILE_NAME   "README.md"
int fd;

int main(){
    char buffer[10];

    fd = open(FILE_NAME, O_RDONLY);
    if (fd > 0){
        read(fd, buffer, 10);
        std::string str(buffer);
        std::cout << str << std::endl;
    } else std::cout << "Unable to open " << FILE_NAME << std::endl;
}
```
