// Given an incomplete Sudoku configuration in terms of a 9x9  2-D integer square matrix, mat[][], the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution. A sudoku solution must satisfy all of the following rules:

// 1.  Each of the digits 1-9 must occur exactly once in each row.

// 2.  Each of the digits 1-9 must occur exactly once in each column.

// 3.  Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSafe(vector<vector<int>> &mat, int row, int col, int num) {
        for (int x = 0; x <= 8; x++){
            if (mat[row][x] == num) return false;
        }
    
        for (int x = 0; x <= 8; x++){
            if (mat[x][col] == num) return false;
        }
        
        int startRow = row - (row % 3), startCol = col - (col % 3);
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (mat[i + startRow][j + startCol] == num) return false;
            }
        }
        return true;
    }
    
    bool solveSudokuRec(vector<vector<int>> &mat, int row, int col) {
        int n = mat.size();
        if (row == n - 1 && col == n) return true;
    
        if (col == n) {
            row++;
            col = 0;
        }
        
        if (mat[row][col] != 0) return solveSudokuRec(mat, row, col + 1);
        for (int num = 1; num <= n; num++) {
            if (isSafe(mat, row, col, num)) {
                mat[row][col] = num;
                if (solveSudokuRec(mat, row, col + 1)) return true;
                mat[row][col] = 0;
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<int>> &mat) {
        solveSudokuRec(mat, 0, 0);
    }
};

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;
        ob.solveSudoku(grid);
        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
}