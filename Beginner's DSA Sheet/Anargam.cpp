// Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other. Strings a and b can only contain lowercase alphabets.




#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isAnagram(string a, string b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a == b;
    }
};

int main(){
    Solution solve;

    // 1st example
    string a = "geeksforgeeks";
    string b = "forgeeksgeeks";
    if(solve.isAnagram(a,b)) cout<<"It's a valid anargam"<<endl;
    else cout<<"It's not a valid anargam"<<endl;
}