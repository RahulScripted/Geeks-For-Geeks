// Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string trimLeadingZeros(const string &s) {
        size_t firstOne = s.find('1');
        return (firstOne == string::npos) ? "0" : s.substr(firstOne);
    }
    
    string addBinary(string& s1, string& s2) {
        string res = "";
        s1 = trimLeadingZeros(s1);
        s2 = trimLeadingZeros(s2);
      
        int n = s1.size();  
        int m = s2.size(); 
        if (n < m) return addBinary(s2, s1);
        
        int j = m - 1;  
        int carry = 0; 
        for (int i = n - 1; i >= 0; i--) {
            int bit1 = s1[i] - '0';  
            int sum = bit1 + carry;
            if (j >= 0) {
                int bit2 = s2[j] - '0';  
                sum += bit2;
                j--;
            }
            int bit = sum % 2;
            carry = sum / 2;
            s1[i] = (char)(bit + '0');
        }
        if (carry > 0) s1 = '1' + s1;
        return s1;   
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}