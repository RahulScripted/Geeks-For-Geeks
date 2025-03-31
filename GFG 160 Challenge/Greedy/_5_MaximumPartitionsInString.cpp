// Given a string s of lowercase English alphabets, your task is to return the maximum number of substrings formed, after possible partitions (probably zero) of s such that no two substrings have a common character.






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxPartitions(string &s) {
        int n = s.length();
        vector<int>arr(26,-1);
        for(int i = 0;i < n;i++){
            arr[s[i] - 'a'] = i;
        }
        
        int count = 0, curr = -1;
        for(int i = 0;i < n;i++){
            curr = max(curr, arr[s[i] - 'a']);
            if(curr == i){
                count++;
                curr = -1;
            }
        }
        return count;
    }
};

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }
}