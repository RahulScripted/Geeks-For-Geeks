// Given a singly linked list and a key, count the number of occurrences of the given key in the linked list.





#include <bits/stdc++.h>
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
    int count(struct Node* head, int key) {
        int ans = 0;
        struct Node* temp = head;
        while(temp){
            if(temp->data == key) ans++;
            temp = temp -> next;
        }
        return ans;
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
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        int key;
        cin >> key;
        cin.ignore();
        Solution ob;
        cout << ob.count(head, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}