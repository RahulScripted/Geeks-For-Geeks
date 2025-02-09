// Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).






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

class Solution {
  public:
    int countPathsUtil(Node* node, int k, int currSum, unordered_map<int, int>& prefSums) {
        if (node == nullptr) return 0;
      
        int pathCount = 0;
        currSum += node->data;
        if (currSum == k) pathCount++;
          
        pathCount += prefSums[currSum - k];
        prefSums[currSum]++;
        pathCount += countPathsUtil(node->left, k, currSum, prefSums);
        pathCount += countPathsUtil(node->right, k, currSum, prefSums);
        prefSums[currSum]--;
     
        return pathCount;
    }
    int sumK(Node *root, int k) {
        unordered_map<int, int> prefSums;
        return countPathsUtil(root, k, 0, prefSums);
    }
};

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);

    while (t--) {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);

        string key;
        getline(cin, key);
        int k = stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
        cout << "~\n";
    }
    return 0;
}