// You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int> ans;
 
        int n = mat.size(); 
        int m = mat[0].size(); 
          
        int top = 0, left = 0, bottom = n - 1, right = m - 1;
        
        while (top <= bottom && left <= right) {
              
            for (int i = left; i <= right; i++) ans.push_back(mat[top][i]);
            top++;
            
            for (int i = top; i <= bottom; i++) ans.push_back(mat[i][right]);
            right--;
            
            if (top <= bottom) {
              for (int i = right; i >= left; i--) ans.push_back(mat[bottom][i]);
              bottom--;
            }
        
            if (left <= right) {
              for (int i = bottom; i >= top; i--) ans.push_back(mat[i][left]);
              left++;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i) cout << result[i] << " ";
        cout << endl;

        cout << "~" << "\n";
    }
    return 0;
}