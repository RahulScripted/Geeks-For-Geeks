// Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring. A parenthesis string is valid if:

// For every opening parenthesis, there is a closing parenthesis.
// The closing parenthesis must be after its opening parenthesis.






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(string& s) {
        int maxLen = 0;

        int open = 0, close = 0;
        for (char ch : s) {
            if (ch == '(') open++;
            else if (ch == ')') close++;
    
            if (open == close) maxLen = max(maxLen, 2 * close);
            else if (close > open) open = close = 0;
        }
    
        open = close = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') open++;
            else if (s[i] == ')') close++;
    
            if (open == close) maxLen = max(maxLen, 2 * open);
            else if (open > close) open = close = 0;
        }

        return maxLen;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~" << "\n";
    }
    return 0;
}