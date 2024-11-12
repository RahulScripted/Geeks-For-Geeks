// Given an array arr[][] such that arr[i][0] is the starting time of ith meeting and arr[i][1] is the ending time of ith meeting, the task is to check if it is possible for a person to attend all the meetings such that he can attend only one meeting at a particular time.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end());

        // Check for overlapping meetings
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i][0] < arr[i - 1][1]) return false;
        }
        
        // If no overlaps found, return true
        return true;
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
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}