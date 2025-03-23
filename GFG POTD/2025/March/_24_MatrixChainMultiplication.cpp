// Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
    
        for (int len = 2; len < n; len++){
            for (int i = 0; i < n - len; i++){
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++){
                    int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
    
        return dp[0][n - 1];
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); 
    while (t--) {
        int n;
        vector<int> a;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }
}