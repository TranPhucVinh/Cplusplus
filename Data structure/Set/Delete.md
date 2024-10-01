# Remove value from set

```cpp
int numberToRemove = 1;
Set.erase(numberToRemove);
```
# Clear the whole set
```cpp
Set.clear();
```
# Delete members from a vector presented in another vector
Remove the members from ``vec_1`` which presents in ``vec_2``. 
* Test case 1: vec_2 = [1,2,3], vec_1 = [1,2,3,4,5]. Result: ``ret_vec = {4, 5}``
* Test case 2: vec_2 = [1], vec_1 = [1,2,1,2,1,2]. Result: ``ret_vec = [2,2,2]``

A naive approach with looking up then delete will result in big time complexity. The best approach is to use set. Convert ``vec_2`` into a set then start looking for all the member of ``vec_1`` inside that. The member doesn't existed in that set is the expected member.

```cpp
set<int> Set(vec_2.begin(), vec_2.end());
vector<int> ret_vec;

for (int i = 0; i < vec_1.size(); i++) {
    set<int>::iterator it = Set.find(vec_1[i]);
    if (it == Set.end()) {
        ret_vec.push_back(vec_1[i]);
    }
}
```
