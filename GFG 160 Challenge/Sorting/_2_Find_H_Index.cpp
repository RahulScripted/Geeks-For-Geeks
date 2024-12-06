// Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n + 1);
    
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) freq[n] += 1;
            else freq[citations[i]] += 1;
        }
    
        int idx = n;
        int s = freq[n]; 
        while (s < idx) {
            idx--;
            s += freq[idx];
        }
        return idx;
    }
};

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) arr.push_back(number);

        Solution ob;
        int result = ob.hIndex(arr);
        cout << result << endl;
        cout << "~" << endl;
    }
    return 0;
}