// Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        int n = intervals.size();
        int cnt = 0;
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < end) {
                cnt++;
                end = min(intervals[i][1], end);
            }
            else end = intervals[i][1];
        }
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~" << "\n";
    }
    return 0;
}