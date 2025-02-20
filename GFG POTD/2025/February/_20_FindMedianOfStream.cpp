// Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read. There are two cases for median on the basis of data set size.

// 1. If the data set has an odd number then the middle one will be consider as median.
// 2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> leftMaxHeap;
        priority_queue<int, vector<int>, greater<int>> rightMinHeap;
        
        vector<double> res;
        for (int i = 0; i < arr.size(); i++) {
            leftMaxHeap.push(arr[i]);
            int temp = leftMaxHeap.top();
            leftMaxHeap.pop();
            rightMinHeap.push(temp);
          
            if (rightMinHeap.size() > leftMaxHeap.size()) {
                temp = rightMinHeap.top();
                rightMinHeap.pop();
                leftMaxHeap.push(temp);
            }
            
            double median;
            if (leftMaxHeap.size() != rightMinHeap.size())
                median = leftMaxHeap.top();
            else
                median = (double)(leftMaxHeap.top() + rightMinHeap.top()) / 2;
            
            res.push_back(median);
        }
        
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);

        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }

        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}