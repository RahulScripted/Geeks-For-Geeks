// Design and implement an LFU (Least Frequently Used) cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types GET(x) and PUT(x, y). 

// The LRU cache should support the following operations:

// 1.   LFUCache(cap): initializes the cache with a given capacity.

// 2.   get(key): returns the value associated with the key if it exists; otherwise, returns -1.

// 3.   put(key, value): inserts or updates the key with value. If the cache has reached its capacity, the least frequently used (LFU) key should be removed. If there is a tie between keys with the same frequency, the least recently used (LRU) key among them should be removed.





#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key,value;
    int timeStamp,cnt;
    Node* next;
    Node(int key,int val, int timeStamp){
        this->key=key;  
        this->value=val;
        this->cnt=1;
        this->timeStamp=timeStamp;
        this->next=nullptr;
    }
};

class LFUCache {
  public:
  int capacity;
  int curSize;
  int curTime;
  Node* head;
    LFUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
        curTime = 0;
        head = new Node(-1,-1,-1);
    }

    int get(int key) {
        curTime++;
        Node* temp = head;
        while(temp->next != nullptr){
            if(temp->next->key == key){
                temp->next->cnt++;
                temp->next->timeStamp = curTime;
                return temp->next->value;
            }
            temp = temp -> next;
        }
        return -1;
    }

    void put(int key, int value) {
        curTime++;
        if(capacity == 0) return;
        Node* temp = head;
        while(temp -> next != nullptr){
            if(temp->next->key == key){
                temp->next->value = value;
                temp->next->cnt++;
                temp->next->timeStamp = curTime;
                return;
            }
            temp = temp->next;
        }
        if(curSize < capacity){
            curSize++;
            Node* temp = head;
            while(temp->next != nullptr) temp = temp->next;
            temp->next = new Node(key,value,curTime);
            return;
        }
        else{
            int minCnt = INT_MAX, minTime = INT_MAX;
            Node* minNode = nullptr;
            Node* temp = head;
            while(temp->next != nullptr){
                if(temp->next->cnt < minCnt || (temp->next->cnt == minCnt && temp->next->timeStamp < minTime)){
                    minCnt = temp->next->cnt;
                    minTime = temp->next->timeStamp;
                    minNode = temp;
                }
                temp = temp->next;
            }
            Node* delNode = minNode->next;
            minNode->next = minNode->next->next;
            delete delNode;
            temp = head;
            while(temp->next != nullptr) temp = temp->next;
            temp->next = new Node(key, value, curTime);
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int capacity;
        cin >> capacity;
        LFUCache *cache = new LFUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
}