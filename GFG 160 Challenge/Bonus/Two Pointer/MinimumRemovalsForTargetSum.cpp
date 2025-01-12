// You are given an array of positive integers arr[] and an integer k. In one operation, you can remove either the leftmost or the rightmost element from the array. After each operation, the size of arr[] will be reduced by one. Your task is to determine the minimum number of operations required to make the total sum of removed elements exactly equal to k. If it is not possible to achieve this, return -1.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minRemovals(vector<int> &arr, int k) {
        int total = 0, n = arr.size();
        for(int num : arr) total += num;
        int target = total - k;
        if(target == 0) return n;
        int left = 0, currSum = 0,maxLen = -1;
        
        for(int right = 0;right < n;right++){
            currSum += arr[right];
            while(left < right && currSum > target) currSum -= arr[left++];
            if(currSum == target) maxLen = max(maxLen,right - left + 1);
        }
        return maxLen == -1 ? -1 : (n - maxLen);
    }
};

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr = inputLine();
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        int ans = obj.minRemovals(arr, k);
        cout << ans << endl;
    }
}