// Given an array of elements arr[] with indices ranging from 0 to arr.size() - 1, your task is to write a program that rearranges the elements of the array such that arr[i] = i. If an element i is not present in the array, -1 should be placed at the corresponding index.





#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);

        // Place elements at their corresponding index if valid
        for (int i = 0; i < n; ++i) {
            if (arr[i] >= 0 && arr[i] < n) result[arr[i]] = arr[i];
        }
        
        return result;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    vector<int>res = solve.rearrange(arr);
    cout<<"After rearranging array : ";
    for(int i = 0;i < res.size();i++) cout<<res[i]<<" ";
    cout<<endl;

    // 2nd Example
    arr = {2, 0, 1};
    res = solve.rearrange(arr);
    cout<<"After rearranging array : ";
    for(int i = 0;i < res.size();i++) cout<<res[i]<<" ";
    cout<<endl;
}