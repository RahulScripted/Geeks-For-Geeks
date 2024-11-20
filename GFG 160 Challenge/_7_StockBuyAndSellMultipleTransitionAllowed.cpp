// The cost of stock on each day is given in an array price[]. Each day you may decide to either buy or sell the stock at price[i], you can even buy and sell the stock on the same day. Find the maximum profit that you can get.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int maximumProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) arr.push_back(number);

        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res << endl;
    }
}