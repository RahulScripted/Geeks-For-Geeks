// Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.





#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;

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

bool isBST(Node* n, int lower, int upper) {
    if (!n)
        return true;
    if (n->data <= lower || n->data >= upper)
        return false;
    return (isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper));
}

bool compare(Node* a, Node* b, vector<pair<int, int>>& mismatch) {
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;

    if (a->data != b->data)
        mismatch.push_back(pair<int, int>(a->data, b->data));

    return (compare(a->left, b->left, mismatch) &&
            compare(a->right, b->right, mismatch));
}

class Solution {
  public:
    void correct(Node* root, Node* &first, Node* &middle, Node* &last, Node* &prev) {
        if(root == nullptr) return;
        correct(root -> left,first,middle,last,prev);
        
        if(prev && root -> data < prev -> data){
            if(!first){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        
        correct(root -> right,first,middle,last,prev);
    }
    
    void correctBST(Node* root) {
        Node* first = nullptr;
        Node* middle = nullptr;
        Node* last = nullptr;
        Node* prev = nullptr;
        correct(root,first,middle,last,prev);
        
        if(first && last) swap(first -> data, last -> data);
        else if(first && middle) swap(first -> data, middle -> data);
    }
};

int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string s;
        getline(cin, s);

        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);

        Solution ob;
        ob.correctBST(root);
        if (!isBST(root, INT_MIN, INT_MAX)) {
            cout << "0\n";
            continue;
        }

        vector<pair<int, int>> mismatch;
        if (!compare(root, duplicate, mismatch)) {
            cout << "0\n";
            continue;
        }

        if (mismatch.size() != 2 || mismatch[0].first != mismatch[1].second ||
            mismatch[0].second != mismatch[1].first)
            cout << "0\n";
        else
            cout << "1\n";

        cout << "~" << "\n";
    }
}