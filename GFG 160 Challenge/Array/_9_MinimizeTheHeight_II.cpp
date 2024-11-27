// Given an array arr[] denoting heights of N towers and a positive integer K. For each tower, you must perform exactly one of the following operations exactly once.

// 1.  Increase the height of the tower by K

// 2.  Decrease the height of the tower by K

// Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int maxi = INT_MIN,secondMaxi = INT_MIN;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            if(arr[i] > maxi){
                secondMaxi = maxi;
                maxi = arr[i];
            }
            else if(arr[i] != maxi && arr[i] > secondMaxi) secondMaxi = arr[i];
        }
        if(secondMaxi == INT_MIN) return -1;
        else return secondMaxi;
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
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
}