// Given an integer n find all its divisors in ascending order and return it in a vector.



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> allDivisors(int n) {
        vector<int> divisors;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) divisors.push_back(i);
        }
        return divisors;
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

    vector<int> divisors = sol.allDivisors(n);
    cout << "Divisors of " << n << " are: ";
    for (int d : divisors) {
        cout << d << " ";
    }
    cout << endl;
}