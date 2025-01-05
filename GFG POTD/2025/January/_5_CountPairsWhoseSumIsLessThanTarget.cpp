// Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Brute-force
        // int n = arr.size();
        // int count = 0;
        // for(int i = 0;i < (n - 1);i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(arr[i] + arr[j] < target) count++;
        //     }
        // }
        // return count;
        
        // Optimal
        sort(arr.begin(), arr.end());
        int left = 0, right = arr.size() - 1;
        int cnt = 0;
        
        while(left < right) {
            int sum = arr[left] + arr[right];
            if (sum < target) {
                cnt += right-left;
                left++;
            }
            else right--;
        }
        
        return cnt;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}