// Given a sorted and rotated array arr[] of distinct elements, the task is to find the index of a target key. Return -1 if the key is not found.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int lo = 0, hi = arr.size() - 1;
    
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == key)
                return mid;
            if (arr[mid] >= arr[lo]) {
                if (key >= arr[lo] && key < arr[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
            else {
                if (key > arr[mid] && key <= arr[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1; 
        
        // Linear Search
        // int n = arr.size();
        // for(int i = 0;i < n;i++){
        //     if(arr[i] == key) return i;
        // }
        // return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) arr.push_back(number);
        
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}