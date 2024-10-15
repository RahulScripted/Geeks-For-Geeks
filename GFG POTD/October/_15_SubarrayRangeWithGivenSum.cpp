// Given an unsorted array of integers arr[], and a target tar, determine the number of subarrays whose elements sum up to the target value.





#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countSubarraysWithSum(vector<int>& arr, int tar) {
    unordered_map<int, int> prefixSumCount;
    int cumulativeSum = 0;
    int subarrayCount = 0;
    prefixSumCount[0] = 1;

    for (int i = 0; i < arr.size(); i++) {
        cumulativeSum += arr[i];
        
        if (prefixSumCount.find(cumulativeSum - tar) != prefixSumCount.end()) subarrayCount += prefixSumCount[cumulativeSum - tar];

        prefixSumCount[cumulativeSum]++;
    }

    return subarrayCount;
}

int main() {
    vector<int> arr = {1, 1, 1}; 
    int tar = 2;

    cout << "Number of subarrays with sum " << tar << " is: " << countSubarraysWithSum(arr, tar) << endl;
}