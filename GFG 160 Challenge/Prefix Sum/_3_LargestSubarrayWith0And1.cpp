// Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        unordered_map<int, int> mp;
        int preSum = 0; 
        int res = 0; 
      
        for (int i = 0; i < arr.size(); i++) {
            preSum += (arr[i] == 0) ? -1 : 1;
            if (preSum == 0) res = i + 1;
            if (mp.find(preSum) != mp.end()) res = max(res, i - mp[preSum]);
            else mp[preSum] = i;
        }
        return res;
    }
};

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        Solution obj;
        cout << obj.maxLen(a) << endl;
    }
}