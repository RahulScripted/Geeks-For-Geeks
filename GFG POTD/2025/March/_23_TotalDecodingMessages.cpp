// A message containing letters A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26

// You are given a string digits. You have to determine the total number of ways that message can be decoded.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countWays(string &digits) {
        int n = digits.length();
        if (n == 0 || digits[0] == '0') return 0;
        int prev1 = 1, prev2 = 0;
    
        for (int i = 1; i <= n; ++i){
            int current = 0;
            if (digits[i - 1] != '0') current += prev1;
    
            if (i > 1){
                int twoDigit = (digits[i - 2] - '0') * 10 + (digits[i - 1] - '0');
                if (twoDigit >= 10 && twoDigit <= 26) current += prev2;
            }
    
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~" << "\n";
    }
}