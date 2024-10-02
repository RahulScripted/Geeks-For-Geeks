// Given an array arr integers. Assume sz to be the initial size of the array. Do the following operations exactly sz/2 times. In every kth (1<= k <= sz/2 ) operation:

// 1.  Right-rotate the array clockwise by 1.

// 2.  Delete the (n– k + 1)th element from begin.

// Now, Return the first element of the array.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rotateDelete(vector<int> &arr) {
        int i = 1;
        int n = arr.size();
        while (i < (n / 2) + 1) {
            rotate(arr.begin(), arr.end() - 1, arr.end());
            arr.erase(arr.begin() + (arr.size() - i));
            i++;
        }
        return arr[0];
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1,2,3,4,5,6};    
    cout << obj.rotateDelete(arr) << endl;
}