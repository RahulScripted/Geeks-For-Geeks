// The n-queens puzzle is the problem of placing n queens on a (n x n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal. Given an integer n, find all distinct solutions to the n-queens puzzle. You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nQueenUtil(int j, int n, vector<int> &board, vector<bool> &rows,  vector<bool> &diag1, vector<bool> &diag2, vector<vector<int>> &res) {
    
        if (j > n) {
            res.push_back(board);
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (!rows[i] && !diag1[i + j] && !diag2[i - j + n]) {
                rows[i] = diag1[i + j] = diag2[i - j + n] = true;
                board.push_back(i);
    
                nQueenUtil(j + 1, n, board, rows, diag1, diag2, res);
                board.pop_back();
                rows[i] = diag1[i + j] = diag2[i - j + n] = false;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> board;
    
        vector<bool> rows(n + 1, false);
        vector<bool> diag1(2 * n + 1, false);
        vector<bool> diag2(2 * n + 1, false);
        nQueenUtil(1, n, board, rows, diag1, diag2, res);
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~" << "\n";
    }
}