// Given a string in Roman number format (s), your task is to convert it to an integer. Various symbols and their values are given below.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int romanToDecimal(string &s) {
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int ans = 0;
        int n = s.length();
        for(int i = 0;i < n;i++){
            if(mp[s[i]] < mp[s[i + 1]]) ans -= mp[s[i]];
            else ans += mp[s[i]];
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;

        cout << "~" << "\n";
    }
}