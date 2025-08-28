// Given a positive integer num, return the square root of num. If num is not a perfect square, return the floor of the square root of num.



#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int num) {
        if (num < 2) return num;
        int left = 1, right = num / 2, ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= num / mid) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (num < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    int result = sol.mySqrt(num);
    cout << "The square root of " << num << " is " << result << "." << endl;
} 