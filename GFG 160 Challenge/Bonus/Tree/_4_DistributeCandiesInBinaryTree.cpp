// You are given a binary tree with n nodes, where each node contains a certain number of candies, and the total number of candies across all nodes is n. In one move, we can select two adjacent nodes and transfer one candy from one node to the other. The transfer can occur between a parent and child in either direction. The task is to determine the minimum number of moves required to ensure that every node in the tree has exactly one candy.






#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
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
    int distributeCandyRec(Node* root, int &ans){
        if(root == nullptr) return 0;
        
        int l = distributeCandyRec(root -> left,ans);
        int r = distributeCandyRec(root -> right,ans);
        
        ans += abs(l) + abs(r);
        return root -> data + l + (r - 1);
    }
    
    int distributeCandy(Node* root) {
        int ans = 0;
        distributeCandyRec(root,ans);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string str;
        getline(cin, str);

        Node* root = buildTree(str);
        Solution ob;
        cout << ob.distributeCandy(root) << "\n";
        cout << "~" << "\n";
    }
    return 0;
}