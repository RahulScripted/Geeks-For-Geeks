// Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int maxi = INT_MIN;
        int prod = 1;

        for(int i = 0;i < n;i++){
            prod *= arr[i];
            maxi = max(prod,maxi);
            if(prod == 0) prod = 1;
        }
        
        prod = 1;
        for(int i = (n - 1);i >= 0;i--){
            prod *= arr[i];
            maxi = max(prod,maxi);
            if(prod == 0) prod = 1;
        }
        return maxi;
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
        while (ss >> number) arr.push_back(number);

        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~" << "\n";
    }
    return 0;
}