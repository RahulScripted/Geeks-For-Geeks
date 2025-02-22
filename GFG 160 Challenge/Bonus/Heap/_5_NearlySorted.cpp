// Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0;i < k;i++) pq.push(arr[i]);
        
        int i;
        for(i = k;i < n;i++){
            pq.push(arr[i]);
            arr[i - k] = pq.top();
            pq.pop();
        }
        
        while(!pq.empty()){
            arr[i - k] = pq.top();
            pq.pop();
            i++;
        }
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
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}