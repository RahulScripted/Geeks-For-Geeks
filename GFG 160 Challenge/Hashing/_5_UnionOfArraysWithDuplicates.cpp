// Given two arrays a[] and b[], the task is to find the number of elements in the union between these two arrays.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int>s;
        for(int i = 0;i < a.size();i++){
            s.insert(a[i]);
        }
        for(int i = 0;i < b.size();i++){
            s.insert(b[i]);
        }
        return s.size();
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> a;
        vector<int> b;

        string input;
        // For a
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // For b
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        cout << ob.findUnion(a, b) << endl;
        cout << '~' << endl;
    }

    return 0;
}