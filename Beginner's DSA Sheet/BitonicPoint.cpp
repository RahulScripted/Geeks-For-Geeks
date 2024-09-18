// Given an array arr of n elements that is first strictly increasing and then maybe strictly decreasing, find the maximum element in the array.



#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    int maxi = arr[n - 1];
	    for(int i = 1;i < n - 1;i++){
	        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
	            maxi = arr[i];
	            break;
	        }
	    }
	    return maxi;
	}
};

int main(){
    Solution solve;
    int n = 9;
    int arr[] = {1,15,25,45,42,21,17,12,11};
    cout<<"Maximum element is : "<<solve.findMaximum(arr,n)<<endl;
}