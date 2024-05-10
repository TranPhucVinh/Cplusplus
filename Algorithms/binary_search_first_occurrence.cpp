#include <iostream>
#include <vector>

using namespace std;

bool found = false;// Mark if the target is found

/*
    Return:
    * Index of the first occurence of the target
    * the index when binary search recursive function search_number()
      ends when target is inside [lower bound, upper bound]
*/
int find_first_occurrence(int target, vector<int> vec_num, int start_index, int end_index) {
    int middle = 0;
    if (start_index == end_index) {
        if (target == vec_num[start_index]) found = true;
        else found = false;

        return start_index;
    }

    middle = (start_index + end_index)/2;// Middle index
    if (target == vec_num[middle]) {
        return find_first_occurrence(target, vec_num, start_index, middle);
    }
    else if (target > vec_num[middle]){
        return find_first_occurrence(target, vec_num, middle+1, end_index);
    } else {
        return find_first_occurrence(target, vec_num, start_index, middle);
    }
    
    return 0;
}

#define TARGET 39

int main(){
    vector<int> num_vec = {1, 2, 2, 2, 5, 5, 5, 12, 34};
    int _first = find_first_occurrence(TARGET, num_vec, 0, num_vec.size()-1);
    if (found) cout << "Fist ocurrence of " << TARGET << " is " << _first << endl;
    else {
        // When ret is 0, TARGET is < lower bound of the array
        if (!_first) {
            cout << TARGET << " isn't found as it is less than the lower bound\n";
            return 0;
        }
        if ( (_first == num_vec.size() - 1) && (TARGET > num_vec[num_vec.size() - 1]) )  {
            cout << TARGET << " isn't found as it is bigger than the upper bound\n";
            return 0;
        }

        cout << TARGET << " isn't found while it's inside range [lower bound, upper bound]\n";
    }
}
