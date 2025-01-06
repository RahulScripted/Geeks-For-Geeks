// You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Brute-force
        // int n = arr.size();
        // int cnt = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (arr[i] + arr[j] == target) cnt++;
        //     }
        // }
        // return cnt;
        
        // Optimal
        unordered_map<int, int> freq;
        int count = 0;
    
        for (int num : arr) {
            int complement = target - num;
            if (freq.find(complement) != freq.end()) count += freq[complement];
            freq[num]++;
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }
}