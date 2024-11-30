// Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other. Strings s1 and s2 can only contain lowercase alphabets.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // Map
        if(s1.length() != s2.length()) return false;
        unordered_map<char,int>mp;
        for(int i = 0;i < s1.length();i++) mp[s1[i]]++;
        
        for(int i = 0;i < s2.length();i++){
            if(mp.find(s2[i]) != mp.end()){
                if(mp[s2[i]] > 0) mp[s2[i]]--;
                else return false;
            }
            else return false;
        }
        return true;
        
        // Approach 2 -> Using 2 HashMap
        // unordered_map<char,int>mp1;
        // unordered_map<char,int>mp2;

        // for(int i = 0;i < s.length();i++) mp1[s[i]]++;
        // for(int i = 0;i < t.length();i++) mp2[t[i]]++;

        // for(auto p : mp1){
        //     char ch1 = p.first;
        //     int freq1 = p.second;
        //     if(mp2.find(ch1) != mp2.end()){
        //         int freq2 = mp2[ch1];
        //         if(freq1 == freq2) continue;
        //         else return false;
        //     }
        //     else return false;
        // }
        // return true;
        
        // sorting
        // sort(s1.begin(),s1.end());
        // sort(s2.begin(),s2.end());
        // return s1 == s2;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d)) cout << "true" << endl;
        else cout << "false" << endl;
        cout << "~" << endl;
    }
}