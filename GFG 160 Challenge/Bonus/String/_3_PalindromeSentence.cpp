// Given a single string s, the task is to check if it is a palindrome sentence or not. A palindrome sentence is a sequence of characters, such as word, phrase, or series of symbols that reads the same backward as forward after converting all uppercase letters to lowercase and removing all non-alphanumeric characters.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool sentencePalindrome(string &s) {
        int n = s.length();
        int i = 0,j = (n - 1);
        while(i < j){
            if(!isalnum(s[i])) i++;
            else if(!isalnum(s[j])) j--;
            else if(tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        if (ob.sentencePalindrome(s)) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}