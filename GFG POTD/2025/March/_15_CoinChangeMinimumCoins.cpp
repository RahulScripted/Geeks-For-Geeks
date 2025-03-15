// You are given an array coins[], where each element represents a coin of a different denomination, and a target value sum. You have an unlimited supply of each coin type {coins1, coins2, ..., coinsm}. Your task is to determine the minimum number of coins needed to obtain the target sum. If it is not possible to form the sum using the given coins, return -1.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        vector<int> dp(sum+1, INT_MAX);
        dp[0] = 0; 
        
        for (int i=coins.size()-1; i>=0; i--) {
            for (int j=1; j<=sum; j++) {
                int take = INT_MAX, noTake = INT_MAX;
                
                if (j-coins[i]>=0 && coins[i]>0) {
                    take = dp[j-coins[i]]; 
                    if (take != INT_MAX) take++; 
                }
                
                if (i+1<coins.size()) noTake = dp[j]; 
                dp[j] = min(take, noTake);
            }
        }
        
        if (dp[sum]!=INT_MAX) return dp[sum];
        return -1;
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}