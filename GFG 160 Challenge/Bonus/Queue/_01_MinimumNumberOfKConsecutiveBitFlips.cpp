// Given a binary array arr[] and an integer k. A k-bit flip involves selecting a contiguous subarray of length k from arr[] and flipping all its bits - changing every 0 to 1 and every 1 to 0 simultaneously. Your task is to return the minimum number of k-bit flips needed to eliminate all 0s from the array. If it is impossible to achieve, return -1.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int ans = 0, flipped = 0;
        
        for(int i = 0;i < arr.size();i++){
            if(i >= k && arr[i - k] == 2) --flipped;
            if(flipped % 2 == arr[i]){
                if((i + k) > arr.size()) return -1;
                ++ans;
                ++flipped;
                arr[i] = 2;
            }
        }
        
        return ans;
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        cout << ob.kBitFlips(arr, k) << endl;
        cout << "~" << endl;
    }
}