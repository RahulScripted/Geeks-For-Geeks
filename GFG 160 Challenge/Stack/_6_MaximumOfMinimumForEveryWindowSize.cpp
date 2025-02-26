// Given an array of integers arr[], the task is to find the maximum of the minimum values for every possible window size in the array, where the window size ranges from 1 to arr.size(). More formally, for each window size k, determine the smallest element in all windows of size k, and then find the largest value among these minimums where 1<=k<=arr.size().





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0); 
        stack<int> s;
        vector<int> len(n, 0);
        
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                int top = s.top();
                s.pop();
                int windowSize = s.empty() ? i : i - s.top() - 1;
                len[top] = windowSize;
            }
            s.push(i);
        }
    
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            int windowSize = s.empty() ? n : n - s.top() - 1;
            len[top] = windowSize;
        }
    
        for (int i = 0; i < n; i++) {
            int windowSize = len[i] - 1; 
            res[windowSize] = max(res[windowSize], arr[i]);
        }
    
        for (int i = n - 2; i >= 0; i--)
            res[i] = max(res[i], res[i + 1]);
    
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
}