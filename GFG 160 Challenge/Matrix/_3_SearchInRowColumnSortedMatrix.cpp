// Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x, the task is to find whether element x is present in the matrix.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // Linear Search
        // int n = mat.size();
        // int m = mat[0].size();
        
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < m;j++){
        //         if(mat[i][j] == x) return true;
        //     }
        // }
        // return false;
        
        // Binary Search
        int n = mat.size(), m = mat[0].size();
        int i = 0, j = m - 1;
      
        while(i < n && j >= 0) {
            if(x > mat[i][j]) i++;
            else if(x < mat[i][j]) j--;
            else return true;
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an) cout << "true" << endl;
        else cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}