// In daily share trading, a trader buys shares and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, find out the maximum profit that a share trader could have made. You are given an array prices[] representing stock prices throughout the day. Note that the second transaction can only start after the first one is complete (buy->sell->buy->sell).





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int firstBuy = INT_MIN;  
        int firstSell = 0;      
        int secondBuy = INT_MIN; 
        int secondSell = 0;      
        
        for (int i = 0; i < prices.size(); i++) {
            firstBuy = max(firstBuy, -prices[i]);
            firstSell = max(firstSell, firstBuy + prices[i]);
            secondBuy = max(secondBuy, firstSell - prices[i]);
            secondSell = max(secondSell, secondBuy + prices[i]);
        }
        
        return secondSell;
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
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
}