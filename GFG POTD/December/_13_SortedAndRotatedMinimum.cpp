// A sorted array arr[] (may contain duplicates) is rotated at some unknown point, the task is to find the minimum element in it. 





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& arr) {
        // Binary Search
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            if (arr[lo] < arr[hi]) return arr[lo];
            int mid = (lo + hi) / 2;
            if (arr[mid] > arr[hi]) lo = mid + 1;
            else hi = mid;
        }

    return arr[lo]; 
        
        // Linear Search
        // int n = arr.size();
        // int mini = INT_MAX;
        // for(int i = 0;i < n;i++){
        //     if(arr[i] < mini) mini = arr[i];
        // }
        // return mini;
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}