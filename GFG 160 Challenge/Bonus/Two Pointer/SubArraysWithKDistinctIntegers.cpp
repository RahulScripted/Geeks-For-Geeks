// You are given an array arr[] of positive integers and an integer k, find the number of subarrays in arr[] where the count of distinct integers is exactly k.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int found(vector<int>&arr,int k){
        int n = arr.size(), res = 0;
        int left = 0,right = 0;
        unordered_map<int,int>freq;
        while(right < n){
            freq[arr[right]] += 1;
            if(freq[arr[right]] == 1) k -= 1;
            while(k < 0){
                freq[arr[left]] -= 1;
                if(freq[arr[left]] == 0) k += 1;
                left += 1;
            }
            res += (right - left + 1);
            right += 1;
        }
        return res;
    }
    
    int exactlyK(vector<int> &arr, int k) {
        return found(arr,k) - found(arr,k - 1);
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
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.exactlyK(arr, k) << endl;
        cout << "~" << endl;
    }
}