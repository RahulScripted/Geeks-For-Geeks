// Given an array arr[] of non-negative numbers. The task is to find the first equilibrium point in the array. The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists. 




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // Brute - force
        // int leftSum, rightSum;
        // int n = arr.size();
 
        // for (int i = 0; i < n; i++) {
        //     leftSum = 0;
        //     for (int j = 0; j < i; j++) leftSum += arr[j];

        //     rightSum = 0;
        //     for (int j = i + 1; j < n; j++) rightSum += arr[j];
            
        //     if (leftSum == rightSum) return i;
        // }
        // return -1;
        
        // Optimal Solution
        int prefSum = 0, total = 0;
        for (int ele: arr) total += ele;
    
        for (int pivot = 0; pivot < arr.size(); pivot++) {
            int suffSum = total - prefSum - arr[pivot];
            if (prefSum == suffSum) return pivot;
            prefSum += arr[pivot];
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        vector<int> arr;
        string input;
        getline(cin, input); 
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}