// Given an array arr[] with repeated elements, the task is to find the maximum distance between two occurrences of an element.




#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> firstOccurrence; 
        int maxDist = 0;
    
        for (int i = 0; i < arr.size(); i++) {
            if (firstOccurrence.find(arr[i]) != firstOccurrence.end()) {
                int dist = i - firstOccurrence[arr[i]];
                maxDist = max(maxDist, dist);
            } 
            else firstOccurrence[arr[i]] = i;
        }
    
        return maxDist;
    }
};

int main(){
    Solution solve;

    // 1st Example
    vector<int>arr = {1, 1, 2, 2, 2, 1};
    cout<<"Maximum distance will be : "<<solve.maxDistance(arr)<<endl;

    // 2nd Example
    arr = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    cout<<"Maximum distance will be : "<<solve.maxDistance(arr)<<endl;
}