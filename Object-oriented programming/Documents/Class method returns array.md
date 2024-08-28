In this example, a local array is returned from a class method:
```cpp
class classTest{
public:
    classTest() {
        int _array[] = {1, 2, 3};
        copy(begin(_array), end(_array), begin(array));
    }
        
    int *returnArray() {
        return array;
    }
private:
    int array[3];
};

int main() {
    classTest obj;
	int *array_pointer;
	array_pointer = obj.returnArray();
    for (int i = 0; i < 3; i++) cout << array_pointer[i] << " "; // 1 2 3
    cout << endl;
}
```
As local array ``_array`` is still inside the memory region of class object ``obj``, after returning ``returnArray`` to ``array_pointer`` pointer (where ``array_pointer`` pointer and class object ``obj`` are still inside the same scope), ``array_pointer`` can stil access ``_array``.

The memory region scoping issue will happen when there are 2 separated class objects:
```cpp
#include <iostream>

using namespace std;

class classTest {
public:
    classTest() {
        int _array[] = {1, 2, 3};
        std::copy(std::begin(_array), std::end(_array), std::begin(array));
    }
        
    int *changeArray() {
        for (int i = 0; i < 3; i++) array[i] += 1;
        return array;
    }

    int *ret_obj_array() {
        classTest obj_1;
        int *array_pointer;
        array_pointer = obj_1.changeArray();
        for (int i = 0; i < 3; i++) cout << array[i] << " ";
        cout << endl;
        return array_pointer;
    }

private:
    int array[3];
};

int main() {
    classTest obj;
    int *ret_array = obj.ret_obj_array();

    for (int i = 0; i < 3; i++) cout << ret_array[i] << " "; // 2 -243867792 32766
    cout << endl;
}
```
In order to use a sub class object (i.e ``obj_1``) like this, use dynamic memory allocation and don't use the destructor function (as it will free the dynamic memory allocated array):
```cpp
#include <iostream>

using namespace std;

class classTest{
public:
    classTest() {
        int _array[] = {1, 2, 3};
        array = new int[3];
        copy(_array, _array + 3, array);
    }

    // If having destructor function like this, *array will be freed 
    // after finishing function ret_obj_array()
    
    // ~classTest() {
    //    delete[] array;
    // }

    int *ret_obj_array() {
        classTest _obj;
        int *array_pointer;
        array_pointer = _obj.changeArray();
        for (int i = 0; i < 3; i++) cout << array[i] << " ";
        cout << endl;
        return array_pointer;
    }

private:
    int *array;

    int *changeArray() {
        for (int i = 0; i < 3; i++) array[i] += 1;
        return array;
    }
};

int main() {
    classTest obj;
    int *ret_array = obj.ret_obj_array();

    for (int i = 0; i < 3; i++) cout << ret_array[i] << " "; // 2 -243867792 32766
    cout << endl;
}
```
Or using unique pointer
```cpp
#include <iostream>
#include <memory>

using namespace std;

class classTest{
public:
    classTest() {        
        int _array[] = {1, 2, 3};
        array = make_unique<int[]>(3);

        copy(_array, _array + 3, array.get());
    }
    
    ~classTest() {}

    unique_ptr<int[]> ret_obj_array() {
        classTest _obj;
        unique_ptr<int[]> array_pointer;
        array_pointer = _obj.changeArray();
        for (int i = 0; i < 3; i++) cout << array[i] << " ";
        cout << endl;
        return array_pointer;
    }

private:
    unique_ptr<int[]> array;

    unique_ptr<int[]> changeArray() {
        for (int i = 0; i < 3; i++) array[i] += 1;
        return move(array);
    }
};

int main() {
    classTest obj;
    unique_ptr<int[]> ret_array = obj.ret_obj_array();

    for (int i = 0; i < 3; i++) cout << ret_array[i] << " "; // 2 3 4
    cout << endl;
}
```
