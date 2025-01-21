// Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.





#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if (!head || k == 1) return head;
    
        stack<Node*> st; 
        Node *curr = head; 
        Node *prev = nullptr; 
      
        while (curr != nullptr) { 
            int count = 0; 
            while (curr != nullptr && count < k) { 
                st.push(curr); 
                curr = curr->next; 
                count++; 
            } 
            
            while (!st.empty()) { 
                if (prev == nullptr) { 
                    prev = st.top(); 
                    head = prev; 
                    st.pop(); 
                } 
                else { 
                    prev->next = st.top(); 
                    prev = prev->next; 
                    st.pop(); 
                } 
            } 
        } 
        prev->next = nullptr;
        return head; 
    }
};

int main(void) {
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
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }
}