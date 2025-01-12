// Given an array of positive elements arr[] that is sorted and then rotated around an unknown point, the task is to check if the array has a pair with sum equals to a given target.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        int n = arr.size();
        int i;
        for(i = 0;i < (n - 1);i++){
            if(arr[i] > arr[i + 1]) break;
        }
        
        int l = (i + 1) % n;
        int r = i;
        while(l != r){
            if(arr[l] + arr[r] == target) return true;
            else if(arr[l] + arr[r] < target) l = (l + 1) % n;
            else r = (r - 1 + n) % n;
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        vector<int> arr;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        bool ans = ob.pairInSortedRotated(arr, target);
        if (ans) cout << "true\n";
        else cout << "false\n";
    }
}