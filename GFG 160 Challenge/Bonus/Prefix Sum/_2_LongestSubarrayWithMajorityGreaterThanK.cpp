// Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        int sum = 0,res = 0;
        unordered_map<int,int>freq;
        
        for(int i = 0;i < n;i++){
            sum += (arr[i] > k ? 1 : -1);
            if(freq.find(sum) == freq.end()) freq[sum] = i;
        }
        
        if(freq.find(-n) != freq.end()) return 0;
        freq[-n] = n;
        
        for(int i = (-n + 1);i <= n;i++){
            if(freq.find(i) == freq.end()) freq[i] = freq[i - 1];
            else freq[i] = min(freq[i],freq[i - 1]);
        }
        
        sum = 0;
        for(int i = 0;i < n;i++){
            sum += (arr[i] > k ? 1 : -1);
            if(sum > 0) res = (i + 1);
            else res = max(res,i - freq[sum - 1]);
        }
        return res;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
}