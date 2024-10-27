// Given an array arr consisting of positive integers numbers, remove all duplicates numbers.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        unordered_set<int> seen;  
        vector<int> result;
    
        for (int num : arr) {
            if (seen.find(num) == seen.end()) { 
                seen.insert(num); 
                result.push_back(num);  
            }
        }
    
        return result;
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
        vector<int> ans = obj.removeDuplicate(arr);
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}