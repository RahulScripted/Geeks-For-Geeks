// Given an array arr[] and a target, your task is to find all unique combinations in the array where the sum is equal to target. The same number may be chosen from the array any number of times to make target.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void makeCombination(vector<int> &arr, int target, vector<int> &curr, vector<vector<int>> &res, int index){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        
        if(target < 0 || index >= arr.size()) return;
        curr.push_back(arr[index]);
        makeCombination(arr,target - arr[index], curr, res, index);
        curr.pop_back();
        makeCombination(arr,target,curr,res, index + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int> curr;
        vector<vector<int>> res;
        makeCombination(arr, target, curr, res, 0);
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        vector<vector<int>> ans = ob.combinationSum(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }
}