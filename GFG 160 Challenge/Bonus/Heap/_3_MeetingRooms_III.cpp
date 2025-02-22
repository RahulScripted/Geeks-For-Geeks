// You are given an integer n representing the number of rooms numbered from 0 to n - 1. Additionally, you are given a 2D integer array meetings[][] where meetings[i] = [starti, endi] indicates that a meeting is scheduled during the half-closed time interval [starti, endi). All starti values are unique. Meeting Allocation Rules:
    
//     1.  When a meeting starts, assign it to the available room with the smallest number.

//     2.  If no rooms are free, delay the meeting until the earliest room becomes available. The delayed meeting retains its original duration.

//     3.  When a room becomes free, assign it to the delayed meeting with the earliest original start time.

// Determine the room number that hosts the most meetings. If multiple rooms have the same highest number of meetings, return the smallest room number among them.





#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    
    using ll = long long;
    using pii = pair<ll,int>;

    int mostBooked(int n, vector<vector<int>> &meetings) {
        priority_queue<int, vector<int> , greater<int>> idle;
        priority_queue<pii, vector<pii> , greater<pii>> busy;
        
        for(int i = 0;i < n;i++) idle.push(i);
        vector<int>cnt(n);
        sort(meetings.begin(),meetings.end());
        
        for(auto &v : meetings){
            int s = v[0], e = v[1];
            while(!busy.empty() && busy.top().first <= s){
                idle.push(busy.top().second);
                busy.pop();
            }
            
            int i = 0;
            if(!idle.empty()){
                i = idle.top();
                idle.pop();
                busy.push({e,i});
            }
            else{
                auto x = busy.top();
                busy.pop();
                i = x.second;
                busy.push({x.first + e - s, i});
            }
            ++cnt[i];
        }
        
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(cnt[ans] < cnt[i]) ans = i;
        }
        
        return ans;
    }
};

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}