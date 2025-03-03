// Given an array arr[] and an integer k, your task is to collect the maximum score possible by performing the following operations:
// 1. Start from the 0th index of the array.
// 2. Reach the last index of the array by jumping at most k indices in each move.
// 3. Add the value stored at each index where you reach after the jump (consider the score of the starting index too).





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getScore(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, INT_MIN);
        
        dp[n - 1] = arr[n - 1];
        deque<int> dq;
        dq.push_back(n - 1);
        
        for(int i = (n - 2); i >= 0;i--){
            while(!dq.empty() && dq.front() > i + k) dq.pop_front();
            dp[i] = arr[i] + dp[dq.front()];
            while(!dq.empty() && dp[i] >= dp[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        
        return dp[0];
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.getScore(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}