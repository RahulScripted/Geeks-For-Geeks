// Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int floorSqrt(int n) {
        int res = exp(0.5 * log(n));
        if ((res + 1) * (res + 1) <= n) res++;
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}