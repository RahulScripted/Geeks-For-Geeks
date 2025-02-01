// Given an array arr[] and a target, your task is to find all unique combinations in the array where the sum is equal to target. Each number in arr[] may only be used once in the combination.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> res;
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        dfs(0, {}, 0, arr, target);
        return res;
    }
  private:
    void dfs(int idx, vector<int> path, int curr, vector<int> &arr, int target){
        if(curr == target){
            res.push_back(path);
            return;
        }
        
        for(int i = idx; i < arr.size(); i++){
            if(i > idx && arr[i] == arr[i - 1]) continue;
            if(curr + arr[i] > target) break;
            path.push_back(arr[i]);
            dfs((i + 1), path, curr + arr[i], arr, target);
            path.pop_back();
        }
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
        vector<vector<int>> ans = ob.uniqueCombinations(arr, sum);
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

    return 0;
}