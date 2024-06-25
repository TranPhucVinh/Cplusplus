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

# Saddle point

In a square matrix with n * n size, a saddle point is an element of the matrix such that it is the minimum element in its row and the maximum in its column. 

**The algorithm to find the saddle point**

Traverse all rows one by one and do the following for every row ``i``:  

1. Find the minimum element of the current row and store the column index of the minimum element.
2. Check if the row minimum element is also maximum in its column. We use the stored column index here.
3. If yes, then saddle point else continues till the end of the matrix.

Program [saddle_point.c](saddle_point.c)