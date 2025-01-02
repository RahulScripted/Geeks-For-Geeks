// Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // Brute-force Solution
        // int n = arr.size();
        // int count = 0;
        // for(int i = 0;i < (n - 1);i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(arr[i] + arr[j] == k) count++;
        //     }
        // }
        // return count; 
        
        // Optimal Solution
        unordered_map<int, int> prefixSums;
  
        int res = 0;
        int currSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            currSum += arr[i];
            if (currSum == k) res++;
            if (prefixSums.find(currSum - k) != prefixSums.end())
                res += prefixSums[currSum - k];
            prefixSums[currSum]++;
        }
    
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~" << "\n";
    }

    return 0;
}