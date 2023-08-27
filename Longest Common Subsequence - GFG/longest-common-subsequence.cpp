//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    // int solverec(int n, int m, string s, string t)
    // {
    //     if(n==0 || m==0)
    //     {
    //         return 0;
    //     }
    //     if(n==0 && m==0)
    //     {
    //         return 1;
    //     }
    //     if(s[n-1] == t[m-1])
    //     {
    //         return 1 + solverec(n-1,m-1,s,t);
    //     }
    //     else return max(solverec(n-1,m,s,t), solverec(n,m-1,s,t));
    // }
    int solve(int n, int m, string s, string t)
    {
        vector<int>prev(m+1,0),curr(m+1,0);
        // for(int i=0;i<=n;i++)
        // {
        //     dp[i][0] = 0;
        // }
        // for(int j=1;j<=m;j++)
        // {
        //     dp[0][j] = 0;
        // }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                }
                else
                {
                    curr[j] = max(prev[j] , curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
    int lcs(int n, int m, string s1, string s2)
    {
       return solve(n,m,s1,s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends