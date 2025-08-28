// Given two integers a and b that can be positive or negative, find the floor and ceiling of their division in a  vector.



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> floorAndCeil(int a, int b) {
        vector<int> result(2);
        int q = a / b;
        int r = a % b; 
        int floorVal = q;
        int ceilVal = q;

        if (r != 0) {
            if ((a > 0) ^ (b > 0)) {
                floorVal = q - 1;
                ceilVal = q;
            } else {
                floorVal = q;
                ceilVal = q + 1;
            }
        }

        result[0] = floorVal;
        result[1] = ceilVal;
        return result;
    }
};

int main() {
    Solution sol;
    int a, b;
    cout << "Enter two integers (a and b): ";
    cin >> a >> b;

    if (b == 0) {
        cout << "Division by zero is not allowed." << endl;
        return 1;
    }

    vector<int> result = sol.floorAndCeil(a, b);
    cout << "Floor of " << a << "/" << b << " is: " << result[0] << endl;
    cout << "Ceiling of " << a << "/" << b << " is: " << result[1] << endl;
}