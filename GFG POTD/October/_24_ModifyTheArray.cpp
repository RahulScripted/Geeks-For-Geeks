// Given an array arr. Return the modified array in such a way that if the current and next numbers are valid numbers and are equal then double the current number value and replace the next number with 0. After the modification, rearrange the array such that all 0's are shifted to the end.

// 1.  Assume ‘0’ as the invalid number and all others as a valid number.

// 2.  The sequence of the valid numbers is present in the same order.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> modifyAndRearrangeArray(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != 0 && arr[i] == arr[i + 1]) {
                arr[i] = 2 * arr[i];  
                arr[i + 1] = 0;       
            }
        }

        int nonZeroIndex = 0; 
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[nonZeroIndex++] = arr[i];
            }
        }

        while (nonZeroIndex < n) {
            arr[nonZeroIndex++] = 0;
        }

        return arr;
    }
};

int main() {
   int t;
   cin>>t;
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) arr.push_back(number);

        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
}