### Example 1

Read data from USB port (``/dev/ttyUSB0``, ``/dev/ttyACM0``,...)

```cpp
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <string.h>

using namespace std;

const char filePath[] = "/dev/ttyACM0";
char bufferRead[100];

int fileDescription;
void delaySeconds(long seconds);

int main(){
    fileDescription = open(filePath, O_RDONLY); //READ ONLY
    while(1){
        if(fileDescription < 0) return 1;
        else {
            read(fileDescription, bufferRead, sizeof(bufferRead));
            cout << bufferRead << endl;
        }
        memset(bufferRead, 0, sizeof(bufferRead));
        delaySeconds(1);
    }
    return 0;
}

void delaySeconds(long seconds){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long totalSecond = 0;
	long previousTime = tv.tv_sec;
	while (totalSecond - previousTime < seconds){
		gettimeofday(&tv, NULL);
		totalSecond = tv.tv_sec;
	}
}
```