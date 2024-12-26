// Given an array arr[] and an integer target. You have to find numbers of pairs in array arr[] which sums up to given target.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Brute-force
        // int n = arr.size();
        // int count = 0;
        // for(int i = 0;i < (n - 1);i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(arr[i] + arr[j] == target) count++;
        //     }
        // }
        // return count;
        
        // Optimal Solution
        int n = arr.size();
        unordered_map<int,int>mp;
        
        int count = 0;
        for(int i = 0;i < n;i++){
            if(mp.find(target - arr[i]) != mp.end()) count += mp[target - arr[i]];
            mp[arr[i]]++;
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}