//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // int solve(int w, int wt[], int val[], int n)
    // {
    //   if(n==0 || w==0) return 0;
       
    //   if(wt[n-1] <= w)
    //   {
    //       int take = val[n-1] + knapSack(w-wt[n-1],wt,val,n-1);
    //       int nottake = knapSack(w,wt,val,n-1);
           
    //       return max(take,nottake);
    //   }
    //   else
    //   {
    //       return knapSack(w,wt,val,n-1);
    //   }
    // }
    
    //memoization
    // int dp[1001][1001];
    // int solve(int w, int wt[], int val[], int n)
    // {
    //   if(n==0 || w==0) return 0;
    //   if(dp[n][w] != -1) return dp[n][w];
    //   if(wt[n-1] <= w)
    //   {
    //       int take = val[n-1] + knapSack(w-wt[n-1],wt,val,n-1);
    //       int nottake = knapSack(w,wt,val,n-1);
           
    //       return dp[n][w] =  max(take,nottake);
    //   }
    //   else
    //   {
    //       return dp[n][w] = knapSack(w,wt,val,n-1);
    //   }
    // }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       //return solve(w,wt,val,n);
       //memset(dp,-1,sizeof(dp));
       vector<int> prev(w+1), curr(w+1);
       for(int i=0;i<=n;i++)
       {
           curr[0] = 0;
       }
       for(int j=1;j<=w;j++)
       {
           curr[j] = 0;
       }
       
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=w;j++)
           {
               if(wt[i-1] <= j)
               {
                   curr[j] = max(val[i-1] + prev[j-wt[i-1]], prev[j]);
               }
               else
               {
                   curr[j] = prev[j];
               }
           }
           prev = curr;
       }
       return prev[w];
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends