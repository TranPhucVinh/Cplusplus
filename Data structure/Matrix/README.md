# Main diagonal and antidiagonal 
* The main diagonal of a matrix is the list of entries a[i][j] such that i = j
* The antidiagonal, which only **available inside a square matrix** of size N, is the list of entries a[i][j] such that i+j = N-1 where 0 <= i, j < N
# Transpose of a matrix
Transposing a matrix involves swapping the element at position (i,j) with the element at position (j,i). This converts rows into columns. 

$$
A(3, 2) = 
\begin{bmatrix}
a & b & c \\
d & e & f \\
\end{bmatrix}
$$

$$
A^T = A(2, 3) =
\begin{bmatrix}
a & d \\
b & e \\
c & f \\
\end{bmatrix}
$$

```cpp
#include <iostream>
#include <vector>
 
using namespace std;

#define m 2
#define n 3

int main() {
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}}; // A(m,n) = A(2,3)
    vector<vector<int>> A_T(n, vector<int>(m)); // A_T(n,m) = A_T(3,2)

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            A_T[j][i] = A[i][j];
        }
    }

    for (int i = 0; i < n; i++){        
        for (int j = 0; j < m; j++){
            cout << A_T[i][j] << " ";
        }
        cout << endl;
    }
}
```
# Saddle point

In a square matrix with n * n size, a saddle point is an element of the matrix such that it is the minimum element in its row and the maximum in its column. 

**The algorithm to find the saddle point**

Traverse all rows one by one and do the following for every row ``i``:  

1. Find the minimum element of the current row and store the column index of the minimum element.
2. Check if the row minimum element is also maximum in its column. We use the stored column index here.
3. If yes, then saddle point else continues till the end of the matrix.

Program [saddle_point.c](saddle_point.c)