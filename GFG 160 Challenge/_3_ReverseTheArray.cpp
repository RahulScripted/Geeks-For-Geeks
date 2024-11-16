// You are given an array of integers arr[]. Your task is to reverse the given array.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = (n - 1);
        while(i < j){
            swap(arr[i],arr[j]);
            i++;
            j--;
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
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}