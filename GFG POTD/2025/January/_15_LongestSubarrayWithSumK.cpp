// Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int res = 0;
        int prefSum = 0;
    
        for (int i = 0; i < arr.size(); ++i) {
            prefSum += arr[i];
            if (prefSum == k) res = i + 1;
            else if (mp.find(prefSum - k) != mp.end()) res = max(res, i - mp[prefSum - k]);
            if (mp.find(prefSum) == mp.end()) mp[prefSum] = i;
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine);
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore();
        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }
}