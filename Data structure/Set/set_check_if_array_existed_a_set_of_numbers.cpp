#include <iostream>
#include <vector>
#include <set>

bool checkSet(const std::vector<int>& arr, const std::set<int>& allowedSet) {
    std::set<int> uniqueNumbers;

    for (int num : arr) {
        if (allowedSet.find(num) == allowedSet.end()) {
            return false; // If any element is not found in the set, return false
        }
    }

    return uniqueNumbers.size() <= allowedSet.size();
}

int main() {
    std::set<int> allowedSet = {1, 2, 3};

    std::vector<int> arr1  {1, 2, 3};
    std::cout << std::boolalpha << checkSet(arr1, allowedSet) << std::endl; // Output: true

    std::vector<int> arr2 = {1, 2, 2, 3};
    std::cout << std::boolalpha << checkSet(arr2, allowedSet) << std::endl; // Output: true

    std::vector<int> arr3 = {1, 2, 2, 4};
    std::cout << std::boolalpha << checkSet(arr3, allowedSet) << std::endl; // Output: false

    std::vector<int> arr4 = {1, 2};
    std::cout << std::boolalpha << checkSet(arr4, allowedSet) << std::endl; // Output: true

    std::vector<int> arr5 = {3};
    std::cout << std::boolalpha << checkSet(arr5, allowedSet) << std::endl; // Output: true

    return 0;
}