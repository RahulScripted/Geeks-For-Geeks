// Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    
        return dp[m][n];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        cout << ob.lcs(s1, s2) << endl;
        cout << "~\n";
    }
    return 0;
}