// Given an array arr[] and an integer target, determine if there exists a triplet in the array whose sum equals the given target. Return true if such a triplet exists, otherwise, return false.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i = 0;i < (n - 2);i++){
            int l = (i + 1),r = (n - 1);
            int required = target - arr[i];
            while(l < r){
                if(arr[l] + arr[r] == required) return true;
                else if(arr[l] + arr[r] < required) l++;
                else r--;
            }
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine);
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); 

        Solution solution;
        bool result = solution.hasTripletSum(arr, target);
        cout << (result ? "true" : "false") << "\n";
    }
}