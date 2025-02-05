// Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.





#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root) {
    if (root == NULL) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

class Solution {
  public:
    Node *buildTreeRecur(unordered_map<int,int> &mp, vector<int> &preorder, int &preIndex, int left, int right) {

        if (left > right) return nullptr;
        int rootVal = preorder[preIndex];
        preIndex++;
    
        Node *root = new Node(rootVal);
        int index = mp[rootVal];
        root->left = buildTreeRecur(mp, preorder, preIndex, left, index - 1);
        root->right = buildTreeRecur(mp, preorder, preIndex, index + 1, right);
    
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int,int> mp;
        for (int i = 0; i < inorder.size(); i++)  mp[inorder[i]] = i;
      
        int preIndex = 0;
        Node *root = buildTreeRecur(mp, preorder, preIndex, 0, inorder.size() - 1);
    
        return root;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num) inorder.push_back(num);

        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num) preorder.push_back(num);
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}