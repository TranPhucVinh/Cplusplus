# Find all max elements of all subarrays formed by a sliding window
Given an array with a sliding window with size of k which will form a subarray for each slide. Find all max elements of all those subarray.

**Test case 1**
int arr[] = {3, 4, 6, 3, 4}, k = 2. The subarrays of each slide are {3,4}, {4,6}, {6,3} and {3,4}. The max will then be {4, 6, 6, 4}.

**Test case 2**
int arr[] = {3, 4, 5, 8, 1, 4, 10}, k = 4. The subarrays of each slide are {3,4,5,8}, {4,5,8,1}, {5,8,1,4}. The max will then be {8, 8, 8, 10}.

**Test case 3**
int arr[] = {3, 4, 5, 8, 1, 4, 2, 3, 2, 1, 2, 10}, k = 4. The subarrays of each slide are {3,4,5,8}, {4,5,8,1}, {5,8,1,4}, {8, 1, 4, 2}, {1, 4, 2, 3}, {4, 2, 3, 2}, {2, 3, 2, 1}, {3, 2, 1, 2}, {2, 1, 2, 10}. The max will then be {8, 8, 8, 10}.

## Algorithm

A naive approach to form the subarray for every slide of the sliding window 4 then start finding the max value. This will result in ${O(n^2)}$.

The best approach for this is to use deque, which requires only one time of traversal and has ${O(n)}$.

For the deque algorithm, we will form a deque with the size of k which stores the max element at front. For every iteration, if the current value is bigger than the back, we will popout that back and keep comparing the new back with this current value, until all deque back which are smaller than this current value are popped out. Finally, that current value is push_back to the deque.

Illustrate with test case 3

Init, i = 0: deque dq = {1}

i=1: dq = {4} as dq.back() = 3 which is <= 4, so 3 is popped out and 4 is push_back()

i=2: dq = {5} (same explanation to i=1)

i=3: dq = {8}

With i = 3, the traversal for the window of size k from 0 to 3 has finished. dq.front() = 8 now is the max value

i=4: dq = {8, 1} as 1 < 8 so push_back(1) to dq

With i = 4, the traversal for the window of size k from 1 to 4 has finished. dq.front() = 8 now is the max value

i=5: dq = {8, 4} as 4 > 1 so pop_back() to remove 1 then push_back(4) to dq

With i = 5, the traversal for the window of size k from 2 to 6 has finished. dq.front() = 8 now is the max value

i=6: dq = {8, 4, 2} (same explanation to i = 4)

With i = 6, the traversal for the window of size k from 3 to 7 has finished. **This i=6 with the position of dq.front() = 8 (i = 3) has already formed a full sliding window withe the size of k = 4**. So for the index iteration (i = 7), the front dq.front() must be removed before checking for the next iteration.

i=7: dq.front() is removed, dq = {8, 4, 3}

Same algorithm is applied for the left iterations.

We can also see that with i >= k - 1, we can start outputing the max element of every sliding window.
## Program

```cpp
void printKMax(int arr[], int arr_sz, int k){
    std::deque<int> dq;

    for (int i = 0; i < arr_sz; i++) {
            if (dq.empty()) dq.push_back(i);
            if (dq.front() <= i - k) dq.pop_front();
            
            while(!dq.empty() && arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if (i >= k - 1) {
                cout << arr[dq.front()] << " ";
            }         
    }
    cout << endl;
}
```
