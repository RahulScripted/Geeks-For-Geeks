// Find the largest pair sum in an array of distinct integers.




#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int n = arr.size();
        int hi = INT_MIN,secondHi = INT_MIN;
        for(int i = 0;i < n;i++){
            if(arr[i] > hi){
                secondHi = hi;
                hi = arr[i];
            }
            else if(arr[i] > secondHi && arr[i] != hi) secondHi = arr[i];
        }
        return secondHi + hi;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>arr = {12, 34, 10, 6, 40};
    cout<<"Largest pair sum will be : "<<solve.pairsum(arr)<<endl;
}