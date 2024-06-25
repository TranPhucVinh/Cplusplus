# Double a number represented as a vector

**Example**: input = [1,8,9], output: [3,7,8] (i.e 189 * 2 = 378); input: head = [9,9,9], output: [1,9,9,8] (i.e 999 * 2 = 1998)

**Approach**: A naive approach is to convert the input into a number, double it then convert it into the vector output. However, this will result in overflow when the input vector represents a number bigger than long long. The best approach for this issue is using a carried number.
```cpp
vector<int> vec = {9, 9, 9};
vector<int> ret_vec;

int carried = 0;
for (int i = vec.size() - 1; i >= 0; i--) {
    int number = vec[i] * 2 + carried;
    ret_vec.push_back(number % 10);
    carried = number/10;
}
if (carried > 0) ret_vec.push_back(carried);

reverse(ret_vec.begin(), ret_vec.end());
```
