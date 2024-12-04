// Given a dictionary of words arr[] where each word follows CamelCase notation, print all words in the dictionary that match with a given pattern pat consisting of uppercase characters only. CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins with a capital letter. Common examples include PowerPoint and Wikipedia, GeeksForGeeks, CodeBlocks, etc.





#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<string> camelCase(vector<string> &arr, string &pat) {
        vector<string> res;
        for (string word : arr) {
            int i = 0, j = 0;
            while (i < word.length() && j < pat.length()) {
                if (islower(word[i])) i++;
                else if (word[i] != pat[j]) break;
                else {
                    i++;
                    j++;
                }
            }
            if (j == pat.length()) res.push_back(word);
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Clear the buffer after reading t
    while (t--) {
        string input;
        vector<string> arr;

        // Read the line of words
        getline(cin, input);
        stringstream ss(input);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        string pat;
        cin >> pat;
        cin.ignore(); 

        Solution ob;
        vector<string> ans = ob.camelCase(arr, pat);
        if (ans.empty()) {
            cout << "[]\n";
        } else {
            sort(ans.begin(), ans.end());
            for (const auto& u : ans)
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}