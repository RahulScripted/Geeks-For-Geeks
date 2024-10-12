// Given an array of integers arr, the task is to find and return the maximum sum of the smallest and second smallest element among all possible subarrays of size greater than one. If it is not possible, then return -1.





#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return -1;

        int maxSum = arr[0] + arr[1];  
        for (int i = 1; i < n - 1; ++i) {
            maxSum = max(maxSum, arr[i] + arr[i + 1]);
        }

        return maxSum;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>arr = {4, 3, 1, 5, 6};
    cout<<"Maximum sum of the smallest and second smallest element will be : "<<solve.pairWithMaxSum(arr)<<endl;

    // 2nd Example
    arr = {1};
    cout<<"Maximum sum of the smallest and second smallest element will be : "<<solve.pairWithMaxSum(arr)<<endl;
}