// Given an array arr. Your task is to find the minimum and maximum elements in the array.



#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        pair<long long, long long>pr;
        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            if(arr[i] > maxi) maxi = arr[i];
            if(arr[i] < mini) mini = arr[i];
        }
        pr.first = mini;
        pr.second = maxi;
        return pr;
    }
};

int main(){
    Solution solve;
    vector<long long int>arr = {3, 2, 1, 56, 10000, 167};

    pair<long long,long long>pr = solve.getMinMax(arr);
    cout<<"Minimum value : "<<pr.first<<" & maximum value :  "<<pr.second<<endl;
}