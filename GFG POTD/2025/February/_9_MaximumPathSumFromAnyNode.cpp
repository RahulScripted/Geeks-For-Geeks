// Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.





#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node *currNode = queue.front();
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

class Solution {
  public:
    int maxPathSumUtil(Node* root, int& res) {
        if (root == NULL) return 0;
        int l = max(0, maxPathSumUtil(root->left, res));
        int r = max(0, maxPathSumUtil(root->right, res));
        res = max(res, l + r + root->data);
        return root->data + max(l, r);
    }
    
    int findMaxSum(Node *root) {
        int res = root->data;
        maxPathSumUtil(root, res);
        return res;
    }
};

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        cout << ob.findMaxSum(root) << "\n";
        cout << "~" << "\n";
    }
    return 0;
}