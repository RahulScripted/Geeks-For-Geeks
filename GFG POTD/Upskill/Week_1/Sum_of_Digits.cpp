// Given an positive integer n your task is to find the sum of digits of n.


#include <iostream>
using namespace std;

class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
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

    cout << "Sum of digits of " << n << " is: " << sol.sumOfDigits(n) << endl;
}