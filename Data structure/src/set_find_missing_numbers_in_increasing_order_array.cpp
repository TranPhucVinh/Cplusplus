#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool found = false;// Mark if the target is found

/*
    Return:
    * Index of the found target
    * the index when binary search recursive function search_number()
      ends when target is inside [lower bound, upper bound]
*/
int search_number(int target, vector<int> &array, int start_index, int end_index) {
    int middle = 0;
    if (start_index == end_index) {
        if (target == array[start_index]){
            found = true;
            return start_index;
        } else {
            found = false;
            return start_index;
        }
    }
    middle = (start_index + end_index)/2;// Middle index
    if (target == array[middle]) {
        found = true;
        return middle;
    }
    else if (target > array[middle]){
        return search_number(target, array, middle+1, end_index);
    } else {
        return search_number(target, array, start_index, middle);
    }
    
    return 0;
}

int main(void) {
	vector<int> vect = {2,3,4,7,11};
    std::set<int> missing_numbers;
    for (int i = 0; i < vect.size(); i++){
        if (vect[i] > i){
            // As the finding process result in duplicate number, use set to avoid that
            for (int j = i+1; j < vect[i]; j++){
                search_number(j, vect, 0, vect.size()-1);
                if (!found) missing_numbers.insert(j);
            }
        }
    }

    for (std::set<int>::iterator it = missing_numbers.begin(); it != missing_numbers.end(); it++) {
        std::cout << *it << " ";
    }
    
	return 0;
}
