//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int dp[1001][1001];
    int lcs(string s, string t, int n, int m)
    {
        if(n==0 || m==0)
        {
            return 0;
        }
        if(dp[n][m] != -1) return dp[n][m] ;
        if(s[n-1] == t[m-1])
        {
            return dp[n][m] = 1 + lcs(s,t,n-1,m-1);
        }
        return dp[n][m] = max(lcs(s,t,n-1,m), lcs(s,t,n,m-1));
    }
    int longestPalinSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        memset(dp, -1, sizeof(dp));
        return lcs(s,t,s.size(),t.size());
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends