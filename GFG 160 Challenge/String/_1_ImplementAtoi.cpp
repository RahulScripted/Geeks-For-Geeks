// Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function. Cases for atoi() conversion:

// 1.  Skip any leading whitespaces.

// 2.  Check for a sign ('+' or '-'), default to positive if no sign is present.

// 3.  Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.

// 4.  If the integer is greater than 2^31 – 1, then return 2^31 – 1 and if the integer is smaller than -2^31, then return -2^31.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int myAtoi(char *s) {
        int sign = 1, res = 0, idx = 0;

        while (s[idx] == ' ') idx++;
        if (s[idx] == '-' || s[idx] == '+') {
            if(s[idx++] == '-')
            sign = -1;
        }
    
        while (s[idx] >= '0' && s[idx] <= '9') {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[idx] - '0' > 7)) return sign == 1 ? INT_MAX : INT_MIN;
            res = 10 * res + (s[idx++] - '0');
        }
        return res * sign;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}