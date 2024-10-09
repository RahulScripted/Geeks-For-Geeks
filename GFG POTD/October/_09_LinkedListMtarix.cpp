// Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.





#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};


/*structure of the node of the linked list 

struct Node{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<Node*>> nodeMatrix(m, vector<Node*>(n, NULL));

        // Create Nodes
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nodeMatrix[i][j] = new Node(mat[i][j]);
            }
        }

        // Attach Nodes
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j < n - 1) {
                    nodeMatrix[i][j]->right = nodeMatrix[i][j + 1]; 
                }
                if (i < m - 1) {
                    nodeMatrix[i][j]->down = nodeMatrix[i + 1][j]; 
                }
            }
        }
        return nodeMatrix[0][0];
    }
};

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        while (ss >> num) nums.push_back(num);

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            while (ss >> num) nums.push_back(num);
            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) cout << "-1\n";
        else display(head);
        cout << "\n";
    }
    return 0;
}