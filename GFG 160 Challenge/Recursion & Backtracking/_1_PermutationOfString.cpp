// Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void recurPermute(int index, string &s,vector<string> &ans) {
        if (index == s.size()) {
            ans.push_back(s);
            return;
        }
    
        unordered_set<char> used;
        for (int i = index; i < s.size(); i++) {
            if (used.find(s[i]) != used.end()) continue;
            used.insert(s[i]);
            swap(s[index], s[i]);
            recurPermute(index + 1, s, ans);
            swap(s[index], s[i]);
        }
    }
    
    vector<string> findPermutation(string &s) {
        vector<string> ans;
        recurPermute(0, s, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) cout << i << " ";
        cout << "\n";
        cout << "~" << "\n";
    }
}