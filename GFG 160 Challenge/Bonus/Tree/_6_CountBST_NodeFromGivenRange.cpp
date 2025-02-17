// Given a Binary Search Tree (BST) and a range l-h (inclusive), your task is to return the number of nodes in the BST whose value lie in the given range.





#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
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
    int getCount(Node *root, int l, int h) {
        if(root == nullptr) return 0;
        
        if(root -> data <= h && root -> data >= l){
            return 1 + getCount(root -> left,l,h) + getCount(root -> right,l,h);
        }
        
        else if (root -> data < l) return getCount(root -> right,l,h);
        else  return getCount(root -> left,l,h);
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin >> ws, s);
        int l, r;
        cin >> l >> r;
        Solution ob;
        Node* root = buildTree(s);
        cout << ob.getCount(root, l, r) << endl;
        cout << "~" << "\n";
    }
    return 1;
}