// Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. Find whether the number x is present in the matrix or not.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // Approach 1
        // int n = mat.size();
        // int m = mat[0].size();
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < m;j++){
        //         if(mat[i][j] == x) return true;
        //     }
        // }
        // return false;
        
        // Approach 2
        int n = mat.size();
        int m = mat[0].size();
    
        // Apply binary search:
        int low = 0, high = n * m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m, col = mid % m;
            if (mat[row][col] == x) return true;
            else if (mat[row][col] < x) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x)) cout << "true\n";
        else cout << "false\n";

        cout << "~" << "\n";
    }
    return 0;
}