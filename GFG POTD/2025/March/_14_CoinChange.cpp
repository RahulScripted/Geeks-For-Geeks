// Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. 




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<int> dp(sum + 1);
        dp[0] = 1;
    
        for (int i = 0; i < n; i++){
            for (int j = coins[i]; j <= sum; j++) dp[j] += dp[j - coins[i]];
        }
        return dp[sum];
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }
}