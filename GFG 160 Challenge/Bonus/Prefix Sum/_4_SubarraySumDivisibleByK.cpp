// You are given an integer array arr[] and a value k. The task is to find the count of all sub-arrays whose sum is divisible by k.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int subCount(vector<int>& arr, int k) {
        int n = arr.size(), res = 0, sum = 0;
        unordered_map<int,int>freq;
        
        for(int i = 0;i < n;i++){
            sum = ((sum + arr[i]) % k + k) % k;
            if(sum == 0) res += 1;
            res += freq[sum];
            freq[sum] += 1;
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
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();
        Solution ob;
        cout << ob.subCount(arr, d);
        cout << endl << "~" << endl;
    }
}