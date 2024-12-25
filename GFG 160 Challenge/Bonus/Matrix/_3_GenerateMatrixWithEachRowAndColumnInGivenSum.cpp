// Given two integer arrays rowSum[] of size n and colSum[] of size m, the task is to construct a 2D matrix of size n x m such that the sum of matrix elements in ith row is rowSum[i] and the sum of matrix elements in jth column is colSum[j].





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> generateMatrix(vector<int> rowSum, vector<int> colSum) {
        vector<vector<int>> res(rowSum.size(), vector<int>(colSum.size()));

        for (int i = 0; i < rowSum.size(); i++) {
            for (int j = 0; j < colSum.size(); j++) {
                res[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }
    
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> rowSum, colSum;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            rowSum.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            colSum.push_back(number2);
        }
        Solution ob;
        vector<vector<int> > ans = ob.generateMatrix(rowSum, colSum);
        int n = ans.size(), m = ans[0].size();
        if (n != rowSum.size() || m != colSum.size()) {
            cout << "false\n";
            return 0;
        }
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (auto x : ans[i])
                s += x;
            if (s != rowSum[i]) {
                cout << "false" << endl;
                return 0;
            }
        }
        for (int j = 0; j < m; j++) {
            int s = 0;
            for (int i = 0; i < n; i++)
                s += ans[i][j];
            if (s != colSum[j]) {
                cout << "false" << endl;
                return 0;
            }
        }
        cout << "true" << endl;
        cout << "~\n";
    }
}