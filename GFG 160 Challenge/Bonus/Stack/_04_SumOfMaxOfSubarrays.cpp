// Given an array arr[], the task is to find the sum of the maximum elements of every possible non-empty sub-arrays of the given array arr[].





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumOfMax(vector<int> &arr) {
        int n = arr.size();
        stack<int>st;
        int res = 0;
        vector<int>left(n), right(n);
        
        for(int i = 0;i < n;i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        for(int i = (n - 1); i >= 0;--i){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        
        for(int i = 0;i < n;++i){
            res += arr[i] * left[i] * right[i];
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
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.sumOfMax(arr);
        cout << result;
        cout << "\n~\n";
    }
    return 0;
}