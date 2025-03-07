// Given a string s, return the length of the longest palindromic subsequence. A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements. A palindromic sequence is a sequence that reads the same forward and backward.






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestPalinSubseq(string &s) {
        int n = s.size();
        vector<int> curr(n), prev(n);
        for (int i = n - 1; i >= 0; --i){
            curr[i] = 1;
            for (int j = i + 1; j < n; ++j){
                if (s[i] == s[j]) curr[j] = prev[j - 1] + 2;
                else curr[j] = max(prev[j], curr[j - 1]);
            }
    
            prev = curr;
        }
    
        return curr[n-1];
    }
};

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~" << "\n";
    }
}