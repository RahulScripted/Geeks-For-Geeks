// Given an unsorted array arr and a number k which is smaller than size of the array. Find if the array contains duplicates within k distance.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_set<int> window;
    
        for (int i = 0; i < arr.size(); i++) {
            if (window.find(arr[i]) != window.end()) return true;
            window.insert(arr[i]);
            if (window.size() > k) window.erase(arr[i - k]);
        }
        
        return false;
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) arr.push_back(number);

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res) cout << "true" << endl;
        else cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}