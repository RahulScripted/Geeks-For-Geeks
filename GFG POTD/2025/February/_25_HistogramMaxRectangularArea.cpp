// You are given a histogram represented by an array arr, where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit. Your task is to find the largest rectangular area possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        stack<int> s;
        int res = 0;
        int tp, curr;
        for (int i = 0; i < n; i++) {      
             
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                tp = s.top(); 
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
              
                res = max(res,  arr[tp] * width);
            }
            s.push(i);
        }
    
        while (!s.empty()) {
            tp = s.top(); 
            s.pop();
            curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
            res = max(res, curr);
        }
    
        return res;
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}