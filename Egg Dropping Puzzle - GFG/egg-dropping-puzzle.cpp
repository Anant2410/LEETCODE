//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int fun(int eggs, int floor, vector<vector<int>>& dp)
    {
        if(floor==0 || floor == 1) return floor;
        if(eggs==1) return floor;
        if(dp[eggs][floor] != -1) return dp[eggs][floor];
        int ans = INT_MAX;
        for(int k=1;k<=floor;k++)
        {
            int temp = 1 + max(fun(eggs-1,k-1,dp), fun(eggs, floor-k,dp));
            ans = min(ans,temp);
        }
        return dp[eggs][floor] =  ans;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return fun(n,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends