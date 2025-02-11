// Given the root of a binary tree. Check whether it is a BST or not.





#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    bool isBST(Node* root) {
        Node* curr = root;
        Node* pre = nullptr;
        int prevValue = INT_MIN; 
    
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                if (curr->data <= prevValue) return false;
                prevValue = curr->data;
                curr = curr->right;
            } 
            else {
                pre = curr->left;
                while (pre->right != nullptr && pre->right != curr) {
                    pre = pre->right;
                }
    
                if (pre->right == nullptr) {
                    pre->right = curr;
                    curr = curr->left;
                } 
                else {
                    pre->right = nullptr;
                    if (curr->data <= prevValue) return false;
                    prevValue = curr->data;
                    curr = curr->right;
                }
            }
        }
    
        return true; 
    }
};

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        if (ob.isBST(root)) cout << "true\n";
        else cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}