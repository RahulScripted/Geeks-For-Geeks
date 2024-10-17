// Given an array arr[] of positive integers where every element appears even times except for one. Find that number occurring an odd number of times.





#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSingle(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            ans ^= arr[i];
        }
        return ans;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>arr = {1,1,2,2,2};
    cout<<"Single number is : "<<solve.getSingle(arr)<<endl;

    // 2nd Example
    arr = {8, 8, 7, 7, 6, 6, 1};
    cout<<"Single number is : "<<solve.getSingle(arr)<<endl;
}