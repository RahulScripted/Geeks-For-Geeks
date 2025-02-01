// Given a string s containing only digits, your task is to restore it by returning all possible valid IP address combinations. You can return your answer in any order. A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255(inclusive).





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string &s){
        int n = s.size();
        if(n == 1) return true;
        int val = stoi(s);
        if(s[0] == '0' || val > 255) return false;
        return true;
    }
    
    void generateIpRec(string &s, int index, string curr, int cnt, vector<string> &res){
        string temp = "";
        if(index >= s.size()) return;
        if(cnt == 3){
            temp = s.substr(index);
            if(temp.size() <=3 && isValid(temp)) res.push_back(curr + temp);
            return;
        }
        
        for(int i = index; i < min(index + 3, (int)s.size()); i++){
            temp += s[i];
            if(isValid(temp)) generateIpRec(s, (i + 1), curr + temp + '.', cnt + 1, res);
        }
    }
    
    vector<string> generateIp(string s) {
        vector<string> res;
        generateIpRec(s,0,"",0,res);
        return res;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        Solution obj;
        vector<string> str = obj.generateIp(s);
        sort(str.begin(), str.end());
        if (str.size() == 0) cout << -1 << "\n";
        else {
            for (auto &u : str) {
                cout << u << "\n";
            }
        }

        cout << "~" << "\n";
    }
}