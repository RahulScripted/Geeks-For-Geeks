// Given an array of positive integers arr[] and a non-negative integer x, the task is to find the longest sub-array where the absolute difference between any two elements is not greater than x. If multiple such subarrays exist, return the one that starts at the smallest index.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        deque<int> minQueue, maxQueue;
        int n = arr.size(), start = 0, end = 0;
        
        int resStart = 0, resEnd = 0;
        while (end < n) {
            while (!minQueue.empty() && arr[minQueue.back()] > arr[end])
                minQueue.pop_back();
                
            while (!maxQueue.empty() && arr[maxQueue.back()] < arr[end])
                maxQueue.pop_back();
                
            minQueue.push_back(end);
            maxQueue.push_back(end);
            
            while (arr[maxQueue.front()] - arr[minQueue.front()]
                   > x) {
                if (start == minQueue.front())
                    minQueue.pop_front();
                if (start == maxQueue.front())
                    maxQueue.pop_front();
                start += 1;
            }
            
            if (end - start > resEnd - resStart) {
                resStart = start;
                resEnd = end;
            }
            end += 1;
        }
    
        vector<int> res;
        for (int i = resStart; i <= resEnd; i++)
            res.push_back(arr[i]);
            
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
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}