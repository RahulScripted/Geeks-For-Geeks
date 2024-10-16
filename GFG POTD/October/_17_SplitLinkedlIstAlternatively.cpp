// Given a singly linked list's head. Your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller lists. The sub-lists should be made from alternating elements from the original list.




#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};


class Solution {
  public:
    vector<Node*> alternatingSplitList(Node* head) {
        if (!head) return {NULL, NULL}; 
        Node* headA = NULL; 
        Node* headB = NULL; 
        Node* currentA = NULL;
        Node* currentB = NULL; 
        
        Node* temp = head;
        bool alternate = true;
    
        while (temp) {
            if (alternate) {
                if (!headA) {
                    headA = temp;
                    currentA = headA;
                } 
                else {
                    currentA->next = temp;
                    currentA = currentA->next;
                }
            } 
            else {
                if (!headB) {
                    headB = temp;
                    currentB = headB;
                } 
                else {
                    currentB->next = temp;
                    currentB = currentB->next;
                }
            }
            temp = temp->next;
            alternate = !alternate;
        }
    
        if (currentA) currentA->next = NULL;
        if (currentB) currentB->next = NULL;
    
        return {headA, headB};
    }
};

// Print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create the linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    Solution sol;
    vector<Node*> result = sol.alternatingSplitList(head);
    
    // Print the two sub-lists
    cout << "List A: ";
    printList(result[0]);
    cout << "List B: ";
    printList(result[1]);

    return 0;
}