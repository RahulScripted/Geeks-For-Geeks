// A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int i = 0, j = (n - 1);
        
        while(i < j){
            if(mat[j][i] == 1) j--;
            else i++;
        }
        
        int c = i;
        for(i = 0;i < n;i++){
            if (i == c) continue;
            if(mat[c][i] || !mat[i][c]) return -1;
        }
        return c;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}