// Given a binary array arr[] (containing only 0s and 1s) and an integer k, you are allowed to flip at most k 0s to 1s. Find the maximum number of consecutive 1's that can be obtained in the array after performing the operation at most k times.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int res = 0;
        int start = 0, end = 0; 
        int cnt = 0;
        
        while (end < arr.size()) {
            if (arr[end] == 0) cnt++;
            while (cnt > k) {
                if (arr[start] == 0) cnt--;
                start++;
            }
            
            res = max(res, (end - start + 1));
            end++; 
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
        int m;
        cin >> m;
        cin.ignore();

        Solution obj;
        int ans = obj.maxOnes(arr, m);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}