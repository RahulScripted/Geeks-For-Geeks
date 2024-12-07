// Given an array of Intervals arr[][], where arr[i] = [start_i, end_i]. The task is to merge all of the overlapping Intervals.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        res.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++) {
            vector<int>& last = res.back();
            vector<int>& curr = arr[i];
            if (curr[0] <= last[1]) last[1] = max(last[1], curr[1]);
            else res.push_back(curr);
        }
        return res;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }

        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}