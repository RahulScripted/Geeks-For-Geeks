// Given a sorted array of distinct positive integers arr[], we need to find the kth positive number that is missing from arr[].  




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int lo = 0, hi = arr.size() - 1;
        int res = arr.size() + k;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] > mid + k) {
                res = mid + k;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
    
        return res;
    }
};

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {
        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) arr.push_back(number);
        
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) crr.push_back(number);
        
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~" << "\n";
    }
    return 0;
}