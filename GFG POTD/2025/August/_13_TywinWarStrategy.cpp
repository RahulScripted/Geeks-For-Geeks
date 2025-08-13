// You are given an array arr[] of size n, where arr[i] represents the number of soldiers in the i-th troop. You are also given an integer k. A troop is considered "lucky" if its number of soldiers is a multiple of k. Find the minimum total number of soldiers to add across all troops so that at least ⌈n / 2⌉ troops become lucky.


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int required = (n + 1) / 2; 
        int currentLucky = 0;
        vector<int> costs;

        for (int soldiers : arr) {
            if (soldiers % k == 0) currentLucky++;
            else costs.push_back(k - (soldiers % k));
        }

        if (currentLucky >= required) return 0;
        sort(costs.begin(), costs.end());

        int soldiersToAdd = 0;
        int need = required - currentLucky;
        for (int i = 0; i < need; i++) soldiersToAdd += costs[i];

        return soldiersToAdd;
    }
};  

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.minSoldiers(arr, k) << endl;
}