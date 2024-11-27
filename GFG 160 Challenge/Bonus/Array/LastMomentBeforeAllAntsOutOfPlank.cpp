// We have a wooden plank of the length n units. Some ants are walking on the plank, each ant moves with a speed of 1 unit per second. Some of the ants move to the left, the other move to the right. When two ants moving in two different directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time. When an ant reaches one end of the plank at a time t, it falls out of the plank immediately. Given an integer n and two integer arrays left[] and right[], the positions of the ants moving to the left and the right, return the moment when the last ant(s) fall out of the plank.





#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ltime=-1,rtime=-1;
        
        if(left.size()>0) ltime=*max_element(left.begin(),left.end());
        if(right.size()>0){
            rtime=*min_element(right.begin(),right.end());
            rtime=n-rtime;
        }
        
        return max(rtime,ltime);
    }
};

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        int n;
        cin >> n;
        cin.ignore();

        string input;
        vector<int> left;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            left.push_back(number);
        }

        string input2;
        vector<int> right;

        // Read the array from input line
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            right.push_back(number2);
        }

        // Solution instance to invoke the function
        Solution ob;
        int lastMoment = ob.getLastMoment(n, left, right);
        cout << lastMoment << endl;
        cout << "~" << endl;
    }
    return 0;
}