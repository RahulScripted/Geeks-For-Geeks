// Given an array arr of integers. Find whether three numbers are such that the sum of two elements equals the third element.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();

        // Sort the array for easy pair summation
        sort(arr.begin(), arr.end());
    
        // Iterate over each element as the 'third element'
        for (int i = n - 1; i >= 2; --i) {
            int left = 0;
            int right = i - 1;
    
            // Check if there exists two numbers whose sum is equal to arr[i]
            while (left < right) {
                int sum = arr[left] + arr[right];
                if (sum == arr[i]) return true;
                else if (sum < arr[i]) ++left;
                else --right;
            }
        }
        return false;
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) arr.push_back(number);

        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res) cout << "true" << endl;
        else cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}