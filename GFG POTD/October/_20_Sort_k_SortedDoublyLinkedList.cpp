// Given a doubly linked list, each node is at most k-indices away from its target position. The problem is to sort the given doubly linked list. The distance can be assumed in either of the directions (left and right).





#include <iostream>
#include <queue>
using namespace std;

class DLLNode{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val){
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        if (!head) return nullptr;

        // Create a min-heap
        priority_queue<int, vector<int>, greater<int>> minHeap;
    
        // Create a new dummy node for the result
        DLLNode* newHead = nullptr;
        DLLNode* current = nullptr;
    
        DLLNode* temp = head;
        
        // Add the first k+1 elements to the heap
        for (int i = 0; temp != nullptr && i <= k; ++i) {
            minHeap.push(temp->data);
            temp = temp->next;
        }
    
        // Now extract elements from the heap and build the sorted list
        while (!minHeap.empty()) {
            if (newHead == nullptr) {
                newHead = new DLLNode(minHeap.top());
                current = newHead;
            } 
            else {
                current->next = new DLLNode(minHeap.top());
                current->next->prev = current;
                current = current->next;
            }
            minHeap.pop();
    
            // Add the next element from the unsorted part of the list to the heap
            if (temp != nullptr) {
                minHeap.push(temp->data);
                temp = temp->next;
            }
        }
    
        return newHead;
    }
};

// Utility function to print the list
void printList(DLLNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function
void append(DLLNode** head_ref, int new_data) {
    DLLNode* new_node = new DLLNode(new_data);
    DLLNode* last = *head_ref;
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr) last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

int main() {
    Solution Solve;

    DLLNode* head = nullptr;
    append(&head, 3);
    append(&head, 6);
    append(&head, 2);
    append(&head, 12);
    append(&head, 56);
    append(&head, 8);

    int k = 2;

    cout << "Original Doubly Linked List: ";
    printList(head);

    head = Solve.sortAKSortedDLL(head, k);

    cout << "Sorted Doubly Linked List: ";
    printList(head);
}