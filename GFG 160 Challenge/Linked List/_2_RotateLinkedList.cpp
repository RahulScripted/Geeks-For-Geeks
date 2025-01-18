// Given the head of a singly linked list, your task is to left rotate the linked list k times.





#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (k == 0 || head == nullptr) return head;

        Node *curr = head;
        int len = 1;
        while (curr->next != nullptr) {
            curr = curr->next;
            len += 1;
        }
        k %= len;
      
        if (k == 0) return head;
        curr->next = head;
        curr = head;
        for (int i = 1; i < k; i++) curr = curr->next;
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}