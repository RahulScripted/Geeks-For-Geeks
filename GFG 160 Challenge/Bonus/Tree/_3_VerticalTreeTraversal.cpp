// Given a root of a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level. If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.





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

void printInorder(Node* root) {
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

class Solution {
  public:
    void DFS(Node *root, int hd, int &mn, unordered_map<int, vector<int>> &mp){
        if(root == NULL) return;
        
        mp[hd].push_back(root -> data);
        mn = min(mn,hd);
        
        DFS(root -> left, hd - 1, mn, mp);
        DFS(root -> right, hd + 1, mn, mp);
    }
    
    vector<vector<int>> verticalOrder(Node *root) {
        unordered_map<int, vector<int>> mp;
        int mn = 0;
        DFS(root,0,mn,mp);
        
        vector<vector<int>>res;
        int hd = mn;
        while(mp.find(hd) != mp.end()){
            res.push_back(mp[hd]);
            hd++;
        }
        
        return res;
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution obj;
        Node* root = buildTree(s);

        vector<vector<int>> res = obj.verticalOrder(root);
        cout << "[ ";
        for (auto& vec : res) {
            cout << "[ ";
            for (int val : vec) {
                cout << val << " ";
            }
            cout << "] ";
        }
        cout << "]" << endl;
        cout << "~" << endl;
    }
    return 0;
}