### Example 1

Split a string with the following sequence ``host`` and ``port``.

```c
#include <iostream>
#include <cstring>
#include <cstdio>
#include <unistd.h>

#define STDOUT_FD 1

using namespace std;

char host[19];
char port[3];

void struct_data_parsing(char *data);

int main() {
	char displayed[] = "demo.thingsboard.io443";
	struct_data_parsing(displayed);
} 

void struct_data_parsing(char *data){
    struct struct_data {
        char host[19];
        char port[3];
    } data_frame;

    memcpy(&data_frame, data, 22);
    strcpy(host, data_frame.host);
    strcpy(port, data_frame.port);

    write(STDOUT_FD, host, sizeof(host));
    printf("\n");
    write(STDOUT_FD, port, sizeof(port));
    printf("\n");
}
```

**Notice**: 

Using ``cout`` like this will cause error:

```c
cout << host << endl;//demo.thingsboard.io443
cout << port << endl;//443
```