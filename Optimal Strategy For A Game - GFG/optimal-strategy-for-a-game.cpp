//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(int arr[], int i, int j, vector<vector<long long>>& dp)
    {
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        long long left = arr[i] + min(solve(arr,i+2,j,dp), solve(arr,i+1,j-1,dp));
        long long right = arr[j] + min(solve(arr,i+1,j-1,dp), solve(arr,i,j-2,dp));
        
        return dp[i][j] =  max(left,right);
    }
    long long maximumAmount(int arr[], int n){
        vector<vector<long long>> dp(n+1, vector<long long>(n+1, -1));
        return solve(arr,0,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends