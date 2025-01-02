// Given an array arr[] and an integer target, you need to find and return the count of quadruplets such that the index of each element of the quadruplet is unique and the sum of the elements is equal to target.






#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int countSum(vector<int>& arr, int target) {
        int n = arr.size();
        int count = 0;
        unordered_map<int,int>freq;
        for(int i = 0;i < (n - 1);i++){
            for(int j = (i + 1);j < n;j++){
                int temp = arr[i] + arr[j];
                count += freq[target - temp];
            }
            for(int j = 0;j < i;j++){
                int temp = arr[i] + arr[j];
                freq[temp]++;
            }
        }
        return count;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string input;
        getline(std::cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        while (iss >> num) arr.push_back(num);

        int k;
        cin >> k;
        cin.ignore();

        Solution solution;
        int ans = solution.countSum(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}