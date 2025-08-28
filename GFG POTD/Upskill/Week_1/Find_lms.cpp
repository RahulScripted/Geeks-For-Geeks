// Given 2 positive integers a and b your task is to find the lcm of a and b.



#include <iostream>
using namespace std; 

class Solution {
public:
    int lcm(int a, int b) {
        return (a / __gcd(a, b)) * b;
    }
};

int main() {
    Solution sol;
    int a, b;
    cout << "Enter two positive integers: ";
    cin >> a >> b;

    if (a <= 0 || b <= 0) {
        cout << "Please enter positive integers." << endl;
        return 1;
    }

    cout << "LCM of " << a << " and " << b << " is: " << sol.lcm(a, b) << endl;
}