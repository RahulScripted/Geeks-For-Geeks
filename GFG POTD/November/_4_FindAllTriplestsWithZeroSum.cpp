// Given an array arr[], find all possible indices [i, j, k] of triplets [arr[i], arr[j], arr[k]] in the array whose sum is equal to zero. Return indices of triplets in any order and all the returned triplets indices should also be internally sorted, i.e., for any triplet indices [i, j, k], the condition i < j < k should hold.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Brute-force
        vector<vector<int>> ans;
        int n = arr.size();
        for(int i = 0;i < (n - 2);i++){
            for(int j = (i + 1);j <(n - 1);j++){
                for(int k = (j + 1);k < n;k++){
                    if(arr[i] + arr[j] + arr[k] == 0) ans.push_back({i,j,k});
                }
            }
        }
        return ans;
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
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}