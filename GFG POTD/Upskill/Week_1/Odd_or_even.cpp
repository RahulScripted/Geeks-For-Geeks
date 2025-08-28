// Given an positive integer n wheteher it's even or odd. Return true if even else return false.



#include <iostream>
using namespace std;

class Solution {
public:
    bool isEven(int n) {
        return n % 2 == 0;
    }
}; 

int main() {
    Solution sol;
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    if (sol.isEven(n)) cout << n << " is even." << endl;
    else cout << n << " is odd." << endl;
}