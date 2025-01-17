// Given a matrix mat[][]. Find the size of the largest sub-matrix whose sum is equal to zero. The size of a matrix is the product of rows and columns. A sub-matrix is a matrix obtained from the given matrix by deletion of several (possibly, zero or all) rows/columns from the beginning and several (possibly, zero or all) rows/columns from the end.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxZeroSum(vector<int>& arr){
        int sum = 0,length = 0;
        unordered_map<int,int>mp;
        int n = arr.size();
        
        for(int i = 0;i < n;i++){
            sum += arr[i];
            if(sum == 0) length = (i + 1);
            if(mp.find(sum) != mp.end()) length = max(length, (i - mp[sum]));
            else mp[sum] = i;
        }
        return length;
    }
    
    int zeroSumSubmat(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int area = 0;
        
        for(int i = 0;i < row;i++){
            vector<int>temp(col,0);
            for(int j = i;j < row;j++){
                for(int k = 0;k < col;k++) temp[k] += mat[j][k];
                int len = maxZeroSum(temp);
                area = max(area, (j - i + 1) * len);
            }
        }
        return area;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.zeroSumSubmat(mat);
        cout << ans << endl;

        cout << "~" << "\n";
    }
}