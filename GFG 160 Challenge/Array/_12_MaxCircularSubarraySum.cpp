// Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int temp_max = 0, temp_min = 0;
        int max_sum = INT_MIN, min_sum = INT_MAX;
        int total = 0;
        for(int i = 0; i < n; i++){
            total += arr[i];
            temp_max += arr[i];
            temp_min += arr[i];
            if(temp_max < arr[i]) temp_max = arr[i];
            if(temp_min > arr[i]) temp_min = arr[i];
            max_sum = max(max_sum, temp_max);
            min_sum = min(min_sum, temp_min);
        }
        if(total == min_sum) return max_sum;
        return max(max_sum, total - min_sum);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) arr.push_back(number);

        Solution ob;
        int res = ob.circularSubarraySum(arr);
        cout << res << endl;
    }
}