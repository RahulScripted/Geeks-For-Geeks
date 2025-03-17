// Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2 != 0)  return false;
        sum = sum / 2;
        int n = arr.size();
        vector<bool> prev(sum + 1, false), curr(sum + 1);
        prev[0] = true;
    
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j < arr[i - 1]) curr[j] = prev[j];
                else curr[j] = (prev[j] || prev[j - arr[i - 1]]);
            }
            prev = curr;
        }
        return prev[sum];
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

        Solution ob;
        if (ob.equalPartition(arr)) cout << "true\n";
        else cout << "false\n";
        cout << "~" << endl;
    }
}