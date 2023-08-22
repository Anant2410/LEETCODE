//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    // int solve(int n, int w, int price[], int length[])
    // {
    //     if(n==0 || w==0)
    //     {
    //         return 0;
    //     }
    //     if(length[n-1] <= w)
    //     {
    //         return max(price[n-1] + solve(n,w-length[n-1],price,length),
    //         solve(n-1,w,price,length));
    //     }
    //     return solve(n-1,w,price,length);
    // }
    int solve(int n, int w, int price[], int length[])
    {
        int dp[n+1][w+1];
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 0;
        }
        for(int j=1;j<=w;j++)
        {
            dp[0][j] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(length[i-1] <= j)
                {
                    dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
    int cutRod(int price[], int n) {
        int length[n];
        for(int i=0;i<n;i++)
        {
            length[i] = i+1;
        }
        return solve(n,n,price,length);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends