// Given an array of strings (all lowercase letters), the task is to group them in such a way that all strings in a group are shifted versions of each other.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string getHash(string s){
        int shifts = s[0] - 'a';
        for(char &ch : s){
            ch = ch - shifts;
            if(ch < 'a') ch += 26;
        }
        return s;
    }
    
    vector<vector<string>> groupShiftedString(vector<string> &arr) {
        vector<vector<string>> res;
        unordered_map<string,int> mp;
        for(string s : arr){
            string hash = getHash(s);
            if(mp.find(hash) == mp.end()){
                mp[hash] = res.size();
                res.push_back({});
            }
            res[mp[hash]].push_back(s);
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        vector<vector<string>> v = ob.groupShiftedString(a);
        int n = v.size();
        for (int i = 0; i < n; i++) {
            sort(v[i].begin(), v[i].end());
        }
        sort(v.begin(), v.end());
        for (auto x : v) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}