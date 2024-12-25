// Given a 2D square matrix mat[][] of size n x n, turn it by 180 degrees without using extra space.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                swap(mat[i][j], mat[n - i - 1][n - j - 1]);
            }
        }
      
        if (n % 2 != 0) {
            int mid = n / 2;
            for (int j = 0; j < n/2; j++) swap(mat[mid][j], mat[mid][n - j - 1]);
        }
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution ob;
        ob.rotateMatrix(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~" << "\n";
    }
    return 0;
}