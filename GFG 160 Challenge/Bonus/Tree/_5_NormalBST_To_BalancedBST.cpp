// Given a root of a Binary Search Tree, modify and return the given BST such that it is balanced and has minimum possible height. If there is more than one answer, return any of them.





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

class Solution {
  public:
    void setInorderForm(Node* root, vector<int> &nodes){
        if(root == nullptr) return;
        
        setInorderForm(root -> left,nodes);
        nodes.push_back(root -> data);
        setInorderForm(root -> right,nodes);
    }
    
    Node* buildBST(vector<int> &nodes, int start,int end){
        if(start > end) return nullptr;
        
        int mid = (start + end) / 2;
        Node* root = new Node(nodes[mid]);
        
        root -> left = buildBST(nodes,start,mid - 1);
        root -> right = buildBST(nodes,mid + 1,end);
        return root;
    }
    
    Node* balanceBST(Node* root) {
        vector<int>nodes;
        setInorderForm(root,nodes);
        return buildBST(nodes,0,nodes.size() - 1);
    }
};

Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

void preOrder(Node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    int lDepth = height(node->left);
    int rDepth = height(node->right);
    if (lDepth > rDepth)
        return (lDepth + 1);
    else
        return (rDepth + 1);
}

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

Node* buildBalancedTree(Node* root);

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        struct Node* root = NULL;
        int n, temp;
        string tree;
        getline(cin, tree);
        root = buildTree(tree);
        // cout<<height(root)<<endl;
        Solution obj;
        root = obj.balanceBST(root);
        cout << height(root) << endl;

        cout << "~" << "\n";
    }
}