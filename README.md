# Cplusplus

C++ document

### Compile cpp file with GCC

``gcc test.cpp``: This will give **linking error** because of missing linker

```cpp
gcc test.cpp -lstdc++
```

This will normally compile a ``cpp`` file with ``.c`` syntax:

**Example**: ``test.cpp``

```cpp
#include <stdio.h>

main(){
	printf("hello");
}
```