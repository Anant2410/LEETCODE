//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // int dp[101][101];
    // int solve(string s, string t, int n, int m)
    // {
    //     if(n==0)
    //     {
    //         return m;
    //     }
    //     if(m == 0)
    //     {
    //         return n;
    //     }
    //     if(dp[n][m] != -1) return dp[n][m];
    //     if(s[n-1] == t[m-1])
    //     {
    //         return dp[n][m] =  solve(s,t,n-1,m-1);
    //     }
    //     else
    //     {
    //         int ins = solve(s,t,n,m-1);
    //         int del = solve(s,t,n-1,m);
    //         int rep = solve(s,t,n-1,m-1);
            
    //         return dp[n][m] = 1 + min({ins,del,rep});
    //     }
    // }
    int solve(string s, string t)
    {
        int n = s.size(), m = t.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = i;
        }
        for(int j=1;j<=m;j++)
        {
            dp[0][j] = j;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    int ins = dp[i][j-1];
                    int del = dp[i-1][j];
                    int rep = dp[i-1][j-1];
                    
                    dp[i][j] = 1 + min({ins,del,rep});
                }
            }
        }
        return dp[n][m];
    }
    int editDistance(string s, string t) {
        // int n = s.size(), m = t.size();
        // memset(dp,-1, sizeof(dp));
        // return solve(s,t,n,m);
        return solve(s,t);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends