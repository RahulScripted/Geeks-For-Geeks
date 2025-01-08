// Given an integer array arr[]. Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. 





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int res = 0;
        sort(arr.begin(), arr.end());
        
        for (int i = 2; i < arr.size(); ++i) {
            int left = 0, right = i - 1; 
            while (left < right) {
                if (arr[left] + arr[right] > arr[i]) {
                    res += right - left; 
                    right--; 
                } 
                else left++;
            }
        }
    
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }
    return 0;
}