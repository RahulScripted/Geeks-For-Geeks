// Given a sorted array arr[] and a number target, the task is to find the lower bound of the target in this given array. The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int lo = 0, hi = arr.size() - 1; 
        int res = arr.size();
      	
      	while(lo <= hi) {
          	int mid = lo + (hi - lo)/2;
          	if(arr[mid] >= target) {
                res = mid;
                hi = mid - 1;
            }
          	else lo = mid + 1;
        }
      	return res;	
    }
};

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {
        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) arr.push_back(number);
        
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) crr.push_back(number);
        
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.lowerBound(arr, d);
        cout << ans << endl;

        cout << "~" << "\n";
    }
    return 0;
}