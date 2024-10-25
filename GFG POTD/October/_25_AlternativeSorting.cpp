// Given an array arr of distinct integers. Rearrange the array in such a way that the first element is the largest and the second element is the smallest, the third element is the second largest and the fourth element is the second smallest, and so on.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> alternateSort(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int n = arr.size();
        vector<int> ans(n);

        int left = 0, right = n - 1;
        bool highTurn = true;

        for (int k = 0; k < n; ++k) {
            if (highTurn) ans[k] = arr[right--];
            else ans[k] = arr[left++];
            highTurn = !highTurn; 
        }

        return ans;
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
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}