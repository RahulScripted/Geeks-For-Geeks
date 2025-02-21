// Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', verify the validity of the arrangement. An input string is valid if:

// 1. Open brackets must be closed by the same type of brackets.

// 2. Open brackets must be closed in the correct order.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
          
            else {
                if (!st.empty() && 
                    ((st.top() == '(' && s[i] == ')') ||
                     (st.top() == '{' && s[i] == '}') ||
                     (st.top() == '[' && s[i] == ']'))) {
    
                    // Pop the matching opening bracket
                    st.pop(); 
                }
                else return false;
            }
        }
        
        return st.empty();
    }
};

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~" << "\n";
    }
}