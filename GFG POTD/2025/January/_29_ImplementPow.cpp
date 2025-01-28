// Implement the function power(b, e), which calculates b raised to the power of e (i.e. be).





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double power(double b, int e) {
        return pow(b,e);
    }
};

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }
}