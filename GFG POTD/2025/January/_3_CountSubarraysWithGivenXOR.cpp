// Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // Brute-force Solution
        // int res = 0;
        // for (int i = 0; i < arr.size(); i++) {
        //     int prefXOR = 0; 
        //     for (int j = i; j < arr.size(); j++) {
        //         prefXOR = prefXOR ^ arr[j];
        //         if (prefXOR == k) res++;
        //     }
        // }
        // return res;
    
        // Optimal Solution
        int res = 0; 
        unordered_map<int, int> mp;
        int prefXOR = 0;
        for (int val : arr) {
            prefXOR ^= val;
            res = res + mp[prefXOR ^ k];
            if (prefXOR == k) res++;
            mp[prefXOR]++;
        }
        return res;
    }
};

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc-- > 0) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) arr.push_back(num);

        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}