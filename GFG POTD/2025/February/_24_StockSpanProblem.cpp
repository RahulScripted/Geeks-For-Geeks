// The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days. The span arr[i] of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the given day is less than or equal to its price on the current day.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> span(n);  
        stack<int> stk;  
    
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] <= arr[i]) {
                stk.pop();
            }
    
            if (stk.empty()) span[i] = (i + 1);
            else span[i] = (i - stk.top());
    
            stk.push(i);
        }
    
        return span;
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}