// Given an array arr[] of non-negative integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<int> lis(n, 1);
    
        for (int i = 1; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[i] > arr[prev] && lis[i] < lis[prev] + 1) {
                    lis[i] = lis[prev] + 1;
                }
            }
        }
    
        return *max_element(lis.begin(), lis.end());
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }
}