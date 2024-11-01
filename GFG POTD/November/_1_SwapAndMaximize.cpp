// Given an array arr[ ] of positive elements. Consider the array as a circular array, meaning the element after the last element is the first element of the array. The task is to find the maximum sum of the absolute differences between consecutive elements with shuffling of array elements allowed i.e. shuffle the array elements and make [a1..an] such order that  |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1| is maximized.






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        int n = arr.size();
        long long sum =0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n/2;i++){
            sum-=2*arr[i];
            sum+=2*arr[n-i-1];
        }
        return sum;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}