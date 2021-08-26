## API

* ``fstream`` for two operations ``input`` and ``output`` at the same time.
* ``ifstream`` for input operation
* ``ofstream`` for output operation

You can't open input and output file stream (with ``ifstream`` and ``ofstream``) at the same time, this will not give compilation error but result in failure when run

```c
//Wrong, must not do it
ifstream fileStreamIn("text.txt");
ofstream fileStreamOut("text.txt");
```

So it means that you can't edit the content of a single line belong to an opening a file to read.
