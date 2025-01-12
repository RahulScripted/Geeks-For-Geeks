// Given an array arr[] of integers and another integer target. Find all unique quadruples from the given array that sums up to target.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        vector<vector<int>> res;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i = 0;i < n;i++){
            if(i > 0 && arr[i] == arr[i - 1]) continue;
            for(int j = (i + 1);j < n;j++){
                if(j > (i + 1) && arr[j] == arr[j - 1]) continue;
                int k = (j + 1),l = (n - 1);
                while(k < l){
                    int sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if(sum == target){
                        res.push_back({arr[i],arr[j],arr[k],arr[l]});
                        k++;
                        l--;
                        while(k < l && arr[k] == arr[k - 1]) k++;
                        while(k < l && arr[l] == arr[l + 1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            }
        }
        return res;
    }
};

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {
        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(arr, d);
        sort(ans.begin(), ans.end());
        for (auto &v : ans) {
            for (int &u : v) cout << u << " ";
            cout << endl;
        }
        if (ans.empty()) cout << -1 << endl;
        cout << "~" << "\n";
    }
    return 0;
}