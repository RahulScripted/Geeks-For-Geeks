// Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int left = 1;
        int right = arr.size() - 2;
        int lMax = arr[left - 1];
        int rMax = arr[right + 1];
    
        int res = 0;
        while (left <= right) {
            if (rMax <= lMax) {
                res += max(0, rMax - arr[right]);
                rMax = max(rMax, arr[right]);
                right -= 1;
            } 
            else {
                res += max(0, lMax - arr[left]);
                lMax = max(lMax, arr[left]);
                left += 1;
            }
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