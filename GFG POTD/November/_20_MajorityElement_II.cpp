// You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i = 0;i < n;i++) mp[arr[i]]++;
        
        vector<int>ans;
        for(auto x : mp){
            if(x.second > (n / 3)) ans.push_back(x.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) cout << "[]";
        else {
            for (auto &i : ans) cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}