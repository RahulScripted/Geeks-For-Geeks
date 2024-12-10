// Given an array of integers arr[] representing non-negative integers, arrange them so that after concatenating all of them in order, it results in the largest possible number. Since the result may be very large, return it as a string.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool myCompare(const string& s1, const string& s2) {
        return (s1 + s2) > (s2 + s1);
    }
    
    string findLargest(vector<int> &arr) {
        vector<string> numbers;
        for(int ele: arr) {
            numbers.push_back(to_string(ele));
        }
        sort(numbers.begin(), numbers.end(), myCompare);
        if (numbers[0] == "0") return "0";
        
        string res = "";
        for (string& num : numbers) res.append(num);
        return res;
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
        string ans = ob.findLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}