// Given a non-empty integer array arr[] of size n, find the top k elements which have the highest frequency in the array.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &arr, int k) {
        int n = arr.size();
        
        unordered_map<int,int>mp;
        for(int i = 0;i < n;i++){
            mp[arr[i]]++;
        }
        
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(pair<int,int>entry : mp){
            pq.push({entry.second,entry.first});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int>res(k);
        for(int i = (k - 1); i >= 0;i--){
            res[i] = pq.top().second;
            pq.pop();
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
        vector<int> res = obj.topKFrequent(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~" << "\n";
    }
    return 0;
}