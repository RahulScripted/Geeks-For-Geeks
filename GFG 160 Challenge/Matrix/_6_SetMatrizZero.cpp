// You are given a 2D matrix mat[][] of size n×m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0 and do it in constant space complexity.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int rowCount = mat.size(), colCount = mat[0].size();
        bool firstRowHasZero = false, firstColHasZero = false;

        for (int col = 0; col < colCount; ++col) {
            if (mat[0][col] == 0) {
                firstRowHasZero = true;
                break;
            }
        }

        for (int row = 0; row < rowCount; ++row) {
            if (mat[row][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }

        for (int row = 1; row < rowCount; ++row) {
            for (int col = 1; col < colCount; ++col) {
                if (mat[row][col] == 0) {
                    mat[row][0] = 0;
                    mat[0][col] = 0;
                }
            }
        }

        for (int row = 1; row < rowCount; ++row) {
            for (int col = 1; col < colCount; ++col) {
                if (mat[row][0] == 0 || mat[0][col] == 0) mat[row][col] = 0;
            }
        }

        if (firstRowHasZero) {
            for (int col = 0; col < colCount; ++col) mat[0][col] = 0;
        }

        if (firstColHasZero) {
            for (int row = 0; row < rowCount; ++row) mat[row][0] = 0;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x) cout << y << " ";
            cout << endl;
        }

        cout << "~" << "\n";
    }
    return 0;
}