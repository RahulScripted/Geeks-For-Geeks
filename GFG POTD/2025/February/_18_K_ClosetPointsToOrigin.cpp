// Given an array of points where each point is represented as points[i] = [xi, yi] on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance, defined as: sqrt( (x2 - x1)^2 + (y2 - y1)^2 )





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int squaredDis(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (int i=0;i<points.size();i++) {
            int dist = squaredDis(points[i]);
    
            if (maxHeap.size() < k) {
                maxHeap.push({dist, points[i]});
            } 
            else {
                if (dist < maxHeap.top().first) {
                    maxHeap.pop();
                    maxHeap.push({dist, points[i]});
                }
            }
        }
    
        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }
}