// Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // 1 Pass
        int n = arr.size();
        int low = 0,high = (n - 1),mid = 0;
        while(mid <= high){
            if(arr[mid] == 0){
                swap(arr[mid],arr[low]);
                low++;
                mid++;
            }
            else if(arr[mid] == 2){
                swap(arr[mid],arr[high]);
                high--;
            }
            else mid++;
        }
        // 2 pass
        // int n = arr.size();
        // int count0 = 0,count1 = 0,count2 = 0;
        // for(int i = 0;i < n;i++){
        //     if(arr[i] == 0) count0++;
        //     else if(arr[i] == 1) count1++;
        //     else count2++;
        // }
        // for(int i = 0;i < n;i++){
        //     if(i < count0) arr[i] = 0;
        //     else if(i < (count0 + count1)) arr[i] = 1;
        //     else arr[i] = 2;
        // }
        
        // In built
        // sort(arr.begin(),arr.end());
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) a.push_back(num);

        Solution ob;
        ob.sort012(a);
        int n = a.size();
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}