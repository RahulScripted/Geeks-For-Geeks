// You are given an array of words where each word consists of lowercase English letters. wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB. For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad". A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k = 1. Return the length of the longest possible word chain with words chosen from the given list of words in any order.




#include <bits/stdc++.h>
using namespace std;

bool static cmp(const string& a, const string& b) {
    return a.size() < b.size();
}

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);

        unordered_map<string, int> dp;
        int res = 1;
    
        for (const string& w : words) {
            dp[w] = 1;
            for (int i = 0; i < w.size(); ++i) {
                string pred = w.substr(0, i) + w.substr(i + 1);
                if (dp.find(pred) != dp.end()) {
                    dp[w] = max(dp[w], dp[pred] + 1);
                }
            }
          
            res = max(res, dp[w]);
        }
    
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~" << "\n";
    }
    return 0;
}