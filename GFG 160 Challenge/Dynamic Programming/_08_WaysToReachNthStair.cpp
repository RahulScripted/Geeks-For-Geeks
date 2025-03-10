// There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Your task is to count the number of ways, the person can reach the top (order does matter).




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countWays(int n) {
        int temp1 = 1, temp2 = 1;
        for(int i = 1; i< n;i++){
            int temp = temp1 + temp2;
            temp1 = temp2;
            temp2 = temp;
        }
        return temp2;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl;
        cout << "~" << "\n";
    }
    return 0;
}