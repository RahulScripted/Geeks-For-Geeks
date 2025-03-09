// Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2. 






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;
      
        for (int i = 0; i < s.size(); i++) {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 and right < n) {
                if (s[left] == s[right]) count++;
                else break;
                left--;
                right++;
            }
        }
    
        for (int i = 0; i < s.size(); i++) {
            int left = i;
            int right = i + 1;
            while (left >= 0 and right < n) {
                if (s[left] == s[right]) count++;
                else break;
                left--;
                right++;
            }
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}