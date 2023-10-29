//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int dp[1001][1001];
    // int fun(int n, int w, int val[], int wt[])
    // {
    //     if(n==0 || w == 0)
    //     {
    //         return 0;
    //     }
    //     if(dp[n][w] != -1)
    //     {
    //         return dp[n][w];
    //     }
    //     if(wt[n-1] <= w)
    //     {
    //         int take = val[n-1] + fun(n,w-wt[n-1],val,wt);
    //         int nottake = fun(n-1,w,val,wt);
            
    //         return dp[n][w] =  max(take,nottake);
    //     }
    //     else
    //     {
    //         return dp[n][w]= fun(n-1,w,val,wt);
    //     }
    // }
    int knapSack(int n, int w, int val[], int wt[])
    {
        // memset(dp,-1,sizeof(dp));
        // return fun(n,w,val,wt);
        
        vector<int> prev(w+1),curr(w+1);
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
                    int take = val[i-1] + curr[j-wt[i-1]];
                    int nottake = prev[j];
                    
                    curr[j] = max(take,nottake);
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

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends