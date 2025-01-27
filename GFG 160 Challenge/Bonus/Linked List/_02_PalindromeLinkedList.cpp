// Given a head singly linked list of positive integers. The task is to check if the given linked list is palindrome or not.





#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* reverse (Node* head){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next;
        
        while(curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isIdentical(Node* n1, Node* n2){
        for(;n1 && n2 ;n1 = n1 -> next, n2 = n2 -> next){
            if(n1 -> data != n2 -> data) return 0;
        }
        return 1;
    }
    
    bool isPalindrome(Node *head) {
        if(!head || !head -> next) return true;
        
        Node* slow = head;
        Node* fast = head;
        while(fast -> next && fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        Node* head2 = reverse(slow -> next);
        slow -> next = nullptr;
        
        bool ret = isIdentical(head,head2);
        head2 = reverse(head2);
        slow -> next = head2;
        
        return ret;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head)) cout << "true" << endl;
        else cout << "false" << endl;

        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
        cout << "~\n";
    }
    return 0;
}