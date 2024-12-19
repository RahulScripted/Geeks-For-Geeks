// You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// 1.  Each student receives atleast one book.

// 2.  Each student is assigned a contiguous sequence of books.

// 3.  No book is assigned to more than one student.

// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(vector<int> &arr, int k, int pageLimit) {
    int cnt = 1;
    int pageSum = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(pageSum + arr[i] > pageLimit) {
            cnt++;
            pageSum = arr[i];
        }
        else {
            pageSum += arr[i];
        }
    }
    return (cnt <= k);
}

    int findPages(vector<int> &arr, int k) {
        if(k > arr.size())
        return -1;
        
    int lo = *max_element(arr.begin(), arr.end());
    int hi = accumulate(arr.begin(), arr.end(), 0);
    int res = -1;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        
        if(check(arr, k, mid)){
            res = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~" << "\n";
    }
    return 0;
}