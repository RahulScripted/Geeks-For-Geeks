// Given a binary tree, determine if it is height-balanced. A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.





#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(string str) {
    if (str.empty() || str[0] == 'N')
        return nullptr;

    vector<string> nodeValues;
    istringstream iss(str);
    for (string s; iss >> s;)
        nodeValues.push_back(s);

    Node* root = new Node(stoi(nodeValues[0]));
    queue<Node*> nodeQueue;
    nodeQueue.push(root);

    size_t i = 1;
    while (!nodeQueue.empty() && i < nodeValues.size()){
        Node* currentNode = nodeQueue.front();
        nodeQueue.pop();

        string leftValue = nodeValues[i++];
        if (leftValue != "N") {
            currentNode->left = new Node(stoi(leftValue));
            nodeQueue.push(currentNode->left);
        }

        if (i >= nodeValues.size())
            break;

        string rightValue = nodeValues[i++];
        if (rightValue != "N") {
            currentNode->right = new Node(stoi(rightValue));
            nodeQueue.push(currentNode->right);
        }
    }
    return root;
}

class Solution {
  public:
    int isBalancedRec (Node* root){
        if(root == NULL) return 0;  
        
        int lHeight = isBalancedRec(root -> left);
        int rHeight = isBalancedRec(root -> right);
        
        if(lHeight == -1 || rHeight == -1 || abs(lHeight - rHeight) > 1) return -1;
        return max(lHeight,rHeight) + 1;
    }
    
    bool isBalanced(Node* root) {
        return (isBalancedRec(root) > 0);
    }
};

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore(); 

    while (testCases--) {
        string treeInput;
        getline(cin, treeInput);

        Node* root = buildTree(treeInput);
        Solution solution;
        bool result = solution.isBalanced(root);

        // Output "true" or "false"
        cout << (result ? "true" : "false") << endl;
        cout << "~" << endl;
    }
}