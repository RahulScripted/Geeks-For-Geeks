// Given a number N, find the first N Fibonacci numbers. The first two number of the series are 1 and 1.




#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<long long> printFibb(int n) {
        vector<long long>ans(n);
        ans[0] = 1;
        ans[1] = 1;
        for(int i = 2;i < n;i++) ans[i] = ans[i - 1] + ans[i - 2];
        return ans;
    }
};

void display(vector<long long>&ans){
    for(int i = 0;i < ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    Solution solve;
    
    // 1st Example
    int n = 6;
    vector<long long> ans = solve.printFibb(n);
    cout<<"For "<<n<<"th the fibonacci series will be : ";
    display(ans);
    
    // 2nd Example
    n = 11;
    ans = solve.printFibb(n);
    cout<<"For "<<n<<" the fibonacci series will be : ";
    display(ans);
}