// Given two sorted arrays a[] and b[] in non-decreasing order. Merge them in sorted order without using any extra space. Modify a so that it contains the first n elements and modify b so that it contains the last m elements.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();
        int res = (n1 + n2 + 1) / 2;

        while (res > 0) {
            int i = 0, j = res;
            while (j < n1 + n2) {
                if (j < n1 && a[i] > a[j]) swap(a[i], a[j]);
                else if (i < n1 && j >= n1 && a[i] > b[j - n1]) swap(a[i], b[j - n1]);
                else if (i >= n1 && b[i - n1] > b[j - n1]) swap(b[i - n1], b[j - n1]);
                i++;
                j++;
            }
            if (res == 1) break;
            res = (res + 1) / 2;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t; 

    while (t--) {
        vector<int> a, b;
        string arr1;
        getline(cin >> ws, arr1);
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}