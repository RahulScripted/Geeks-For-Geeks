// Given an array arr[], the task is to find the maximum distance between two occurrences of an element. If no element has two occurrences, then return 0.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int,int>mp;
        int res = 0, n = arr.size();
        for(int i = 0;i < n;i++){
            if(mp.find(arr[i]) == mp.end()) mp[arr[i]] = i;
            else res = max(res,i - mp[arr[i]]);
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

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}