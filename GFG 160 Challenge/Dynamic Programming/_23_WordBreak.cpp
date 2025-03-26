// You are given a string s and a list dictionary[] of words. Your task is to determine whether the string s can be formed by concatenating one or more words from the dictionary[].





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.size();
        vector<bool> dp(n + 1, 0);
        dp[0] = 1;
    
        for (int i = 1; i <= n; i++){
            for (string &w : dictionary){
                int start = i - w.size();
                if (start >= 0 && dp[start] && s.substr(start, w.size()) == w){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) cout << "true\n";
        else cout << "false\n";
        cout << "~" << "\n";
    }
}