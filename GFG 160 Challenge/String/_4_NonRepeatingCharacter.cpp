// Given a string s consisting of lowercase Latin Letters. Return the first non-repeating character in s. If there is no non-repeating character, return '$'.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        vector<int> vis(26, -1);
        for (int i = 0; i < s.length(); i++) {
            if (vis[s[i] - 'a'] == -1) vis[s[i] - 'a'] = i;
            else vis[s[i] - 'a'] = -2;
        }
    
        int idx = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (vis[i] >= 0) idx = min(idx, vis[i]);
        }
        
        return (idx == INT_MAX ? '$' : s[idx]);
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$') cout << ans << endl;
        else cout << "-1" << endl;
    }
}