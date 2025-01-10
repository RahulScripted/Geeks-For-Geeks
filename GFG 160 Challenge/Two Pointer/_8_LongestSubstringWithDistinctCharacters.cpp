// Given a string s, find the length of the longest substring with all distinct characters. 




#include <bits/stdc++.h>
using namespace std;

class Solution {
  int MAX_CHAR = 26;
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        int res = 0;
        vector<int> lastIndex(MAX_CHAR, -1);
        int start = 0;
    
        for (int end = 0; end < n; end++) {
            start = max(start, lastIndex[s[end] - 'a'] + 1);
            res = max(res, end - start + 1);
            lastIndex[s[end] - 'a'] = end;
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~" << "\n";
    }
    return 0;
}