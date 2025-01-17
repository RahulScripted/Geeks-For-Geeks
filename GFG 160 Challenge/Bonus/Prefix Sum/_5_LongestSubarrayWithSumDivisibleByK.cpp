// Given an array arr[] and a positive integer k, find the length of the longest subarray with the sum of the elements divisible by k.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        int n = arr.size(),res = 0,sum = 0;
        unordered_map<int,int> freq;
        
        for(int i = 0;i < n;i++){
            sum = ((sum + arr[i]) % k + k) % k;
            if(sum == 0) res = (i + 1);
            else if(freq.find(sum) != freq.end()) res = max(res, (i - freq[sum]));
            else freq[sum] = i;
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
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.longestSubarrayDivK(arr, d);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}