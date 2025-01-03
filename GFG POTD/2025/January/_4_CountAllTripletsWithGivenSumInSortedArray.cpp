// Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Brute-focre
        // int n = arr.size(),count = 0;
        // for(int i = 0;i < (n - 2);i++){
        //     for(int j = (i + 1);j < (n - 1);j++){
        //         for(int k = (j + 1);k < n;k++){
        //             if(arr[i] + arr[j] + arr[k] == target) count++;
        //         }
        //     }
        // }
        // return count;
        
        // Optimal SOlution
        int n = arr.size();
        int res = 0;
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum < target) left += 1;
                else if (sum > target) right -= 1;
                else if (sum == target) {
                    int ele1 = arr[left], ele2 = arr[right];
                    int cnt1 = 0, cnt2 = 0;
                    
                    while (left <= right && arr[left] == ele1) {
                        left++;
                        cnt1++;
                    }
    
                    while (left <= right && arr[right] == ele2) {
                        right--;
                        cnt2++;
                    }
                    
                    if (ele1 == ele2) res += (cnt1 * (cnt1 - 1)) / 2;
                    else res += (cnt1 * cnt2);
                }
            }
        }
        return res;
    }
};

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}