// Given a permutation of some of the first natural numbers in an array arr[], determine if the array can be sorted in exactly two swaps. A swap can involve the same pair of indices twice. Return true if it is possible to sort the array with exactly two swaps, otherwise return false.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        int n = arr.size();
        int swapCnt = 0;
        
        for(int i=0;i<n;i++){
            if(arr[i] == i+1) continue;
            while(arr[i] != i+1){
                swap(arr[arr[i] - 1],arr[i]);
                swapCnt++;
            }
        }
        if(swapCnt == 2 || swapCnt == 0) return true;
        return false;
    }
};



int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}