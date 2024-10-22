// Given an array arr[] and two integers say, x and y, find the number of sub-arrays in which the number of occurrences of x is equal to the number of occurrences of y.





#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countSubarraysWithEqualXandY(const vector<int>& arr, int x, int y) {
    unordered_map<int, int> prefix_count;
    int count_diff = 0;
    int result = 0;
    
    prefix_count[0] = 1;

    for (int num : arr) {
        if (num == x) count_diff++;
        else if (num == y) count_diff--;

        if (prefix_count.find(count_diff) != prefix_count.end()) result += prefix_count[count_diff];
        prefix_count[count_diff]++;
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 1};
    int x = 1;
    int y = 2;
    
    cout << "Number of subarrays where occurrences of " << x << " and " << y << " are equal: "<< countSubarraysWithEqualXandY(arr, x, y) << endl;
}