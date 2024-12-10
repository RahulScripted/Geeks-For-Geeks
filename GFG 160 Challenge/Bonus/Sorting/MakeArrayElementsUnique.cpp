// Given an integer array arr[ ], your task is to find the minimum number of increment operations required to make all the array elements unique. i.e. no value in the array should occur more than once. In one operation, a value can be incremented by 1 only.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        if (arr.empty()) return 0;

        int ans = 0;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] <= arr[i - 1]) {
                ans += arr[i - 1] - arr[i] + 1;
                arr[i] = arr[i - 1] + 1; 
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}