# Vector as function argument
Function read all vector member, as its argument:
```cpp
void readVector(vector<int> vec){
	for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
}

int main()
{
    vector<int> vec{10, 20, 30};
    readVector(vec);
}
```
Change value of a vector by a function: Use [lvalue](https://github.com/TranPhucVinh/Cplusplus/blob/master/Physical%20layer/Memory/lvalue.md)
```cpp
void updateVector(vector<int> &vec){
	for (int i = 0; i < vec.size(); i++){
       vec[i] += 100;
    }
}

int main()
{
    vector<int> vec{10, 20, 30};
    updateVector(vec);
    // vec{110, 120, 130}
}
```
