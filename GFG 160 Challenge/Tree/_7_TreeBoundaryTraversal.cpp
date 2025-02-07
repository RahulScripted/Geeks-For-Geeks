// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

// Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

// Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

// Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.





#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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

Node* newNode(int val) {
    return new Node(val);
}

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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

class Solution {
  public:
    bool isLeaf(Node *node) {
        return node->left == nullptr && node->right == nullptr;
    }
    
    void collectBoundaryLeft(Node *root, vector<int> &res) {
        if (root == nullptr) return;
    
        Node *curr = root;
        while (!isLeaf(curr)) {
            res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void collectLeaves(Node* root, vector<int>& res) {
        Node* current = root;
    
        while (current) {
            if (current->left == nullptr) {
                if (current->right == nullptr) res.push_back(current->data);
                current = current->right;
            } 
            else {
                Node* predecessor = current->left;
                while (predecessor->right && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
    
                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } 
                else {
                    if (predecessor->left == nullptr) res.push_back(predecessor->data);
                    predecessor->right = nullptr;
                    current = current->right;
                }
            }
        }
    }
    
    void collectBoundaryRight(Node *root, vector<int> &res) {
        if (root == nullptr) return;
        Node *curr = root;
        vector<int> temp;
        
        while (!isLeaf(curr)) {
            temp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; --i) res.push_back(temp[i]);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);
    
        collectBoundaryLeft(root->left, res);
        collectLeaves(root, res);
        collectBoundaryRight(root->right, res);
    
        return res;
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res) cout << i << " ";
        cout << endl;

        cout << "~" << "\n";
    }
}