// Given a string s, of lowercase english alphabets, find the length of the longest proper prefix which is also a suffix.



#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.size();
        vector<int> lps(n, 0);  
    
        int len = 0;  
        int i = 1;
    
        while (i < n) {
            if (s[i] == s[len]) {
                lps[i] = ++len;
                i++;
            } 
            else{
                if (len != 0) len = lps[len - 1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps[n - 1];
    }
};

int main() {
    string s;
    cin >> s;
    
    Solution obj;
    cout << obj.getLPSLength(s) << endl;
    
    return 0;
}