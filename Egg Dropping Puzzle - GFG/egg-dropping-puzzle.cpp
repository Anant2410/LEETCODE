//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    // recurrence relation
    // int solve(int e, int f)
    // {
    //     if(f==0 || f==1) return f;
    //     if(e==1) return f;
        
    //     int ans = INT_MAX;
        
    //     for(int k=1;k<=f;k++)
    //     {
    //         int temp = 1 + max(solve(e-1,k-1), solve(e,f-k));
            
    //         ans = min(ans,temp);
    //     }
    //     return ans;
    // }
    
    //memoization
    //int dp[201][201];
    // int solve(int e, int f)
    // {
    //     if(f==0 || f==1)
    //     {
    //         return f;
    //     }
    //     if(e==1)
    //     {
    //         return f;
    //     }
    //     if(dp[e][f] != -1)
    //     {
    //         return dp[e][f];
    //     }
        
    //     int ans = INT_MAX;
    //     for(int k=1;k<=f;k++)
    //     {
    //         int temp = 1 + max(solve(e-1,k-1), solve(e,f-k));
            
    //         ans = min(ans,temp);
    //     }
    //     return dp[e][f] = ans;
    // }
    
    //better optimization
    int dp[201][201];
    int solve(int e, int f)
    {
        if(e==1) return f;
        if(f==0 || f==1) return f;
        if(dp[e][f] != -1) return dp[e][f];
        int ans = INT_MAX;
        
        for(int k=1;k<=f;k++)
        {
            int left,right;
            if(dp[e-1][k-1] != -1)
            {
                left = dp[e-1][k-1];
            }
            else
            {
                left = solve(e-1,k-1);
                dp[e-1][k-1] = left;
            }
            
            if(dp[e][f-k] != -1)
            {
                right = dp[e][f-k];
            }
            else
            {
                right = solve(e,f-k);
                dp[e][f-k] = right;
            }
            int temp = 1 + max(left,right);
            
            ans = min(ans,temp);
        }
        
        return dp[e][f] = ans;
    }
    int eggDrop(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(n,k); 
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