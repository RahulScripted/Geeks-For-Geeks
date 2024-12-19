// Given two sorted arrays a[] and b[], . You need to find and return the median of the combined array after merging them into a single sorted array.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
    
        if (n > m) return medianOf2(b, a);
      
        int lo = 0, hi = n;
        while (lo <= hi) {
            int mid1 = (lo + hi) / 2;
            int mid2 = (n + m + 1) / 2 - mid1;
    
            int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
            int r1 = (mid1 == n ? INT_MAX : a[mid1]);
    
            int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
            int r2 = (mid2 == m ? INT_MAX : b[mid2]);
            
            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 == 0) return (max(l1, l2) + min(r1, r2)) / 2.0;
                else return max(l1, l2);
            }
            if (l1 > r2) hi = mid1 - 1;
            else lo = mid1 + 1;
        }
        return 0;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string line1;
        getline(cin, line1);
        stringstream ss1(line1);

        vector<int> array1;
        int num;
        while (ss1 >> num) array1.push_back(num);

        string line2;
        getline(cin, line2);
        stringstream ss2(line2);

        vector<int> array2;
        while (ss2 >> num) array2.push_back(num);

        Solution ob;
        if (array2.size() == 1 && array2[0] == 0) array2.pop_back();

        double ans = ob.medianOf2(array1, array2);
        if (ans == (int)ans) cout << (int)ans << endl;
        else cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}