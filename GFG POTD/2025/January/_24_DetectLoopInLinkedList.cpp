// You are given the head of a singly linked list. Your task is to determine if the linked list contains a loop. A loop exists in a linked list if the next pointer of the last node points to any other node in the list (including itself), rather than being null.





#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void loopHere(Node* head, Node* tail, int position) {
    if (position == 0) return;
    Node* walk = head;
    for (int i = 1; i < position; i++) walk = walk->next;
    tail->next = walk;
}

class Solution {
  public:
    bool detectLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(slow && fast && fast-> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return true;
        }
        return false;
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

        int pos;
        cin >> pos;
        cin.ignore();

        Node* head = nullptr;
        Node* tail = nullptr;

        if (!arr.empty()) {
            head = new Node(arr[0]);
            tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
            loopHere(head, tail, pos);
        }

        Solution ob;
        if (ob.detectLoop(head)) cout << "true\n";
        else cout << "false\n";

        unordered_set<Node*> visited;
        Node* current = head;
        while (current && visited.find(current) == visited.end()) {
            visited.insert(current);
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
}