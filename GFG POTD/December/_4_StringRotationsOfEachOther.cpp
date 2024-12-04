// You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // Built-in method
        // s1 += s1;
        // return s1.find(s2) != string::npos;
        
        string str = s1+s1;
        int j=0;
        if(s1.size()!=s2.size()) return false;
        for(int i=0; i<str.size();i++){
           if(s2[j] == str[i]) j++;
        }
        return j==s2.size();
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) cout << "true" << endl;
        else cout << "false" << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}