// Given an array arr[] of integers where each element represents a pile of bananas, and Koko has k hours to finish all the piles, find the minimum number of bananas (s) Koko must eat per hour to finish all the bananas within k hours. Each hour, Koko chooses a pile and eats s bananas from it. If the pile has fewer than s bananas, she consumes the entire pile for that hour and won't eat any other banana during that hour.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(vector<int>& arr, int mid, int k) {
        int hours = 0;
        for (int i = 0; i < arr.size(); i++) {
            hours += arr[i] / mid;
            if (arr[i] % mid != 0) hours++;
        }
        return hours <= k;
    }
    
    int kokoEat(vector<int>& arr, int k) {
        int lo = 1;
        int hi = *max_element(arr.begin(), arr.end());
        int res = hi;
    
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(arr, mid, k) == true) {
                hi = mid - 1;
                res = mid;
            }
            else lo = mid + 1;
        }
        return res;
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
        while (ss >> number) arr.push_back(number);
        
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;

        cout << ob.kokoEat(arr, k);
        cout << "\n";
    }
}