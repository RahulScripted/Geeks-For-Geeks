// Given a positive integer k and an array arr[] denoting heights of towers, you have to modify the height of each tower either by increasing or decreasing them by k only once. Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int maxi = arr[n - 1],mini = arr[0];
        int ans = maxi - mini;
        for(int i = 1;i < n;i++){
            maxi = max(arr[i - 1] + k,arr[n - 1] - k);
            mini = min(arr[i] - k,arr[0] + k);
            ans = min(ans,(maxi - mini));
        }
        return ans;
    }
};

int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
}