// You are given an array of integer nums[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return -1. 





#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {-1}; 

        int num1 = -1, num2 = -1;  
        int c1 = 0, c2 = 0;  

        for (auto x : nums) {
            if (x == num1) c1++;
            else if (x == num2) c2++;
            else if (c1 == 0) {
                num1 = x;
                c1 = 1;
            } 
            else if (c2 == 0) {
                num2 = x;
                c2 = 1;
            } 
            else {
                c1--;
                c2--;
            }
        }

        c1 = 0, c2 = 0;
        for (auto x : nums) {
            if (x == num1) c1++;
            else if (x == num2) c2++;
        }

        vector<int> res;
        if (c1 > n / 3) res.push_back(num1);
        if (c2 > n / 3) res.push_back(num2);

        if (res.empty()) res.push_back(-1);

        return res;
    }
};

void display(vector<int>&nums){
    for(int i = 0;i < nums.size();i++) cout<<nums[i]<<" ";
    cout<<endl;
}

int main(){
    Solution solve;

    // 1st Example
    cout<<"Our array : ";
    vector<int>nums = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    display(nums);
    cout<<"Majority element : ";
    vector<int>ans = solve.findMajority(nums);
    display(ans);

    // 2nd Example
    cout<<"Our array : ";
    nums = {1, 2, 3, 4, 5};
    display(nums);
    cout<<"Majority element : ";
    ans = solve.findMajority(nums);
    display(ans);
}