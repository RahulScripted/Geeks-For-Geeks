// Given a circular integer array arr[], the task is to determine the next greater element (NGE) for each element in the array. The next greater element of an element arr[i] is the first element that is greater than arr[i] when traversing circularly. If no such element exists, return -1 for that position.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int>res(n,-1);
        stack<int>st;
        
        for(int i = (2 * n) - 1;i >= 0;i--){
            while(!st.empty() && st.top() <= arr[i % n]) st.pop();
            if(i < n && !st.empty()) res[i] = st.top();
            st.push(arr[i % n]);
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
        int n = arr.size();
        vector<int> v = ob.nextLargerElement(arr);
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        cout << "~" << "\n";
    }
    return 0;
}