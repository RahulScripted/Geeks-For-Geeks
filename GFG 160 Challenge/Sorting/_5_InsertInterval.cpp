// Geek has an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti. He wants to add a new interval newInterval= [newStart, newEnd] where newStart and newEnd represent the start and end of this interval. Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
    
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
    
        return result;
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
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;
        cout << "~" << "\n";
    }
    return 0;
}