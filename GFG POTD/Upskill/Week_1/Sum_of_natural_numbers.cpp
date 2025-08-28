// Given an integer n your task is to find the sum of first n natural numbers.



#include <iostream>
using namespace std;

class Solution {
public:
    int sumOfNaturalNumbers(int n) {
        return n * (n + 1) / 2;
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

    cout << "Sum of first " << n << " natural numbers is: " << sol.sumOfNaturalNumbers(n) << endl;
}