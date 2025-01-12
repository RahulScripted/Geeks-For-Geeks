// Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int res = 0;
        while(left < right) {
            int water = min(arr[left], arr[right]) * (right - left);
            res = max(res, water);
          
            if(arr[left] < arr[right]) left += 1;
            else right -= 1;
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
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);
        cout << res << endl << "~" << endl;
    }
}