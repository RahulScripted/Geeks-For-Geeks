// Given a string s with repeated characters, the task is to rearrange characters in a string such that no two adjacent characters are the same.





#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

class Solution {
  public:
    string rearrangeString(string s) {
        unordered_map<char,int> freq;
        for(char c : s) freq[c]++;
        
        priority_queue<pair<int,char>>maxHeap;
        for(auto it : freq){
            maxHeap.push({it.second, it.first});
        }
        
        string result = "";
        pair<int, char> prev = {-1, '#'};
        while(!maxHeap.empty()){
            pair<int, char> current = maxHeap.top();
            maxHeap.pop();
            result += current.second;
            
            if(prev.first > 0) maxHeap.push(prev);
            prev = {current.first - 1, current.second};
        }
        
        return result.size() == s.size() ? result : "";
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        string str1 = ob.rearrangeString(str);
        int flag = 1;
        int c[26] = {0};
        for (int i = 0; i < str.length(); i++)
            c[str[i] - 'a'] += 1;
        int f = 0;
        int x = (str.length() + 1) / 2;
        for (int i = 0; i < 26; i++) {
            if (c[i] > x)
                f = 1;
        }
        if (f) {
            if (str1 == "")
                cout << 0 << endl;
            else
                cout << 1 << endl;
        } else {
            int a[26] = {0};
            int b[26] = {0};
            for (int i = 0; i < str.length(); i++)
                a[str[i] - 'a'] += 1;
            for (int i = 0; i < str1.length(); i++)
                b[str1[i] - 'a'] += 1;

            for (int i = 0; i < 26; i++)
                if (a[i] != b[i])
                    flag = 0;

            for (int i = 0; i < str1.length(); i++) {
                if (i > 0)
                    if (str1[i - 1] == str1[i])
                        flag = 0;
            }
            if (flag == 1)
                cout << "1\n";
            else
                cout << "0\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}