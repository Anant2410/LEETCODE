//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int dp[21][21][21];
int solve(string a, string b, string c, int n1, int n2, int n3)
{
    if(n1==0 || n2 == 0 || n3 == 0)
    {
        return 0;
    }
    if(dp[n1][n2][n3] != -1) return dp[n1][n2][n3];
    if(a[n1-1] == b[n2-1] && b[n2-1] == c[n3-1])
    {
        return dp[n1][n2][n3] =  1 + solve(a,b,c,n1-1,n2-1,n3-1);
    }
    return dp[n1][n2][n3] = max({solve(a,b,c,n1-1,n2,n3), solve(a,b,c,n1,n2-1,n3), 
    solve(a,b,c,n1,n2,n3-1)});
}

int LCSof3 (string a, string b, string c, int n1, int n2, int n3)
{
    memset(dp, -1, sizeof(dp));
    return solve(a,b,c,n1,n2,n3);
}