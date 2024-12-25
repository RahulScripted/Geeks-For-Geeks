// You are given two positive integers n and m, and an integer array arr[] containing total (n*m) elements. Return a 2D matrix of dimensions n x m by filling it in a clockwise spiral order using the elements from the given array.





#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Solution {
  public:
    vector<vector<int>> spiralFill(int n, int m, vector<int> &arr) {
        vector<vector<int>> res(n, vector<int>(m, 0));

        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        int index = 0;
    
        while (index < arr.size()) {
            for (int j = left; j <= right; j++) {
                res[top][j] = arr[index++];
            }
            top++;
    
            for (int i = top; i <= bottom; i++) {
                res[i][right] = arr[index++];
            }
            right--;
    
            if(top <= bottom) {
                for (int j = right; j >= left; j--) {
                    res[bottom][j] = arr[index++];
                }
                bottom--;
            }
    
            if(left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res[i][left] = arr[index++];
                }
                left++;
            }
        }
    
        return res;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int m;
        scanf("%d", &m);

        vector<int> arr(n * m);
        Array::input(arr, n * m);

        Solution obj;
        vector<vector<int>> res = obj.spiralFill(n, m, arr);

        Matrix::print(res);
    }
}