// You have a row of flowers, where each flower blooms after a specific day. The array arr represents the blooming schedule: arr[i] is the day the flower at position i will bloom. To create a bouquet, you need to collect k adjacent bloomed flowers. Each flower can only be used in one bouquet. Your goal is to find the minimum number of days required to make exactly m bouquets. If it is not possible to make m bouquets with the given arrangement, return -1.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(vector<int>& arr, int k, int m, int days) {
        int bouquets = 0;
        int cnt = 0;
    
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= days) cnt += 1;
            else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }
    
        bouquets += cnt / k;
        return bouquets >= m;
    }

    int minDaysBloom(int m, int k, vector<int> &arr) {
        int lo = 0;
      	int hi = *max_element(arr.begin(), arr.end());
        int res = -1;
    
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(arr, k, m, mid)) {
                res = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return res;
    }
};

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) arr.push_back(num);
        
        getline(cin, str);
        int m = stoi(str);
        getline(cin, str);
        int k = stoi(str);
        Solution obj;
        cout << obj.minDaysBloom(m, k, arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}