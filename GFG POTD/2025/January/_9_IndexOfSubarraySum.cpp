// Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value target. You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first subarray whose sum is equal to the target.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int s = 0, e = 0;  
        vector<int> res;
    
        int curr = 0;
        for (int i = 0; i < arr.size(); i++) {
            curr += arr[i];
            if (curr >= target) {
                e = i;
                while (curr > target && s < e) {
                    curr -= arr[s];
                    ++s;
                }
                
                if (curr == target) {
                    res.push_back(s + 1);
                    res.push_back(e + 1);
                    return res;
                }
            }
        }
        return {-1};
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
}