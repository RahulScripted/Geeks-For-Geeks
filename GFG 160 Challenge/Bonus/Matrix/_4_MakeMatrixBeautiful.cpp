// A beautiful matrix is a matrix in which the sum of elements in each row and column is equal. Given a square matrix mat[][]. Find the minimum number of operation(s) that are required to make the matrix beautiful. In one operation you can increment the value of any one cell by 1.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMinOperation(vector<vector<int> >& mat) {
        int n = mat.size();
        vector<int>row,col;
        for(int i=0;i<n;i++){
            int sum =0;
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
            }
            row.push_back(sum);
        }
        
        for(int i=0;i<n;i++){
            int sum =0;
            for(int j=0;j<n;j++){
                sum+=mat[j][i];
            }
            col.push_back(sum);
        }
        sort(row.begin(),row.end());
        sort(col.begin(),col.end());
      
        int ans =0;
        if(row[n-1]>=col[n-1]){
            int val = row[n-1];
            for(int i=0;i<n-1;i++){
                ans+=(val-row[i]);
            }
        }
        
        else{
            int val = col[n-1];
              for(int i=0;i<n-1;i++){
                ans+=(val-col[i]);
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        Solution ob;
        cout << ob.findMinOperation(matrix) << endl;

        cout << "~" << "\n";
    }
    return 0;
}