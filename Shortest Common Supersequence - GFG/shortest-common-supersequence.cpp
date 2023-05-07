//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int lcs(string x, string y, int n, int m, vector<vector<int>>& dp)
    {
        if(n==0 || m== 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(x[n-1] == y[m-1])
        {
            return dp[n][m] =  1 + lcs(x,y,n-1,m-1,dp);
        }
        else
        {
            return dp[n][m] =  max(lcs(x,y,n-1,m,dp), lcs(x,y,n,m-1,dp));
        }
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans = lcs(X,Y,m,n,dp);
        return (m + n - ans);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends