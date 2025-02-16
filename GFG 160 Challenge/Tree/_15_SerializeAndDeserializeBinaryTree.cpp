// Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

// serialize() : stores the tree into an array a and returns the array.
// deSerialize() : deserializes the array to the tree and returns the root of the tree.






#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
    void serializePreOrder(Node *root, vector<int> &arr) {
        if(root == nullptr){
            arr.push_back(-1);
            return;
        }    
        
        arr.push_back(root -> data);
        serializePreOrder(root -> left,arr);
        serializePreOrder(root -> right, arr);
    }
    
    vector<int> serialize(Node *root) {
        vector<int>arr;
        serializePreOrder(root,arr);
        return arr;
    }

    Node *deSerializePreOrder(int &i, vector<int> &arr){
        if(arr[i] == -1){
            i++;
            return nullptr;
        }
        
        Node* root = new Node(arr[i]);
        i++;
        
        root -> left = deSerializePreOrder(i,arr);
        root -> right = deSerializePreOrder(i,arr);
        return root;
    }
    
    Node *deSerialize(vector<int> &arr) {
        int i = 0;
        return deSerializePreOrder(i,arr);
    }
};

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node *node) {
    if (node == NULL) return;
    _deleteTree(node->left);
    _deleteTree(node->right);
    delete node;
}

void deleteTree(Node **node_ref) {
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);

        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node *temp = root;
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);

        cout << "\n";
        cout << "~" << "\n";
    }
}