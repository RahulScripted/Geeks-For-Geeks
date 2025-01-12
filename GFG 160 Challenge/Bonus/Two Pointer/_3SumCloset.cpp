// Given an array arr[] and an integer target, the task is to find the sum of three integers in arr[] such that the sum is closest to target. 





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int res = 0,min = INT_MAX;
        for(int i = 0;i < (n - 2);i++){
            int l = (i + 1),r = (n - 1);
            while(l < r){
                int currSum = arr[i] + arr[l] + arr[r];
                if(abs(currSum - target) < min){
                    min = abs(currSum - target);
                    res = currSum;
                }
                else if(abs(currSum - target) == min) res = max(res,currSum);
                if(currSum > target) r--;
                else l++;
            }
        }
        return res;
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
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int target = stoi(input);

        Solution obj;
        cout << obj.closest3Sum(arr, target) << endl;
        cout << "~" << endl;
    }
    return 0;
}