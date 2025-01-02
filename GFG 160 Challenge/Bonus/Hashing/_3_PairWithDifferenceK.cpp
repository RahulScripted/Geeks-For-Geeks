// Given an array arr[] of positive integers. Find the number of pairs of integers whose absolute difference equals to a given number k.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int>freq;
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(freq.find(arr[i] + k) != freq.end()) cnt += freq[arr[i] + k];
            if(freq.find(arr[i] - k) != freq.end()) cnt += freq[arr[i] - k];
            freq[arr[i]]++;
        }
        return cnt;
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
        auto ans = ob.countPairs(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}