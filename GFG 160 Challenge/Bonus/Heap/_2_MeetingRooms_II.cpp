// Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. Return the minimum number of rooms required to attend all meetings.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        if(n == 0) return 0;
        
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        int rooms = 0;
        for(int i = 0;i < n;i++){
            while(!minHeap.empty() && minHeap.top() <= start[i]){
                minHeap.pop();
            }
            
            minHeap.push(end[i]);
            rooms = max(rooms, (int)minHeap.size());
        }
        return rooms;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.minMeetingRooms(arr, brr);
        cout << res << endl;
        cout << "~" << endl;
    }
}