// Given a square matrix[][]. The task is to rotate it by 90 degrees in clockwise direction without using any extra space.





#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    // Transpose
    for(int i = 0;i < n;i++){
        for(int j = (i + 1);j < n;j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    // Reverse
    for(int k = 0;k < n;k++){
        int i = 0,j = (n - 1);
        while(i <= j){
            int temp = matrix[k][i];
            matrix[k][i] = matrix[k][j];
            matrix[k][j] = temp;
            i++;
            j--;
        }
    }
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}