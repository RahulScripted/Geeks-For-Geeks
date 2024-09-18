// Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array(In Place). In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5]..... If there are multiple solutions, find the lexicographically smallest one.




#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void convertToWave(int n, vector<int>& arr){
        for(int i = 0;i < n;i+=2){
            if(i < n && (i + 1) < n) swap(arr[i],arr[i + 1]);
        }
    }
};

void display(int n, vector<int>& arr){
    for(int i = 0;i < n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    Solution solve;
    int n = 5;
    vector<int> arr = {1,2,3,4,5};
    cout<<"Before wave : ";
    display(n,arr);
    solve.convertToWave(n,arr);
    cout<<"After wave : ";
    display(n,arr);
}