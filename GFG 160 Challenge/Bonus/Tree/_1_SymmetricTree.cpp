// Given a root of a Binary Tree. Your task is to check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself.






#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

class Node {
  public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
    bool checkIsSymmetric(Node* leftSub, Node* rightSub) {
        if(leftSub == nullptr && rightSub == nullptr) return true;
        if(leftSub == nullptr || rightSub == nullptr || leftSub -> data != rightSub -> data) return false;
        return checkIsSymmetric (leftSub -> left, rightSub -> right) && checkIsSymmetric(leftSub -> right,rightSub -> left);
    }
    
    bool isSymmetric(Node* root) {
        if(root == nullptr) return true;
        return checkIsSymmetric(root -> left,root -> right);
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);

        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        if (ob.isSymmetric(root)) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }

        cout << "~" << "\n";
    }
    return 0;
}