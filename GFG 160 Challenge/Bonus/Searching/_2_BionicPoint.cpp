// Given an array of integers arr[] that is first strictly increasing and then maybe strictly decreasing, find the bitonic point, that is the maximum element in the array. Bitonic Point is a point before which elements are strictly increasing and after which elements are strictly decreasing.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int n = arr.size();
        int l=0;
	    int r=n-1;
	    while(l<=r){
	        int mid=l+(r-l)/2;
	        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return arr[mid];
	        else if(arr[mid]<arr[mid-1] && arr[mid+1]<arr[mid]) r=mid-1;
	        else if(arr[mid]>arr[mid-1] && arr[mid+1]>arr[mid]) l=mid+1;
	    }
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int value;

        string line;
        getline(cin, line);
        stringstream ss(line);

        while (ss >> value) arr.push_back(value);

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~" << "\n";
    }
    return 0;
}