// Stickler the thief wants to loot money from the houses arranged in a line. He cannot loot two consecutive houses and aims to maximize his total loot. Given an array, arr[] where arr[i] represents the amount of money in the i-th house. Determine the maximum amount he can loot.




#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];
    
        int secondLast = 0, last = arr[0];
    
        int res;
        for (int i = 1; i < n; i++) {
            res = max(arr[i] + secondLast, last);
            secondLast = last;
            last = res;
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}