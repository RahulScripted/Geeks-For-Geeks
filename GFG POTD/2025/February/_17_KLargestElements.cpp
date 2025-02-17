// Given an array arr[] of positive integers and an integer k, Your task is to return k largest elements in decreasing order. 





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Brute force
        // sort(arr.begin(),arr.end());
        // vector<int>ans;
        // int n = arr.size();
        // for(int i = (n - 1);i >= 0;i--){
        //     if(k > 0){
        //         ans.push_back(arr[i]);
        //         k--;
        //     }
        //     else break;
        // }
        // return ans;
        
        // Using Priority - Queue
        
        priority_queue<int, vector<int>, greater<int>> minH(arr.begin(), arr.begin() + k);
        for (int i = k; i < arr.size(); i++) {
              if(minH.top() < arr[i]) {
                minH.pop();
                minH.push(arr[i]);
            }
        }
    
        vector<int> res;
        while (!minH.empty()) {
            res.push_back(minH.top());
            minH.pop();
        }
        reverse(res.begin(), res.end());
        return res;
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
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}