// Given a sorted doubly linked list and an element x, you need to insert the element x into the correct position in the sorted Doubly linked list(DLL).





#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        Node *nouv;

        nouv = new Node;
        nouv->next = nullptr;
        nouv->prev = nullptr;
        nouv->data = x;
    
    
        if (head == NULL)
        {
            return nouv;
        }
    
        if (x < head->data)
        {
            nouv->next = head;
            head->prev = nouv;
            return nouv;
        }
    
        Node *node = head;
    
        for (node = head; node->next != nullptr && node->next->data < x; node = node->next);
    
        if (node->next != nullptr)
        {
            nouv->next = node->next;
            node->next->prev = nouv;
        }
    
        node->next = nouv;
        nouv->prev = node;
    
        return head;
    }
};



int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}