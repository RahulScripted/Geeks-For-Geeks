// Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<int> dp(W + 1, 0);

        for (int i = 1; i <= wt.size(); i++) {
            for (int j = W; j >= wt[i - 1]; j--) {
                dp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
            }
        }
        return dp[W];
    }
};

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;
        ss >> numberOfItems;

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
}