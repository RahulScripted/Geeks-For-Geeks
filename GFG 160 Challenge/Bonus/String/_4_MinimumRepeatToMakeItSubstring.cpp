// Given two strings s1 and s2. Return a minimum number of times s1 has to be repeated such that s2 is a substring of it. If s2 can never be a substring then return -1.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        string repeatedS1 = s1;
        int count = 1;
        while (repeatedS1.length() < s2.length()) {
            repeatedS1 += s1;
            count++;
        }
    
        if (repeatedS1.find(s2) != std::string::npos) return count;
        repeatedS1 += s1;
        count++;
        if (repeatedS1.find(s2) != string::npos) return count;
        return -1;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}