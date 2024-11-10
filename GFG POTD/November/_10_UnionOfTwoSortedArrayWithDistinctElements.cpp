// Given two sorted arrays a[] and b[], where each array contains distinct elements , the task is to return the elements in the union of the two arrays in sorted order.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        vector<int> unionResult;
    
        while (i < a.size() && j < b.size()) {
            if (i > 0 && a[i] == a[i - 1]) {
                i++;
                continue;
            }
            if (j > 0 && b[j] == b[j - 1]) {
                j++;
                continue;
            }
    
            // Add the smaller element to the union and move the pointer
            if (a[i] < b[j]) {
                unionResult.push_back(a[i]);
                i++;
            } 
            else if (a[i] > b[j]) {
                unionResult.push_back(b[j]);
                j++;
            } 
            else {  // a[i] == b[j], add one of them and move both pointers
                unionResult.push_back(a[i]);
                i++;
                j++;
            }
        }
    
        // Add remaining elements of array a, if any
        while (i < a.size()) {
            if (i == 0 || a[i] != a[i - 1]) unionResult.push_back(a[i]);
            i++;
        }
    
        // Add remaining elements of array b, if any
        while (j < b.size()) {
            if (j == 0 || b[j] != b[j - 1]) unionResult.push_back(b[j]);
            j++;
        }
    
        return unionResult;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}