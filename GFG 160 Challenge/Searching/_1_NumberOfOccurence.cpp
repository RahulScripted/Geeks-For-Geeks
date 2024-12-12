// Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int count = 0;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            if(arr[i] == target) count++;
        }
        return count;
    }
};

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) arr.push_back(number);

        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~" << "\n";
    }
    return 0;
}