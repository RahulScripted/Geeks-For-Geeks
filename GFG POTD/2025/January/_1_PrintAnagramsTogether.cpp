// Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.





#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int MAX_CHAR = 26;
class Solution {
  public:
    string getHash(string &s) {
        string hash;
        vector<int> freq(MAX_CHAR, 0);
        for(char ch: s) freq[ch - 'a'] += 1;
        for(int i = 0; i < MAX_CHAR; i++) {
            hash.append(to_string(freq[i]));
            hash.append("$");
        }
        return hash;
    }
    
    vector<vector<string>> anagrams(vector<string>& arr) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            string key = getHash(arr[i]);
            if (mp.find(key) == mp.end()) {
                mp[key] = res.size();
                res.push_back({});
            }
            res[mp[key]].push_back(arr[i]);
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "~" << "\n";
    }

    return 0;
}