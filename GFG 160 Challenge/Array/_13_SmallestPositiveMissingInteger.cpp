// You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();

        // Step 1: Place each number in its correct position
        for (int i = 0; i < n; ++i) {
            while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Step 2: Find the first index where the value is not (index + 1)
        for (int i = 0; i < n; ++i) {
            if (arr[i] != i + 1) return i + 1;
        }
        
        return n + 1;
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}