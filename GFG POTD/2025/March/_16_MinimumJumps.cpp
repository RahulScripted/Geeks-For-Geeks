// You are given an array arr[] of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.

// 1. If arr[i] = 3, you can jump to index i + 1, i + 2, or i + 3 from position i.

// 2. If arr[i] = 0, you cannot jump forward from that position.

// Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position. Return -1 if you can't reach the end of the array.






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        if (arr[0] == 0) return -1;
        
        int n = arr.size();
        int maxReach = 0;
        int currReach = 0;
        int jump = 0;
    
        for (int i = 0; i < n; i++) {
            maxReach = max(maxReach, i+arr[i]);
            if (maxReach >= n-1) return jump + 1;
          
            if (i == currReach) {
                if (i == maxReach) return -1;
                else {
                    jump++;    
                    currReach = maxReach;
                }
            }
        }
      
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
}