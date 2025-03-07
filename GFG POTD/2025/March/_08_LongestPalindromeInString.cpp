// Given a string s, your task is to find the longest palindromic substring within s. A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s). A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestPalindrome(string &s) {
        int n = s.length();
        if (n == 0) return "";
        int start = 0, maxLen = 1;
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 1; j++) {
                int low = i;
                int high = i + j; 
    
                while (low >= 0 && high < n && s[low] == s[high]) {
                    int currLen = high - low + 1;
                    if (currLen > maxLen) {
                        start = low;
                        maxLen = currLen;
                    }
                    low--;
                    high++;
                }
            }
        }
    
        return s.substr(start, maxLen);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~" << "\n";
    }
}