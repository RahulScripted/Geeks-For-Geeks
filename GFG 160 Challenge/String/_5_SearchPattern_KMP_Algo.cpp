// Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void constructLps(string& pat,vector<int>&lps){
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while(i < pat.length()){
            if(pat[i] == pat[len]){
                len++;
                lps[i++] = len;
            }
            else{
                if(len != 0) len = lps[len - 1];
                else{
                    lps[i++] = 0;
                }
            }
        }
    }
    
    vector<int> search(string& pat, string& txt) {
        int m = pat.length(),n = txt.length();
        vector<int>lps(m);
        vector<int>res;
        constructLps(pat,lps);
        
        int i = 0, j = 0;
        while(i < n){
            if(txt[i] == pat[j]){
                i++;
                j++;
                if(j == m){
                    res.push_back(i - j);
                    j = lps[j - 1];
                }
            }
            else{
                if(j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0) cout << "[]" << endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}