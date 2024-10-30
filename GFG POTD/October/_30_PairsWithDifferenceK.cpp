// Given an array arr[] of positive integers. Find the number of pairs of integers whose difference equals a given number k.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // Set
        unordered_set<int> numSet(arr.begin(), arr.end());
        int count = 0;

        for (int x : numSet) {
            if (numSet.find(x + k) != numSet.end()) {
                count += count_if(arr.begin(), arr.end(), [x](int n){ return n == x; }) * 
                         count_if(arr.begin(), arr.end(), [x, k](int n){ return n == x + k; });
            }
        }

        return count;
        
        // Brute-force [Gives TLE]
        // int n = arr.size();
        // int count  = 0;
        // for(int i = 0;i < (n - 1);i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(abs(arr[i] - arr[j]) == k) count++;
        //     }
        // }
        // return count;
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}