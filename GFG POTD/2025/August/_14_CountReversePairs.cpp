// You are given an array arr[] of positive integers, find the count of reverse pairs. A pair of indices (i, j) is said to be a reverse pair if both the following conditions are met:

// 1.  0 ≤ i < j < arr.size()
// 2.  arr[i] > 2 * arr[j]





#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countRevPairs(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
  private:
    int mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;
        
        int mid = (low + high) / 2;
        int count = mergeSort(arr, low, mid) + mergeSort(arr, mid + 1, high);
        
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)arr[i] > 2LL * arr[j]) j++;
            count += (j - (mid + 1));
        }
        
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) temp.push_back(arr[left++]);
            else temp.push_back(arr[right++]);
        }
        
        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        
        return count;
    }
};

int main (){
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    Solution sol;
    int result = sol.countRevPairs(arr);
    
    cout << "Total reverse pair count: " << result << endl;
    return 0;
}