// Given an array arr[] of integers, the task is to count the number of ways to split given array elements into two non-empty subsets such that the XOR of elements of each group is equal. Each element should belong to exactly one subset.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int power(int x, int y, int p) {
        int result = 1;
        x = x % p;
        while (y > 0) {
            if (y & 1) result = (result * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return result;
    }

    int countgroup(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        int xs = 0;
        for (int num : arr) xs ^= num;

        if (xs == 0) return (power(2, n - 1, mod) - 1 + mod) % mod;
        return 0;
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
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}