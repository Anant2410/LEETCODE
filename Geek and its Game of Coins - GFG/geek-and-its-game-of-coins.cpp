//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int n, int x, int y, vector<int>& dp)
	{
	    if(n==0) return 0;
	    else if(n==1) return 1;
	    if(dp[n] != -1) return dp[n];
	    int c1=1,c2=1,c3=1;
	    
	    if(n-y >= 0) c3 = solve(n-y,x,y,dp);
	    if(n-x>=0) c2 = solve(n-x,x,y,dp);
	    if(n-1>=0) c1 = solve(n-1,x,y,dp);
	    
	    if(!c1 || !c2 || !c3) return dp[n] = 1;
	    
	    return dp[n] =  0;
	}
	int findWinner(int n, int x, int y)
	{
	    vector<int> dp(n+1, -1);
		return solve(n,x,y,dp);
	}

};
	

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends