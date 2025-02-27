// Given q queries, You task is to implement the following four functions for a stack:

// push(x) – Insert an integer x onto the stack.
// pop() – Remove the top element from the stack.
// peek() - Return the top element from the stack. If the stack is empty, return -1.
// getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
// Each query can be one of the following:

// 1 x : Push x onto the stack.
// 2 : Pop the top element from the stack.
// 3: Return the top element from the stack. If the stack is empty, return -1.
// 4: Return the minimum element from the stack.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    stack<int> s;
    int minEle;
    
  public:
    Solution() {
        minEle = -1;
    }
    
    void push(int x) {
        if (s.empty()) {
            minEle = x;
            s.push(x);
        }

        else if (x < minEle) {
            s.push(2 * x - minEle);
            minEle = x;
        }

        else s.push(x);
    }
    
    void pop() {
        if (s.empty()) return ;
        
        int top = s.top();
        s.pop();
        
        if (top < minEle) {
            minEle = 2 * minEle - top;
        }
    }
    
    int peek() {
        if (s.empty()) return -1;

        int top = s.top();
        return (minEle > top) ? minEle : top;
    }
    
    int getMin() {
        if (s.empty()) return -1;

        return minEle;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;
        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
}