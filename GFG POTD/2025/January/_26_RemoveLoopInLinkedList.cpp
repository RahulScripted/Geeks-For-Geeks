// Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked list is connected back to a node in the same list. The task is to remove the loop from the linked list (if it exists).





#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position) {
    if (position == 0) return;

    Node* walk = head;
    for (int i = 1; i < position; i++) walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head) {
    if (!head) return false;
    Node* fast = head->next;
    Node* slow = head;

    while (fast != slow) {
        if (!fast || !fast->next) return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}

int length(Node* head) {
    int ret = 0;
    while (head) {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node* head, unordered_map<Node*, int>& myMap) {

    while (head) {
        if (myMap.find(head) == myMap.end())
            return true;
        if (myMap[head] != (head->data))
            return true;

        head = head->next;
    }
}

class Solution {
  public:
    void removeLoop(Node* head) {
        if (head == nullptr || head->next ==nullptr) return;
        Node *slow = head, *fast = head;
        slow = slow->next;
        fast = fast->next->next;
    
        // Search for loop
        while (fast && fast->next) {
            if (slow == fast) break;
            slow = slow->next;
            fast = fast->next->next;
        }
    
        // If loop exists
        if (slow == fast) {
            slow = head;
            if (slow == fast){
                while (fast->next != slow) fast = fast->next;
            }
            else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            fast->next = nullptr;
        }
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

        unordered_map<Node*, int> myMap;
        int n, num;
        n = arr.size();

        Node *head, *tail;
        num = arr[0];
        head = tail = new Node(num);

        myMap[head] = num;

        for (int i = 1; i < n; i++) {
            num = arr[i];
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail] = num;
        }

        int pos;
        cin >> pos;
        cin.ignore();
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);
        if (isLoop(head) || length(head) != n || notOriginal(head, myMap)) cout << "false\n";
        else cout << "true\n";
        cout << "~" << endl;
    }
}