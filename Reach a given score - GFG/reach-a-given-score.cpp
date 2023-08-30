//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function
int dp[1001][1001];
long long int solve(int i, int n, int arr[])
{
    if(i==3) return 0;
    if(n==0) return 1;
    if(dp[i][n] != -1) return dp[i][n] ;
    
    if(arr[i] <= n)
    {
        int take = solve(i,n-arr[i],arr);
        int nottake = solve(i+1,n,arr);
        
        return dp[i][n] =  take + nottake;
    }
    return dp[i][n] =  solve(i+1,n,arr);
}
long long int count(long long int n)
{
    int arr[3] = {3,5,10};
    memset(dp, -1, sizeof(dp));
    return solve(0,n,arr);
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends