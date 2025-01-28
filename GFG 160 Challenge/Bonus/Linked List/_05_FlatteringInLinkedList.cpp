// Given a linked list containing n head nodes where every node in the linked list contains two pointers:
// 1. next points to the next node in the list.
// 2. bottom pointer to a sub-linked list where the current node is the head.

// Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data.Your task is to flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.






#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}

class Solution {
  public:
    Node *flatten(Node *root) {
        vector<int>values;
        while(root != nullptr){
            values.push_back(root->data);
            Node* temp = root->bottom;
            while(temp != nullptr){
                values.push_back(temp->data);
                temp = temp -> bottom;
            }
            root = root->next;
        }
        sort(values.begin(),values.end());
        Node* tail = nullptr;
        Node* head = nullptr;
        for(int i = 0;i < values.size();i++){
            Node* newNode = new Node(values[i]);
            if(head == nullptr) head = newNode;
            else tail->bottom = newNode;
            tail = newNode;
        }
        return head;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }
}