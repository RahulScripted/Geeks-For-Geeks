// Given an array arr[]. Push all the zeros of the given array to the right end of the array while maintaining the order of non-zero elements. Do the mentioned change in the array in place.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // Brute-force
        // int n = arr.size();
        // for(int i = 0;i < (n - 1);i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(arr[i]== 0 && arr[j] != 0) swap(arr[i],arr[j]);
        //     }
        // }
        
        int n = arr.size();    
        int i = 0;
        for(int j = 0;j < n;j++){
            if(arr[j] != 0){
                swap(arr[j],arr[i]);
                i++;
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}