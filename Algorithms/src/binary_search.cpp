#include <iostream>
#include <vector>

using namespace std;

bool found = false;// Mark if the target is found

/*
    Return:
    * Index of the found target
    * the index when binary search recursive function search_number()
      ends when target is inside [lower bound, upper bound]
*/
int search_number(int target, vector<int> num_vec, int start_index, int end_index) {
    int middle = 0;
    if (start_index == end_index) {
        if (target == num_vec[start_index]) found = true;
        else found = false;

        return start_index;
    }
    middle = (start_index + end_index)/2;// Middle index
    if (target == num_vec[middle]) {
        found = true;
        return middle;
    }
    else if (target > num_vec[middle]){
        return search_number(target, num_vec, middle+1, end_index);
    } else {
        return search_number(target, num_vec, start_index, middle);
    }
    
    return 0;
}

#define TARGET 13

int main(){
    vector<int> num_vec = {1, 2, 5, 12, 34};
    int ret = search_number(TARGET, num_vec, 0, num_vec.size()-1);
    if (found) cout << TARGET << " found at " << ret;
    else {
        // When ret is 0, TARGET is < lower bound of the array
        if (!ret) {
            cout << TARGET << " isn't found as it is less than the lower bound\n";
            return 0;
        }
        if ( (ret == num_vec.size() - 1) && (TARGET > num_vec[num_vec.size() - 1]) ) {
            cout << TARGET << " isn't found as it is bigger than the upper bound\n";
            return 0;
        }

        cout << TARGET << " isn't found while it inside range [lower bound, upper bound]\n";
    }
}
