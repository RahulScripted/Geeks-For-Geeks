// Given a binary array arr[] containing only 0s and 1s and an integer k, you are allowed to flip at most k 0s to 1s. Find the maximum number of consecutive 1's that can be obtained in the array after performing the operation at most k times.



#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int left = 0, right = 0;
        int zeroCount = 0, maxLen = 0;
    
        while (right < arr.size()) {
            if (arr[right] == 0) zeroCount++;
    
            while (zeroCount > k) {
                if (arr[left] == 0) zeroCount--;
                left++;
            }
    
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 0, 1, 1, 0, 0, 1, 1, 1, 0};
    int k = 2;
    cout << "Maximum number of consecutive 1's: " << sol.maxOnes(arr, k) << endl;
    return 0;
}