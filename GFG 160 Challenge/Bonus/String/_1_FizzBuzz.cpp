// Fizz Buzz Problem involves that given an integer n, for every integer 0 < i <= n, the task is to output,

// 1.  "FizzBuzz" if i is divisible by 3 and 5,
// 2.  "Fizz" if i is divisible by 3,
// 3.  "Buzz" if i is divisible by 5
// 4.  "i" as a string, if none of the conditions are true.

// Return an array of strings.





#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Solution {
  public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans;
        for(int i = 1;i <= n;i++){
            if(i % 3 == 0 && i % 5 == 0) ans.push_back("FizzBuzz");
            else if(i % 3 == 0) ans.push_back("Fizz");
            else if(i % 5 == 0) ans.push_back("Buzz");
            else ans.push_back(to_string(i));
        }
        return ans;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<string> res = obj.fizzBuzz(n);

        Array::print(res);
        cout << "~" << endl;
    }
}