// Given an array of distinct positive numbers, the task is to calculate the minimum number of subsets (or subsequences) from the array such that each subset contains consecutive numbers.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int numOfSubset(vector<int> &arr) {
        unordered_set<int> s(arr.begin(),arr.end());
        int count = 0;
        for(int x : arr){
            if(s.find(x - 1) == s.end()){
                int j = x;
                while(s.find(j) != s.end()) j++;
                count++;
            }
        }
        return count;
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.numOfSubset(nums) << endl; 
    }
    return 0;
}