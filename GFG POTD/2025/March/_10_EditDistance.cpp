// Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2. The possible operations are permitted:

// 1. Insert a character at any position of the string.
// 2. Remove any character from the string.
// 3. Replace any character from the string with any other character.






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int editDistance(string& s1, string& s2) {
        int m = s1.size();
        int n = s2.size();
        int prev; 
        vector<int> curr(n + 1, 0); 
    
        for (int j = 0; j <= n; j++) curr[j] = j;
      
        for (int i = 1; i <= m; i++) {
            prev = curr[0]; 
            curr[0] = i;
            for (int j = 1; j <= n; j++) {
                int temp = curr[j];
                if (s1[i - 1] == s2[j - 1]) curr[j] = prev;
                else curr[j] = 1 + min({curr[j - 1], prev, curr[j]});
                prev = temp;
            }
        }
        
        return curr[n];
    }
};

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
}