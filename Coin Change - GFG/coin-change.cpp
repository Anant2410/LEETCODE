//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // int dp[1001][1001];
    // long long int solve(int coins[], int n,int sum)
    // {
    //     if(n==0)
    //     {
    //         return 0;
    //     }
    //     if(sum==0)
    //     {
    //         return 1;
    //     }
    //     if(dp[n][sum] != -1)
    //     {
    //         return dp[n][sum];
    //     }
    //     if(coins[n-1] <= sum)
    //     {
    //         int t = count(coins,n,sum-coins[n-1]);
    //         int nt = count(coins,n-1,sum);
            
    //         return dp[n][sum] =  t + nt;
    //     }
    //     else
    //     {
    //         return dp[n][sum] =  count(coins,n-1,sum);
    //     }
    // }
    long long int count(int coins[], int n, int sum) 
    {
        //memset(dp,-1,sizeof(dp));
        //return solve(coins,n,sum);
        long long int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                {
                    dp[i][j] = 0;
                }
                if(j==0)
                {
                    dp[i][j] = 1;
                }
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(coins[i-1] <= j)
                {
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends