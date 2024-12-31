// Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> st;
        int res = 0;
        for (int val: arr) st.insert(val);
        
        for (int val: arr) {
            if (st.find(val) != st.end() && st.find(val-1) == st.end()) {
                int cur = val, cnt = 0;
                while (st.find(cur) != st.end()) {
                    st.erase(cur);
                    cur++;
                    cnt++;
                }
                res = max(res, cnt);
            }
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}