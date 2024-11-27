// You are given a positive integer n, you need to add all the digits of n and create a new number. Perform this operation until the resultant number has only one digit in it. Return the final number obtained after performing the given operation.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int singleDigit(int n) {
        if(n % 9 == 0) return 9;
        else return (n % 9);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.singleDigit(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
}