```c
void throw_in_function(){
    float number = 1;
    if (number >= 10) {
        cout << "Valid number\n";
    } else {
        throw (number);
    }

    cout << "Finish throw_in_function()\n";
}

int main(){
    throw_in_function();

    int number = 1;
    if (number >= 10) {
        cout << "Valid number\n";
    } else {
        throw (number);
    }

    cout << "Flow after throw() will not printed out\n";
}
```

**Result**: ``terminate called after throwing an instance of 'float'``

String ``Finish throw_in_function()`` in function ``throw_in_function()`` will not print out, along with the following lines of code after calling ``throw_in_function()`` as the whole program has broken while reaching ``throw``.

If commenting ``throw_in_function()`` and the program will then be:

```c
int main(){
    // throw_in_function();

    int number = 1;
    if (number >= 10) {
        cout << "Valid number\n";
    } else {
        throw (number);
    }

    cout << "Flow after throw() will not printed out\n";
}
```
**Result**:
```
terminate called after throwing an instance of 'int'
```

String ``Flow after throw() will not printed out`` will not print out.

Add customize throw message with ``runtime_error``:

```c
int number = 1;
if (number >= 10) {
    cout << "Valid number\n";
} else {
    throw runtime_error("Invalid number");
}
```
**Result**
```
terminate called after throwing an instance of 'std::runtime_error'
  what():  Invalid number
```