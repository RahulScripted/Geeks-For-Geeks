// Geek has successfully developed an effective vaccine for the Coronavirus and aims to ensure that every house in Geek Land has access to it. The houses in Geek Land are structured as a binary tree, where each node represents a house, and the edges denote direct connections between houses. Each house that receives a vaccine kit can provide coverage to:

// 1.  Itself

// 2.  Its direct parent house (if it exists)

// 3.  Its immediate child houses (if any exist)

// Your task is to determine the minimum number of houses that must be supplied with a vaccine kit to ensure that every house is covered.







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
    int minVaccine(Node* root, int &res) {
        if(!root) return 1;
        
        int l = minVaccine(root -> left, res);
        int r = minVaccine(root -> right, res);
        
        if(l == 0 || r == 0){
            res++;
            return 2;
        }
        
        if(l == 2 || r == 2) return 1;
        return 0;
    }
    
    int supplyVaccine(Node* root) {
        int res = 0;
        if(minVaccine(root,res) == 0) res++;
        return res;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.supplyVaccine(root) << "\n";

        cout << "~" << "\n";
    }
    return 0;
}