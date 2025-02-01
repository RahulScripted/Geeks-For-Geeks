// Given a root of a binary tree with n nodes, the task is to find its level order traversal. Level order traversal of a tree is breadth-first traversal for the tree.





#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

class Solution {
  public:
    void levelOrderRec(Node* root, int level, vector<vector<int>>& res) {
        if (root == nullptr) return; 
        if (res.size() <= level) res.push_back({});
        
        res[level].push_back(root->data);
        levelOrderRec(root->left, level + 1, res);
        levelOrderRec(root->right, level + 1, res);
    }
    
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        levelOrderRec(root, 0, res);
        return res;
    }
};

void inOrder(Node* node) {
    if (node == nullptr)
        return;

    inOrder(node->left);
    printf("%d ", node->data);

    inOrder(node->right);
}

// Function to Build Tree
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return nullptr;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<vector<int>> res = ob.levelOrder(root);
        for (auto level : res) {
            for (int ele : level)
                cout << ele << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
}