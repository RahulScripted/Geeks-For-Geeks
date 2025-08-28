// Given a string s, find if it is divisible by 13 or not.



#include <iostream>
#include <string>
using namespace std; 

class Solution {
public:
    bool isDivisibleBy13(const string& s) {
        int num = 0;
        for (char c : s) {
            if (!isdigit(c)) return false;
            num = (num * 10 + (c - '0')) % 13;
        }
        return num == 0;
    }
}; 

int main() {
    Solution sol;
    string s;
    cout << "Enter a number as a string: ";
    cin >> s;

    if (sol.isDivisibleBy13(s)) 
        cout << s << " is divisible by 13." << endl;
    else 
        cout << s << " is not divisible by 13." << endl;
}