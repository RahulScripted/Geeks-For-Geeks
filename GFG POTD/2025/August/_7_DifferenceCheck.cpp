// Given an array arr[] of time strings in 24-hour clock format "HH:MM:SS", return the minimum difference in seconds between any two time strings in the arr[]. The clock wraps around at midnight, so the time difference between "23:59:59" and "00:00:00" is 1 second.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int toSeconds(string &time) {
        int h = stoi(time.substr(0, 2));   
        int m = stoi(time.substr(3, 2));   
        int s = stoi(time.substr(6, 2)); 
        
        return h * 3600 + m * 60 + s;      
    }

    int minDifference(vector<string> &arr) {
        vector<int> sec;
        int n = arr.size();
    
        for (int i = 0; i < n; i++) {
            sec.push_back(toSeconds(arr[i]));
        }
    
        sort(sec.begin(), sec.end());
        int minDiff = INT_MAX;
    
        for (int i = 1; i < n; i++) {
            int diff = sec[i] - sec[i - 1];
            minDiff = min(diff, minDiff);
        }
    
        int wrapdiff = 86400 - sec[n - 1] + sec[0]; 
        minDiff = min(minDiff, wrapdiff);
    
        return minDiff;
    }
};

int main() {
    Solution sol;
    vector<string> arr = {"23:59:59", "00:00:00", "12:30:45", "13:15:30"};
    cout << sol.minDifference(arr) << endl; 
    return 0;
}