// Given a number n, check if it is a perfect number or not. A perfect number is a positive integer that is equal to the sum of its proper positive divisors, excluding the number itself. For example, 6 is a perfect number because its divisors are 1, 2, and 3, and 1 + 2 + 3 = 6.




#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectNumber(int n) {
        if (n <= 1) return false; 
        int sum = 1; 
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) sum += n / i; 
            }
        }
        return sum == n;
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

    if (sol.isPerfectNumber(n)) 
        cout << n << " is a perfect number." << endl;
    else 
        cout << n << " is not a perfect number." << endl;
}