// Given an array, arr[], determine if arr can be split into three consecutive parts such that the sum of each part is equal. If possible, return any index pair(i, j) in an array such that sum(arr[0..i]) = sum(arr[i+1..j]) = sum(arr[j+1..n-1]), otherwise return an array {-1,-1}.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
     vector<int> findSplit(vector<int>& arr) {
        // code here
        int sum=0;
        for(auto it:arr) sum+=it;
        
        int curr=0, first=-1, second=-1;
        
        int ptr=0;
        while(ptr<arr.size()){
            curr+=arr[ptr];
            
            if(curr*3==sum){
                first=ptr;
                ptr++;
                break;
            }
            else if(curr*3>sum) return {-1,-1};
            else ptr++;
        }
        
        curr=0;
        while(ptr<arr.size()){
            curr+=arr[ptr];
            if(curr*3==sum){
                second=ptr;
                ptr++;
                break;
            }
            else if(curr*3 > sum) return {-1,-1};
            else ptr++;
            
        }
        
        curr=0;
        while(ptr<arr.size()){
            curr+=arr[ptr];
            ptr++;
        }
        if(curr*3==sum) return {first, second};
        else return {-1,-1};
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
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1 || result.size() != 2) {
            cout << "false" << endl;
        } else {
            int sum1 = 0, sum2 = 0, sum3 = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (i <= result[0])
                    sum1 += arr[i];

                else if (i <= result[1])
                    sum2 += arr[i];

                else
                    sum3 += arr[i];
            }
            if (sum1 == sum2 && sum2 == sum3) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        cout << "~" << endl;
    }
    return 0;
}