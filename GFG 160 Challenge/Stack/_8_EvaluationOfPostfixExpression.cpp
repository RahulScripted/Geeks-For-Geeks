// You are given an array of strings arr that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

// Key Details:

// 1.   The valid operators are '+', '-', '*', and '/'.

// 2.   Each operand is guaranteed to be a valid integer or another expression.

// 3.   The division operation between two integers always rounds the result towards zero, discarding any fractional part.

// 4.   No division by zero will occur in the input.

//  5.  The input is a valid arithmetic expression in Reverse Polish Notation.

// 6.   The result of the expression and all intermediate calculations will fit in a 32-bit signed integer.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;

        for (string token : arr) {
            if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
                st.push(stoi(token));
            } 
            
            else {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
    
                if (token == "+") {
                    st.push(val2 + val1);
                } 
                else if (token == "-") {
                    st.push(val2 - val1);
                } 
                else if (token == "*") {
                    st.push(val2 * val1);
                } 
                else if (token == "/") {
                    st.push(val2 / val1);
                }
            }
        }
        return st.top();
    }
};

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}