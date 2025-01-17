// Given an integer array arr[], where each arr[i] denotes the trajectory of the graph over the plane; i.e. arr[i]>0 means graph going above its current position by arr[i] value and arr[i]<0 means graph going down by arr[i] value. If initial position of the graph is at origin, determines the number of times graph crosses or touches the X-axis.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int touchedXaxis(vector<int>& arr) {
        int curr = 0,res = 0;
        int n = arr.size();
        
        for(int i = 0;i < n;i++){
            int prev = curr;
            curr += arr[i];
            
            if((prev < 0 && curr >= 0) || (prev > 0 && curr <= 0)) res++;
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        int num;
        stringstream ss(line);
        vector<int> arr;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.touchedXaxis(arr);
        cout << ans << endl;
        cout << "~\n";
    }
}