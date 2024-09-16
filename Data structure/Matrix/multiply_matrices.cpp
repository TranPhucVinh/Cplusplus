#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a = {
    {0x2, 0x3, 0x1, 0x1},
    {0x1, 0x2, 0x3, 0x1},
    {0x1, 0x1, 0x2, 0x3},
    {0x3, 0x1, 0x1, 0x2},
};

vector<vector<int>> b = {
    {0xd4, 0xe0, 0xb8, 0x1e},
    {0xbf, 0xb4, 0x41, 0x27},
    {0x5d, 0x52, 0x11, 0x98},
    {0x30, 0xae, 0xf1, 0xe5},
};

vector<vector<int>> multiply_matrices(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> multiply(4, vector<int>(4));

    for (int col = 0; col < 4; col++) {
        for (int _row = 0; _row < 4; _row++) {
            multiply[_row][col] = 0;
            for (int _col = 0; _col < 4; _col++) {
                multiply[_row][col] += a[_row][_col] * b[_col][col];
            }
        }
    }
    return multiply;
}

int main() {    
    vector<vector<int>> multiply = multiply_matrices(a, b);

    for (int _row = 0; _row < 4; _row++) {
        for (int _col = 0; _col < 4; _col++) {
            // cout << hex << "0x" << static_cast<int>(multiply[_row][_col]) << " "; 
            cout << multiply[_row][_col] << " "; 
        }
        cout << endl;
    } 
}
