// Given q queries, You task is to implement the following three functions for a stack:

// 1.   push(x) – Insert an integer x onto the stack.
// 2.   pop() – Remove the top element from the stack.
// 3.   peek() - Return the top element from the stack. If the stack is empty, return -1.
// 4.   getMax() – Retrieve the maximum element from the stack in O(1) time. If the stack is empty, return -1.
// Each query can be one of the following:

// 1 x : Push x onto the stack.
// 2 : Pop the top element from the stack.
// 3: Return the top element from the stack. If the stack is empty, return -1.
// 4: Return the maximum element from the stack.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    stack<int>st;
    int maxEle;
    
  public:
    Solution() {
        maxEle = -1;
    }

    // Add an element to the top of Stack
    void push(int x) {
        if(st.empty()){
            maxEle = x;
            st.push(x);
        }
        else if(x > maxEle){
            st.push(2 * x - maxEle);
            maxEle = x;
        }
        else st.push(x);
    }

    // Remove the top element from the Stack
    void pop() {
        if(st.empty()) return;
        int top = st.top();
        st.pop();
        if(top > maxEle) maxEle = (2 * maxEle - top);
    }

    // Returns top element of the Stack
    int peek() {
        if(st.empty()) return -1;
        int top = st.top();
        return (maxEle < top) ? maxEle : top;
    }

    // Finds minimum element of Stack
    int getMax() {
        if(st.empty()) return -1;
        return maxEle;
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
                cout << ob.getMax() << " ";
            }
        }
        cout << endl;
    }
}