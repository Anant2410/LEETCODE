//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
// 	int solve(int wt[], int cost[], int n, int w, vector<vector<int>>& dp)
// 	{
// 	    if(w==0) return 0;
// 	    if(n==0) return INT_MAX;
// 	    if(dp[n][w] != -1) return dp[n][w];
// 	    if(wt[n-1] <= w && cost[n-1] != -1)
// 	    {
// 	        int take = cost[n-1] + solve(wt,cost,n,w-wt[n-1],dp);
// 	        int nottake = solve(wt,cost,n-1,w,dp);
	        
// 	        return dp[n][w] =  min(take,nottake);
// 	    }
// 	    return dp[n][w] = solve(wt,cost,n-1,w,dp);
// 	}
	int minimumCost(int cost[], int n, int w) 
	{
		int INF = 999999999;
	    vector<int> val, wt; 
	    int size = 0; 
	    for (int i=0; i<n; i++) 
	    { 
	        if (cost[i]!= -1) 
	        { 
	            val.push_back(cost[i]); 
	            wt.push_back(i+1); 
	            size++; 
	        } 
	    } 
	  
	    n = size; 
	    int dp[n+1][w+1]; 
	    for (int i=0; i<=w; i++) 
	        dp[0][i] = INF; 
	    for (int i=1; i<=n; i++) 
	        dp[i][0] = 0; 
	        
	    for (int i=1; i<=n; i++) 
	    { 
	        for (int j=1; j<=w; j++) 
	        { 
	            if (wt[i-1] > j) 
	                dp[i][j] = dp[i-1][j]; 
	            else
	                dp[i][j] = min(dp[i-1][j],dp[i][j-wt[i-1]] + val[i-1]); 
	        } 
	    } 
	    return (dp[n][w]==INF)? -1: dp[n][w]; 
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends