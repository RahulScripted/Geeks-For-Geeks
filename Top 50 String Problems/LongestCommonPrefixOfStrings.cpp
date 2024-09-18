// Given an array of strings arr. Return the longest common prefix among each and every strings present in the array. If there's no prefix common in all the strings, return "-1".




#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        sort(arr.begin(),arr.end());
        string ans = "";
        int n = arr.size();
        string first = arr[0];
        string last = arr[n - 1];
        for(int i = 0;i < min(first.size(),last.size());i++){
            if(first[i] == last[i]) ans += first[i];
            else break;
        }
        return ans.size() > 0 ? ans : "-1";
    }
};

int main(){
    Solution solve;
    vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
    if(solve.longestCommonPrefix(arr) != "-1")cout<<"Longest common prefix : "<<solve.longestCommonPrefix(arr);
    else cout<<"Not found"<<endl;
}