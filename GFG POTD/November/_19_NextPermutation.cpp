// Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverse(vector<int>& arr, int l, int r) {
    while (l < r)
        swap(arr[l++], arr[r--]);
    }
    
    void nextPermutation(vector<int>& arr) {
        const int n = arr.size();
        int i;
        for (i = n - 2; i >= 0; --i){
            if (arr[i] < arr[i + 1]) break;
        }

        if (i >= 0)
        for (int j = n - 1; j > i; --j){
            if (arr[j] > arr[i]) {
                swap(arr[i], arr[j]);
                break;
            }
        }

        reverse(arr, i + 1, n - 1);
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}