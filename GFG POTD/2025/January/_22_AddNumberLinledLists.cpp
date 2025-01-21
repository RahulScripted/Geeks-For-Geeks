// Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.





#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution {
  public:
    Node *reverse(Node *head) {
        Node *prev = nullptr, *curr = head, *next;
    
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    Node *trimLeadingZeros(Node* head) {
        while(head->next != nullptr && head->data == 0) head = head->next;
        return head;
    }
    
    int countNodes(Node* head) {
        int len = 0;
        Node* curr = head;
      
        while(curr != nullptr) {
            len += 1;
            curr = curr->next;
        }
        return len;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = trimLeadingZeros(num1);
        num2 = trimLeadingZeros(num2);
      
        int len1 = countNodes(num1);
        int len2 = countNodes(num2);
        if(len1 < len2) return addTwoLists(num2, num1);
    
        int carry = 0;
        num1 = reverse(num1);
        num2 = reverse(num2);
        Node *res = num1;
        while (num2 != nullptr || carry != 0) {
            num1->data += carry;
            if (num2 != nullptr) {
                num1->data += num2->data;
                num2 = num2->next;
            }
          
            carry = num1->data / 10;
            num1->data = num1->data % 10;
            if(num1->next == nullptr && carry != 0) num1->next = new Node(0);
            num1 = num1->next;
        }
        return reverse(res);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
}