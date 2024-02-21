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
