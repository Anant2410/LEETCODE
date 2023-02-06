//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod = 1e9+7;
    int fun(int n, vector<int>& dp)
    {
        if(n==0 || n==1) return 1;
        if(dp[n] != -1) return dp[n];
        int left = fun(n-1,dp);
        int right = fun(n-2,dp);
        
        
        return dp[n] = (left + right) % mod;
    }
    int countWays(int n)
    {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends