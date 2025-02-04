// Given a binary tree, convert the binary tree to its Mirror tree.





#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
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

string levelOrder(Node *root) {
    if (root == nullptr)
        return "N\n";

    string str;
    queue<Node *> qq;
    qq.push(root);

    while (!qq.empty()) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            str += "N ";
            continue;
        }
        str += (to_string(curr->data) + " ");
        qq.push(curr->left);
        qq.push(curr->right);
    }
    while (!str.empty() && !isdigit(str.back())) {
        str.pop_back();
    }
    return str;
}

class Solution {
  public:
    void mirror(Node* node) {
        if (node == nullptr) return ;
        mirror(node->left);
        mirror(node->right);
        swap(node->left, node->right);
    }
};

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        ob.mirror(root);
        cout << levelOrder(root);
        cout << "\n";
        cout << "~\n";
    }
}