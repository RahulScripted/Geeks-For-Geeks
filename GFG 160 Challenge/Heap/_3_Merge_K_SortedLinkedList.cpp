// Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, then return the head of the merged linked list.





#include <bits/stdc++.h>
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
    cout << endl;
}

class Solution {
  public:
    Node* mergeTwo(Node* head1,Node* head2){
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        
        while(head1 != nullptr && head2 != nullptr){
            if(head1 -> data <= head2 -> data){
                curr -> next = head1;
                head1 = head1 -> next;
            }
            else{
                curr -> next = head2;
                head2 = head2 -> next;
            }
            curr = curr -> next;
        }
        
        if(head1 != nullptr) curr -> next = head1;
        else curr -> next = head2;
        return dummy -> next;
    }
    
    Node* mergeListRec(int i,int j, vector<Node*> &arr){
        if(i == j) return arr[i];
        int mid = i + (j - i) / 2;
        Node* head1 = mergeListRec(i,mid,arr);
        Node* head2 = mergeListRec((mid + 1),j,arr);
        Node* head = mergeTwo(head1,head2);
        return head;
    }
    
    Node* mergeKLists(vector<Node*>& arr) {
        if(arr.size() == 0) return nullptr;
        return mergeListRec(0,arr.size() - 1,arr);
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
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}