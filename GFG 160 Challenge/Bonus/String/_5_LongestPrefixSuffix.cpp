// Given a string of characters s, find the length of the longest prefix which is also a suffix.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestPrefixSuffix(string &s) {
        int n = s.length();
        vector<int> lps(n);
        int len = 0;
        lps[0] = 0;
    
        int i = 1;
        while (i < s.length()) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps[n - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.longestPrefixSuffix(str) << "\n";
        cout << "~"
             << "\n";
    }

    return 0;
}