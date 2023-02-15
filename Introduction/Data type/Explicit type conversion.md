Beside conventional explicit type conversion performed in C, CPP supports explicit type conversion with ``cast``:

* [static_cast](#static_cast)
* Dynamic cast
* Const cast
* Reinterpret cast

# static_cast

* ``static_cast`` does things like implicit conversions between types (such as ``int`` to ``float``, or ``pointer`` to ``void*``), and it can also call explicit conversion functions.
* ``static_cast`` is a compile time cast.

```cpp
float f = 3.5;
int a = f; // this is how you do in C
int b = static_cast<int>(f);
cout << a << endl;
cout << b << endl;
```

There are cases that ``static_cast`` can't be implemented although its corresponding implementation in C performed successfully:

```cpp
char a = 'a';//ASCII value is 97
  
int *q = (int*)&a; 
int *p = static_cast<int*>(&a);//Error at compilation:  invalid static_cast from type 'char*' to type 'int*'

printf("%c", *q);//a
printf("%c", *p);//Error at compilation:  invalid static_cast from type 'char*' to type 'int*'
```
