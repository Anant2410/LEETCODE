//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// int solve(int idx, int buy, int k, vector<int>& price, vector<vector<vector<int>>>& dp)
// {
//     if(idx>=price.size() || k<=0)
//     {
//         return 0;
//     }
    
//     if(dp[idx][buy][k] != -1) return dp[idx][buy][k];
//     if(buy)
//     {
//         int take = -price[idx] + solve(idx+1,!buy,k,price,dp);
//         int nottake = solve(idx+1,buy,k,price,dp);
        
//          return dp[idx][buy][k] = max(take,nottake);
//     }
//     else
//     {
//         int take = price[idx] + solve(idx+1,!buy,k-1,price,dp);
//         int nottake = solve(idx+1,buy,k,price,dp);
        
//         return dp[idx][buy][k] = max(take,nottake);
//     }
// }

int maxProfit(vector<int>&prices)
{
    vector<vector<vector<int>>>dp(prices.size()+1,
            vector<vector<int>>(2, vector<int>(3,0)));
        
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int k=1;k<=2;k++)
                {
                    if(buy)
                    {
                        int take = -prices[i] + dp[i+1][!buy][k];
                        int nottake = dp[i+1][buy][k];

                        dp[i][buy][k] = max(take,nottake);
                    }
                    else
                    {
                        int take = prices[i] + dp[i+1][!buy][k-1];
                        int nottake = dp[i+1][buy][k];

                        dp[i][buy][k] = max(take,nottake);
                    }
                }
            }
        }
        return dp[0][1][2];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends