// Given an integer array arr[]. You need to find and return the maximum sum possible from all the subarrays.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += arr[i];
            if(sum > maxi) maxi = sum;
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) arr.push_back(number);

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}