// Given an array arr of size n−1 that contains distinct integers in the range of 1 to n (inclusive), find the missing element. The array is a permutation of size n with one element missing. Return the missing element.


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int missingNumber(int n, vector<int>& arr) {
        int sum = 0;
        for(int i = 0;i < (n - 1);i++){
            sum += arr[i];
        }
        int actualSum = (n * (n + 1)) / 2;
        return (actualSum - sum);
    }
};

int main(){
    Solution solve;
    int n = 5;
    vector<int> arr = {1,2,3,5};
    cout<<"Missing value : "<<solve.missingNumber(n,arr);
}